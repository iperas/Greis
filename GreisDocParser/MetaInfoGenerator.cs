using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text.RegularExpressions;

namespace GreisDocParser
{
    public class MetaInfoGenerator
    {
        private static readonly List<string> _messagesWithFillBehavior = new List<string>()
                                                                             {
                                                                                 "SI", "AN", "NN", "EL", "AZ", "RC", "rc", "1R", "1r", "CC", "cc", 
                                                                                 "PC", "pc", "CP", "cp", "DC", "1d", "EC", "CE", "FC", "TC", "SS", 
                                                                                 "ID", "GD", "gd", "LD", "lD", "ED", "rT", "RE", "ER", "==", ">>", 
                                                                                 "PM", "cd"
                                                                             };

        private static readonly List<string> _almanacsAndEphemerisMessages = new List<string>() { "GA", "EA", "NA", "WA", "GE", "NE", "WE", "EN" };

        private static readonly List<string> _messagesWithUniformFillBehavior = new List<string>() { "gC" };
        // rM - page 340, smartass rules (dynamic customTypes SvData2 & SlotRec also here)
        // LH - page 346, smartass rules

        //private static readonly List<string> _structsWithFixedSize = new List<string>() { "SvData0", "SvData1", "ClkOffs" };

        public static MetaInfo FromUserManual(string rawText)
        {
            return parseText(rawText);
        }

        private static MetaInfo parseText(string text)
        {
            // Retrieving standard messages
            var metaInfo = new MetaInfo();
            var matches = Regex.Matches(text,
                                        @"^(?<title>\[(?<code>[\x30-\x7E]{2})\](,\s*\[(?<code>[\x30-\x7E]{2})\])*
                                                    ([^\r\n\d]|(?!\d+[\r\n])\d)+)
                                                    ((?![\r\n]\s*\[[\x30-\x7E]{2}\]).)*?
                                                    struct\s+(?<name>[^\s{]+)\s*\{(?<size>[^\}]+)\}\s*\{(?<content>[^}]+)\}",
                                        RegexOptions.IgnoreCase | RegexOptions.Multiline | RegexOptions.Singleline |
                                        RegexOptions.ExplicitCapture | RegexOptions.IgnorePatternWhitespace);
            foreach (Match m in matches)
            {
                // Parsing message meta-info
                var msg = new StandardMessage();
                msg.Title = m.Groups["title"].Value;
                foreach (Capture capture in m.Groups["code"].Captures)
                {
                    msg.Codes.Add(capture.Value);
                }
                msg.Name = m.Groups["name"].Value;
                msg.Size = parseSize(msg.Codes[0], m.Groups["size"].Value);
                msg.Type = getMessageType(msg.Codes[0]);

                // Parsing variables
                var content = m.Groups["content"].Value;
                msg.Variables.AddRange(parseContent(content));
                // Checksum or crc16?
                if (msg.Variables.Count > 0)
                {
                    var lastVar = msg.Variables.Last();
                    if (lastVar.Name == "cs" && lastVar.Comment.Trim() == "Checksum formatted as hexadecimal")
                    {
                        msg.Validation = ValidationType.ChecksumAsHexAscii;
                    }
                    else
                    if (lastVar.Name == "cs")
                    {
                        msg.Validation = ValidationType.Checksum;
                    } else
                    if (lastVar.Name == "crc16" && lastVar.Comment.Contains("16-bit CRC"))
                    {
                        msg.Validation = ValidationType.Crc16;
                    } else
                    {
                        
                    }
                }

                metaInfo.StandardMessages.Add(msg);
            }
            // retrieving custom types
            var customTypes = new List<CustomType>();
            matches = Regex.Matches(text, @"^struct\s+(?<name>[^\s{]+)?\s*(\{(?<size>[^\}]+)\})?\s*\{(?<content>[^}]+)\}",
                                    RegexOptions.IgnoreCase | RegexOptions.Multiline | RegexOptions.Singleline |
                                    RegexOptions.ExplicitCapture | RegexOptions.IgnorePatternWhitespace);
            foreach (Match m in matches)
            {
                var ct = new CustomType();
                ct.Name = m.Groups["name"].Value;
                ct.Size = parseSize(ct.Name, m.Groups["size"].Value);
                var content = m.Groups["content"].Value;
                ct.Variables.AddRange(parseContent(content));
                customTypes.Add(ct);
            }
            // correcting CustomType names with duplicates (with updating usages)
            customTypes = customTypes.Where(t => !metaInfo.StandardMessages.Any(m => m.Name == t.Name)).ToList();
            var customTypesByName = customTypes.GroupBy(t => t.Name).ToList();
            var varsWithCustomTypes = metaInfo.StandardMessages.SelectMany(m => m.Variables).
                Where(v => !Enum.GetNames(typeof(GreisTypes)).Contains(v.GreisType)).GroupBy(v => v.GreisType).ToList();
            foreach (var usagesGroup in varsWithCustomTypes)
            {
                var usages = usagesGroup.ToList();
                var typeName = usagesGroup.Key;
                var definitions = customTypesByName.FirstOrDefault(g => g.Key == typeName);
                if (definitions == null)
                {
                    continue;
                }
                if (usages.Count > 1 && usages.Count == definitions.Count())
                {
                    var defList = definitions.ToList();
                    for (int i = 0; i < usages.Count; i++)
                    {
                        usages[i].GreisType = typeName + i;
                        defList[i].Name = typeName + i;
                        if (defList[i].Size == (int) SizeSpecialValue.Fill)
                        {
                            defList[i].Size = parseSize(defList[i].Name, "");
                        }
                    }
                }
            }
            metaInfo.CustomTypes = customTypes.Where(t => !String.IsNullOrEmpty(t.Name)).ToList();
            // correcting StandardMessage names with duplicates
            foreach (var grp in metaInfo.StandardMessages.GroupBy(msg => msg.Name).Where(grp => grp.Count() > 1))
            {
                int index = 0;
                foreach (var stdMsg in grp)
                {
                    stdMsg.Name += index++;
                }
            }

            resolveFixedSizeFields(metaInfo);
            addGpsAlmsAndEphemerisTypes(metaInfo);
            fixDocumentationBugs(metaInfo);

            return metaInfo;
        }

        private static void fixDocumentationBugs(MetaInfo metaInfo)
        {
            // fixed in 03-2012 version
            //var waasEphemeris = (CustomType) metaInfo.StandardMessages.First(m => m.Name == "WAASEhemeris");
            //waasEphemeris.Size = 71;
        }

        private static void addGpsAlmsAndEphemerisTypes(MetaInfo metaInfo)
        {
            addCustomTypeFromStdMessage(metaInfo, "GPSAlm", true);
            addCustomTypeFromStdMessage(metaInfo, "GPSEphemeris", true);
            addCustomTypeFromStdMessage(metaInfo, "IonoParams", false);
            addCustomTypeFromStdMessage(metaInfo, "GpsNavData", false);
            addCustomTypeFromStdMessage(metaInfo, "GpsRawNavData", false);
        }

        private static void addCustomTypeFromStdMessage(MetaInfo metaInfo, string msgName, bool removeCs)
        {
            var stdMsg = (CustomType) metaInfo.StandardMessages.First(m => m.Name == msgName);

            CustomType customType;
            if (removeCs)
            {
                customType = new CustomType
                {
                    Name = stdMsg.Name,
                    Size = stdMsg.Size - 1,
                    Variables = stdMsg.Variables.Where(v => v.Name != "cs").ToList()
                };
            } else
            {
                customType = new CustomType
                {
                    Name = stdMsg.Name,
                    Size = stdMsg.Size,
                    Variables = stdMsg.Variables.ToList()
                };
            }
            metaInfo.CustomTypes.Add(customType);

            stdMsg.Name += "0";
            customType.Name += "1";

            foreach (var variable in metaInfo.StandardMessages.SelectMany(m => m.Variables).
                Where(v => v.GreisType == msgName))
            {
                variable.GreisType += "1";
            }
        }

        private static void resolveFixedSizeFields(MetaInfo metaInfo)
        {
            var types = metaInfo.CustomTypes.Concat(metaInfo.StandardMessages).ToList();

            // size cache
            Dictionary<string, int> nameToSizeCache = new Dictionary<string, int>();
            foreach (var simpleType in Enum.GetNames(typeof (GreisTypes)))
            {
                nameToSizeCache[simpleType] = int.Parse(simpleType[1].ToString(CultureInfo.InvariantCulture));
            }
            foreach (var ct in types.Where(ct => ct.Size >= 0))
            {
                nameToSizeCache[ct.Name] = ct.Size;
            }

            int resolvingPointsCount = int.MaxValue;
            int resolvingPointsCountPrevIter = int.MaxValue - 1;
            while (resolvingPointsCountPrevIter != resolvingPointsCount && resolvingPointsCount > 0)
            {
                resolvingPointsCountPrevIter = resolvingPointsCount;

                var resolvingPoints = types.Where(ct => ct.Size < 0 && !ct.ContainsOptionalDataBlock && 
                    ct.Variables.All(v => nameToSizeCache.ContainsKey(v.GreisType) && v.SizeOfDimensions.All(s => s >= 0))).ToList();

                resolvingPointsCount = resolvingPoints.Count;

                foreach (var customType in resolvingPoints)
                {
                    int size = customType.Variables.Sum(v => nameToSizeCache[v.GreisType] * 
                        (v.IsScalar ? 1 : v.SizeOfDimensions.Aggregate(1, (s1, s2) => s1 * s2)));
                    customType.Size = size;
                    nameToSizeCache[customType.Name] = size;
                }
            }

            foreach (var ct in types.Where(ct => ct.ContainsOptionalDataBlock))
            {
                ct.Size = (int) SizeSpecialValue.FixedWithOptionalDataBlock;
            }
        }

        private static MessageTypes getMessageType(string code)
        {
            if (_almanacsAndEphemerisMessages.Contains(code))
            {
                return MessageTypes.AlmanacsAndEphemeris;
            }
            return MessageTypes.Unknown;
        }

        private static int parseSize(string codeOrStructName, string sizeStr)
        {
            int size;
            if (int.TryParse(sizeStr, out size))
            {
                return size;
            }
            if (_messagesWithFillBehavior.Contains(codeOrStructName) ||
                _messagesWithUniformFillBehavior.Contains(codeOrStructName))
            {
                return (int) SizeSpecialValue.Fill;
            }
            return (int) SizeSpecialValue.Dynamic;
        }

        private static List<Variable> parseContent(string content)
        {
            var finalVariables = new List<Variable>();
            var lines = content.Split(new[] { '\r', '\n' }, StringSplitOptions.RemoveEmptyEntries);

            List<Variable> lastAddedVariables = null; // For comments-only lines
            foreach (var line in lines.Where(s => Regex.IsMatch(s, "(;|//)")))
            {
                // extract comments and code
                var lm = Regex.Match(line, @"^[\s!]*((?<code>((?!;?\s*//).)*?);)?\s*(//\s*(?<comment>.*)\s*)?$",
                                     RegexOptions.IgnoreCase |
                                     RegexOptions.Singleline |
                                     RegexOptions.ExplicitCapture |
                                     RegexOptions.IgnorePatternWhitespace);
                if (!lm.Success)
                {
                    throw new Exception(String.Format("Invalid content string '{0}' (lm).", line));
                }
                var code = lm.Groups["code"].Value;
                var comment = lm.Groups["comment"].Value;
                if (String.IsNullOrWhiteSpace(code) && !String.IsNullOrWhiteSpace(comment))
                {
                    if (lastAddedVariables != null)
                    {
                        foreach (var lastAddedVariable in lastAddedVariables)
                        {
                            if (String.IsNullOrWhiteSpace(lastAddedVariable.Comment))
                            {
                                lastAddedVariable.Comment = comment;
                            }
                            else
                            {
                                lastAddedVariable.Comment = lastAddedVariable.Comment + Environment.NewLine +
                                                            comment;
                            }
                        }
                    }
                    continue;
                }
                // Parsing code
                // variable pattern does not covers all cases. For example empty SIZE property in multidimension arrays causes a bug.
                const string variablePattern =
                    @"(?<name>[a-z][a-z0-9]*)
                    (?<sizePresented>\[(?<size>[^\]]*)\])*
                    (\s*=\s*([""\u201c\u201d](?<value>[^""\u201c\u201d]+)[""\u201c\u201d]|(?<value>[^\s,]+)))?";
                var cm = Regex.Match(code,
                                     String.Format(@"^(?<type>[a-z][a-z0-9]*)\s+(?<var>{0})(\s*,\s*(?<var>{0}))*$",
                                                   variablePattern),
                                     RegexOptions.IgnoreCase |
                                     RegexOptions.Singleline |
                                     RegexOptions.ExplicitCapture |
                                     RegexOptions.IgnorePatternWhitespace);
                if (!cm.Success)
                {
                    throw new Exception(String.Format("Invalid content string '{0}' (cm).", line));
                }
                var variables = new List<Variable>();
                var vartype = cm.Groups["type"].Value;
                foreach (Capture capture in cm.Groups["var"].Captures)
                {
                    // Parsing variables names
                    var varname = capture.Value;
                    var vm = Regex.Match(varname, String.Format(@"^{0}$", variablePattern),
                                         RegexOptions.IgnoreCase |
                                         RegexOptions.Singleline |
                                         RegexOptions.ExplicitCapture |
                                         RegexOptions.IgnorePatternWhitespace);
                    if (!vm.Success)
                    {
                        throw new Exception(String.Format("Invalid content string '{0}' (vm).", line));
                    }
                    var variable = new Variable();
                    variable.GreisType = vartype;
                    variable.Name = vm.Groups["name"].Value;
                    variable.RequiredValue = vm.Groups["value"].Value;
                    variable.Comment = comment;

                    var dimensionsCount = vm.Groups["sizePresented"].Captures.Count;
                    if (dimensionsCount > 0)
                    {
                        for (int i = 0; i < dimensionsCount; i++)
                        {
                            var sizeStr = vm.Groups["size"].Captures[i].Value;
                            //var sizePresented = !string.IsNullOrEmpty(vm.Groups["sizePresented"].Captures[i].Value);
                            int varsize;
                            /*if (!sizePresented)
                            {
                                varsize = 1;
                            }
                            else*/ if (!Int32.TryParse(sizeStr, out varsize))
                            {
                                varsize = (int) SizeSpecialValue.Fill;
                            }
                            variable.SizeOfDimensions.Add(varsize);
                        }
                    }
                    else
                    {
                        //variable.SizeOfDimensions.Add(1);
                    }

                    variables.Add(variable);
                }
                lastAddedVariables = variables;
                finalVariables.AddRange(variables);
            }
            return finalVariables;
        }
    }
}