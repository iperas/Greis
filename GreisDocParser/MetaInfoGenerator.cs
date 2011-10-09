using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

namespace GreisDocParser
{
    public class MetaInfoGenerator
    {
        private List<string> _messagesWithFillBehavior = new List<string>() { "SI", "AN", "NN", "EL", "AZ", "RC", "rc", "1R", "1r", "CC", "cc", "PC", "pc", "CP", "cp", "DC", "1d", "EC", "CE", "FC", "TC", "SS", "ID", "GD", "LD", "ED", "rT", "RE", "ER", "EV", ">>", "PM" };
        private List<string> _messagesWithUniformFillBehavior = new List<string>() { "gC" };
        // rM - page 340, smartass rules
        // LH - page 346, smartass rules

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
                int size;
                if (Int32.TryParse(m.Groups["size"].Value, out size))
                {
                    msg.Size = size;
                }

                // Parsing variables
                var content = m.Groups["content"].Value;
                msg.Variables.AddRange(parseContent(content));
                // Checksum or crc16?
                if (msg.Variables.Count > 0)
                {
                    var lastVar = msg.Variables.Last();
                    if (lastVar.Name == "cs" && lastVar.Comment.Trim() == "Checksum")
                    {
                        msg.Validation = ValidationTypes.Checksum;
                    }
                    if (lastVar.Name == "cs" && lastVar.Comment.Trim() == "Checksum formatted as hexadecimal")
                    {
                        msg.Validation = ValidationTypes.ChecksumAsHexAscii;
                    }
                    if (lastVar.Name == "crc16" && lastVar.Comment.Contains("16-bit CRC"))
                    {
                        msg.Validation = ValidationTypes.Crc16;
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
                int size;
                if (Int32.TryParse(m.Groups["size"].Value, out size))
                {
                    ct.Size = size;
                }
                var content = m.Groups["content"].Value;
                ct.Variables.AddRange(parseContent(content));
                customTypes.Add(ct);
            }
            // correcting CustomType names for duplicates (with updating usages)
            customTypes = customTypes.Where(t => !metaInfo.StandardMessages.Any(m => m.Name == t.Name)).ToList();
            var customTypesByName = customTypes.GroupBy(t => t.Name).ToList();
            var varsWithCustomTypes = metaInfo.StandardMessages.SelectMany(m => m.Variables).
                Where(v => !Enum.GetNames(typeof(GreisTypes)).Contains(v.Type)).GroupBy(v => v.Type).ToList();
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
                        usages[i].Type = typeName + i;
                        defList[i].Name = typeName + i;
                    }
                }
            }
            metaInfo.CustomTypes = customTypes.Where(t => !String.IsNullOrEmpty(t.Name)).ToList();
            return metaInfo;
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
                    variable.Type = vartype;
                    variable.Name = vm.Groups["name"].Value;
                    variable.RequiredValue = vm.Groups["value"].Value;
                    variable.Comment = comment;

                    var dimensionsCount = vm.Groups["sizePresented"].Captures.Count;
                    if (dimensionsCount > 0)
                    {
                        for (int i = 0; i < dimensionsCount; i++)
                        {
                            var sizeStr = vm.Groups["size"].Captures[i].Value;
                            var sizePresented = !String.IsNullOrEmpty(vm.Groups["sizePresented"].Captures[i].Value);
                            int varsize;
                            if (!sizePresented)
                            {
                                varsize = 1;
                            }
                            else if (!Int32.TryParse(sizeStr, out varsize))
                            {
                                varsize = (int) SizeSpecialValues.Dynamic;
                            }
                            variable.Dimensions.Add(varsize);
                        }
                    }
                    else
                    {
                        variable.Dimensions.Add(1);
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