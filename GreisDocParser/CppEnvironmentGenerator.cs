using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace GreisDocParser
{
    public class CppEnvironmentGenerator
    {
        private const string StubToken = "// ${stub}";
        private const string IncludesStubToken = "// ${includes}";
        private const string ClassFieldsStubToken = "// ${ClassFieldsStub}";
        private const string ClassFieldsAccessorsStubToken = "// ${ClassFieldsAccessorsStub}";
        private const string ClassNameStubToken = "${ClassName}";
        private const string ToByteArrayStubToken = "// ${ToByteArrayStub}";
        private const string DeserializationConstructorStubToken = "// ${DeserializationConstructorStub}";
        private const string StdMessagesDir = "StdMessages";
        private const string CustomTypesDir = "CustomTypes";
        private readonly MetaInfo _metaInfo;
        private readonly string _cppEnvTemplatesDir;
        private string _outDir;
        private readonly CustomTypeNameCustomizer _normalizedStdMessagesNamesProvider;
        private readonly CustomTypeNameCustomizer _normalizedCustomTypeNamesProvider;
        private readonly string[] _simpleTypes = Enum.GetNames(typeof (GreisTypes));

        public CppEnvironmentGenerator(MetaInfo metaInfo, string cppEnvTemplatesDir)
        {
            _metaInfo = metaInfo;
            _cppEnvTemplatesDir = cppEnvTemplatesDir;

            _normalizedStdMessagesNamesProvider = new CustomTypeNameCustomizer(_metaInfo.StandardMessages,
                s => CustomTypeNameCustomizer.NormalizeNameToLowerCamelCase(s.Name));
            _normalizedCustomTypeNamesProvider = new CustomTypeNameCustomizer(_metaInfo.CustomTypes, null,
                s => CustomTypeNameCustomizer.NormalizeNameToLowerCamelCase(s.Name));
        }

        public void Generate(string outDir)
        {
            _outDir = outDir;

            generateEMessageId();
            generateStdMessageGeneratedMembers();
            generateStdMessageFactory();
            generateStdMessages();
            generateCustomTypes();
        }

        private class CustomTypeStubsContent
        {
            public string Includes { get; set; }
            public string ClassFields { get; set; }
            public string ClassFieldsAccessors { get; set; }
            public string ToByteArrayCode { get; set; }
            public string DeserializationConstructorCode { get; set; }
        }

        private void generateStdMessages()
        {
            var concreteStdMsgHTemplatePath = Path.Combine(_cppEnvTemplatesDir, "ConcreteStdMessage.template.h");
            var concreteStdMsgCppTemplatePath = Path.Combine(_cppEnvTemplatesDir, "ConcreteStdMessage.template.cpp");
            var templateStrH = File.ReadAllText(concreteStdMsgHTemplatePath, Encoding.Default);
            var templateStrCpp = File.ReadAllText(concreteStdMsgCppTemplatePath, Encoding.Default);

            var fieldsListIntendation = Regex.Match(templateStrH, @"([ \t]*)" + Regex.Escape(ClassFieldsStubToken)).
                Groups[1].Value;
            var fieldsAccessorsListIntendation = Regex.Match(templateStrH, @"([ \t]*)" +
                Regex.Escape(ClassFieldsAccessorsStubToken)).Groups[1].Value;
            var codeIntendation = Regex.Match(templateStrCpp, @"([ \t]*)" +
                Regex.Escape(DeserializationConstructorStubToken)).Groups[1].Value;

            foreach (var msg in _metaInfo.StandardMessages)
            {
                var className = _normalizedStdMessagesNamesProvider.GetName(msg) + "StdMessage";

                var content = generateCustomTypeStubsContent(msg, fieldsAccessorsListIntendation,
                    fieldsListIntendation, codeIntendation);

                // ClassNameStubToken
                var fileHContent = templateStrH.Replace(IncludesStubToken, content.Includes).
                    Replace(ClassFieldsStubToken, content.ClassFields).
                    Replace(ClassFieldsAccessorsStubToken, content.ClassFieldsAccessors).
                    Replace(ClassNameStubToken, className);
                var fileCppContent = templateStrCpp.Replace(ClassNameStubToken, className).
                    Replace(ToByteArrayStubToken, content.ToByteArrayCode).
                    Replace(DeserializationConstructorStubToken, content.DeserializationConstructorCode);

                // Write
                File.WriteAllText(Path.Combine(_outDir, StdMessagesDir, className + ".h"), fileHContent, 
                                  Encoding.Default);
                File.WriteAllText(Path.Combine(_outDir, StdMessagesDir, className + ".cpp"), fileCppContent, 
                                  Encoding.Default);
            }
        }

        private void generateCustomTypes()
        {
            var concreteCtHTemplatePath = Path.Combine(_cppEnvTemplatesDir, "ConcreteCustomType.template.h");
            var concreteCtCppTemplatePath = Path.Combine(_cppEnvTemplatesDir, "ConcreteCustomType.template.cpp");
            var templateStrH = File.ReadAllText(concreteCtHTemplatePath, Encoding.Default);
            var templateStrCpp = File.ReadAllText(concreteCtCppTemplatePath, Encoding.Default);

            var fieldsListIntendation = Regex.Match(templateStrH, @"([ \t]*)" + Regex.Escape(ClassFieldsStubToken)).
                Groups[1].Value;
            var fieldsAccessorsListIntendation = Regex.Match(templateStrH, @"([ \t]*)" +
                Regex.Escape(ClassFieldsAccessorsStubToken)).Groups[1].Value;
            var codeIntendation = Regex.Match(templateStrCpp, @"([ \t]*)" +
                Regex.Escape(DeserializationConstructorStubToken)).Groups[1].Value;

            foreach (var ct in _metaInfo.CustomTypes)
            {
                var className = _normalizedCustomTypeNamesProvider.GetName(ct) + "CustomType";

                var content = generateCustomTypeStubsContent(ct, fieldsAccessorsListIntendation,
                    fieldsListIntendation, codeIntendation);

                // ClassNameStubToken
                var fileHContent = templateStrH.Replace(IncludesStubToken, content.Includes).
                    Replace(ClassFieldsStubToken, content.ClassFields).
                    Replace(ClassFieldsAccessorsStubToken, content.ClassFieldsAccessors).
                    Replace(ClassNameStubToken, className);
                var fileCppContent = templateStrCpp.Replace(ClassNameStubToken, className).
                    Replace(ToByteArrayStubToken, content.ToByteArrayCode).
                    Replace(DeserializationConstructorStubToken, content.DeserializationConstructorCode);

                // Write
                File.WriteAllText(Path.Combine(_outDir, CustomTypesDir, className + ".h"), fileHContent, 
                                  Encoding.Default);
                File.WriteAllText(Path.Combine(_outDir, CustomTypesDir, className + ".cpp"), fileCppContent, 
                                  Encoding.Default);
            }
        }

        private CustomTypeStubsContent generateCustomTypeStubsContent(CustomType msg, 
            string fieldsAccessorsListIntendation, string fieldsListIntendation, string codeIntendation)
        {
            var content = new CustomTypeStubsContent();

            // IncludesStubToken
            var includeLines = msg.Variables.Where(v => !_simpleTypes.Contains(v.GreisType)).
                Select(v => string.Format("#include \"CustomTypes/{0}CustomType.h\"", getLowerCamelCase(v.GreisType))
                ).ToArray();
            var contentIncludes = string.Join("\r\n", includeLines);
            if (includeLines.Length > 0)
            {
                contentIncludes = "\r\n\r\n" + contentIncludes;
            }
            content.Includes = contentIncludes;

            // ClassFieldsStubToken
            var fields = new List<string>();
            foreach (var variable in msg.Variables)
            {
                var field = string.Format("{0} {1};",
                                          getTypeNameForVariable(variable), getFieldNameForVariable(variable));

                fields.Add(field);
            }
            content.ClassFields = string.Join("\r\n" + fieldsListIntendation, fields.ToArray());

            // ClassFieldsAccessorsStubToken
            var fieldsAccessors = new List<string>();
            foreach (var variable in msg.Variables)
            {
                var getter = string.Format("const {0}& {1}() const {{ return {2}; }}",
                                           getTypeNameForVariable(variable),
                                           getAccessorNameForVariable(variable),
                                           getFieldNameForVariable(variable));
                string setter = string.Format("{0}& {1}() {{ return {2}; }}",
                                              getTypeNameForVariable(variable),
                                              getAccessorNameForVariable(variable),
                                              getFieldNameForVariable(variable));
                string comments = "// " + variable.Comment.
                                              Replace("\n", "\r\n" + fieldsAccessorsListIntendation + "// ");
                string alltogether = string.Format("{0}\r\n{2}{1}\r\n{2}{3}\r\n", comments, getter,
                                                   fieldsAccessorsListIntendation, setter);
                fieldsAccessors.Add(alltogether);
            }
            content.ClassFieldsAccessors = string.Join("\r\n" + fieldsAccessorsListIntendation,
                                                fieldsAccessors.ToArray()).TrimEnd();

            // ToByteArrayStubToken
            var serializationLines = new List<string>();
            foreach (var variable in msg.Variables)
            {
                var line = string.Format("_serializer.Serialize({0}, result);", getFieldNameForVariable(variable));

                serializationLines.Add(line);
            }
            content.ToByteArrayCode = string.Join("\r\n" + codeIntendation, serializationLines.ToArray());

            // DeserializationConstructorStubToken
            if (msg.Size != (int)SizeSpecialValue.Dynamic)
            {
                var arraySizeInUniformFillFields = getArraySizeInUniformFillFieldsLine(msg, codeIntendation);

                var deserializationLines = new List<string>();
                foreach (var variable in msg.Variables)
                {
                    string line = generateDeserializationLine(codeIntendation, variable);

                    deserializationLines.Add(line);
                }
                content.DeserializationConstructorCode = arraySizeInUniformFillFields + 
                    string.Join("\r\n" + codeIntendation, deserializationLines.ToArray());
            } else
            {
                content.DeserializationConstructorCode = "throw ProjectBase::NotImplementedException();";
            }
            
            return content;
        }

        private string getArraySizeInUniformFillFieldsLine(CustomType msg, string codeIntendation)
        {
            int sizeOfFieldsWithKnownSize = 0;
            var sizeOfGreisTypes = new Dictionary<string, int>();
            sizeOfGreisTypes["a1"] = 1;
            sizeOfGreisTypes["u1"] = 1;
            sizeOfGreisTypes["u2"] = 2;
            sizeOfGreisTypes["u4"] = 4;
            sizeOfGreisTypes["i1"] = 1;
            sizeOfGreisTypes["i2"] = 2;
            sizeOfGreisTypes["i4"] = 4;
            sizeOfGreisTypes["f4"] = 4;
            sizeOfGreisTypes["f8"] = 8;
            var greisTypesNames = Enum.GetNames(typeof (GreisTypes));
            int summarySizeOfFillFields = 0;
            foreach (var variable in msg.Variables)
            {
                // typeSize
                int typeSize;
                if (greisTypesNames.Contains(variable.GreisType))
                {
                    typeSize = sizeOfGreisTypes[variable.GreisType];
                }
                else
                {
                    var customType = _metaInfo.CustomTypes.Single(ct => ct.Name == variable.GreisType);
                    Debug.Assert(customType.Size > 0, "Custom types with fixed size are only supported.");
                    typeSize = customType.Size;
                }
                // check if field is dynamic
                bool fillField = false;
                for (int i = 1; i <= variable.DimensionsCount; ++i)
                {
                    if (variable.GetSizeForDimension(i) == (int) SizeSpecialValue.Fill)
                    {
                        fillField = true;
                    }
                }
                if (fillField)
                {
                    summarySizeOfFillFields += typeSize;
                }
                else
                {
                    // altering sizeOfFieldsWithKnownSize
                    if (variable.IsScalar)
                    {
                        sizeOfFieldsWithKnownSize += typeSize;
                    }
                    else
                    {
                        int fieldItemsCount = 1;
                        for (int i = 1; i <= variable.DimensionsCount; ++i)
                        {
                            fieldItemsCount *= variable.GetSizeForDimension(i);
                        }
                        sizeOfFieldsWithKnownSize += typeSize*fieldItemsCount;
                    }
                }
            }

            if (summarySizeOfFillFields == 0)
            {
                return "";
            }

            var arraySizeInUniformFillFields = 
                string.Format("int arraySizeInUniformFillFields = (BodySize() - {0}) / {1};\r\n\r\n{2}",
                    sizeOfFieldsWithKnownSize, summarySizeOfFillFields, codeIntendation);
            return arraySizeInUniformFillFields;
        }

        private string generateDeserializationLine(string codeIntendation, Variable variable)
        {
            string line;
            const string arraySizeInUniformFillFields = "arraySizeInUniformFillFields";

            if (Enum.GetNames(typeof (GreisTypes)).Contains(variable.GreisType))
            {
                // ### one of Greis types ###
                if (variable.IsScalar)
                {
                    // scalar greis type deserialization
                    line = string.Format("_serializer.Deserialize(p_message, {0});\r\n{1}" +
                                         "p_message += sizeof({0});", getFieldNameForVariable(variable),
                                         codeIntendation);
                }
                else if (variable.IsLinearArray && variable.GreisType == GreisTypes.a1.ToString())
                {
                    // character array (string) deserialization
                    string arraySize;
                    switch (variable.GetSizeForDimension(1))
                    {
                    case (int) SizeSpecialValue.Dynamic:
                        throw new FormatException("`Dynamic` is impossible value for fields.");
                    case (int) SizeSpecialValue.Fill:
                        arraySize = arraySizeInUniformFillFields;
                        break;
                    default:
                        arraySize = variable.GetSizeForDimension(1).ToString(CultureInfo.InvariantCulture);
                        break;
                    }
                    line = string.Format("_serializer.Deserialize(p_message, sizeof({0}) * {2}, {0});\r\n{1}" +
                                         "p_message += sizeof({0}) * {2};", getFieldNameForVariable(variable),
                                         codeIntendation, arraySize);
                }
                else
                {
                    // array of any dimensions
                    string countOfItemsInFieldStr;
                    switch (variable.GetSizeForDimension(1))
                    {
                    case (int) SizeSpecialValue.Dynamic:
                        throw new FormatException("`Dynamic` is impossible value for fields.");
                    case (int) SizeSpecialValue.Fill:
                        Debug.Assert(variable.IsLinearArray, "Only linear arrays for `Fill` size is supported.");
                        countOfItemsInFieldStr = arraySizeInUniformFillFields;
                        break;
                    default:
                        int countOfItemsInField = 1;
                        for (int i = 1; i <= variable.DimensionsCount; i++)
                        {
                            countOfItemsInField *= variable.GetSizeForDimension(i);
                        }
                        countOfItemsInFieldStr = countOfItemsInField.ToString(CultureInfo.InvariantCulture);
                        break;
                    }
                    line = string.Format("_serializer.Deserialize(p_message, sizeof({0}) * {2}, {0});\r\n{1}" +
                                         "p_message += sizeof({0}) * {2};", getFieldNameForVariable(variable),
                                         codeIntendation, countOfItemsInFieldStr);
                }
            }
            else
            {
                var customType = _metaInfo.CustomTypes.Single(ct => ct.Name == variable.GreisType);
                // ### CustomType ###
                if (variable.IsScalar)
                {
                    // scalar custom type deserialization
                    Debug.Assert(customType.Size > 0, "Custom types with fixed size are only supported.");
                    line = string.Format("_serializer.Deserialize(p_message, {2}, {0});\r\n{1}" +
                                         "p_message += {2};", getFieldNameForVariable(variable),
                                         codeIntendation, customType.Size);
                }
                else
                {
                    Debug.Assert(variable.IsLinearArray, "Linear arrays of custom types are only supported.");
                    // array of any dimensions
                    string countOfItemsInFieldStr;
                    switch (variable.GetSizeForDimension(1))
                    {
                    case (int) SizeSpecialValue.Dynamic:
                        throw new FormatException("`Dynamic` is impossible value for fields.");
                    case (int) SizeSpecialValue.Fill:
                        countOfItemsInFieldStr = arraySizeInUniformFillFields;
                        break;
                    default:
                        int countOfItemsInField = 1;
                        for (int i = 1; i <= variable.DimensionsCount; i++)
                        {
                            countOfItemsInField *= variable.GetSizeForDimension(i);
                        }
                        countOfItemsInFieldStr = countOfItemsInField.ToString(CultureInfo.InvariantCulture);
                        break;
                    }
                    line = string.Format("_serializer.Deserialize(p_message, {3} * {2}, {3}, {0});\r\n{1}" +
                                         "p_message += {3} * {2};", getFieldNameForVariable(variable),
                                         codeIntendation, countOfItemsInFieldStr, customType.Size);
                }
            }
            return line;
        }

        private void generateStdMessageFactory()
        {
            var stdMessageFactoryTemplatePath = Path.Combine(_cppEnvTemplatesDir, "StdMessageFactory.template.cpp");
            var templateStr = File.ReadAllText(stdMessageFactoryTemplatePath, Encoding.Default);

            var intendation = Regex.Match(templateStr, @"([ \t]*)" + Regex.Escape(StubToken)).Groups[1].Value;
            var includeLines = _metaInfo.StandardMessages.OrderBy(msg => msg.Name).
                Select((msg, i) =>
                       string.Format("#include \"{0}/{1}StdMessage.h\"", StdMessagesDir, 
                                     _normalizedStdMessagesNamesProvider.GetName(msg))).ToArray();
            var lines = _metaInfo.StandardMessages.OrderBy(msg => msg.Name).
                Select((msg, i) =>
                       string.Format("case EMessageId::{0}:\r\n" +
                                     "{1}    return StdMessage::UniquePtr_t(new {0}StdMessage(p_message, p_length));", 
                                     _normalizedStdMessagesNamesProvider.GetName(msg), intendation)
                ).ToArray();
            var stubContent = string.Join("\r\n" + intendation, lines);
            var includesContent = string.Join("\r\n", includeLines);
            var fileContent = templateStr.Replace(StubToken, stubContent).Replace(IncludesStubToken, includesContent);

            File.WriteAllText(Path.Combine(_outDir, "StdMessageFactory.cpp"), fileContent, Encoding.Default);
        }

        private void generateStdMessageGeneratedMembers()
        {
            var stdMessageGeneratedMembersTemplatePath = Path.Combine(_cppEnvTemplatesDir, "StdMessageGeneratedMembers.template.cpp");
            var templateStr = File.ReadAllText(stdMessageGeneratedMembersTemplatePath, Encoding.Default);

            var intendation = Regex.Match(templateStr, @"([ \t]*)" + Regex.Escape(StubToken)).Groups[1].Value;
            var lines = _metaInfo.StandardMessages.OrderBy(msg => msg.Name).
                SelectMany((msg, i) =>
                           msg.Codes.Select(
                               code => string.Format("cache[CHAR2_TO_USHORT(\"{0}\")] = EMessageId::{1};", code, 
                                                     _normalizedStdMessagesNamesProvider.GetName(msg)))
                ).ToArray();
            var stubContent = string.Join("\r\n" + intendation, lines);
            var fileContent = templateStr.Replace(StubToken, stubContent);

            File.WriteAllText(Path.Combine(_outDir, "StdMessageGeneratedMembers.cpp"), fileContent, Encoding.Default);
        }

        private void generateEMessageId()
        {
            var eMessageIdTemplatePath = Path.Combine(_cppEnvTemplatesDir, "EMessageId.template.h");
            var templateStr = File.ReadAllText(eMessageIdTemplatePath, Encoding.Default);

            var intendation = Regex.Match(templateStr, @"([ \t]*)" + Regex.Escape(StubToken)).Groups[1].Value;
            var lastIndex = _metaInfo.StandardMessages.Count - 1;
            var lines = _metaInfo.StandardMessages.OrderBy(msg => msg.Name).
                Select((msg, i) => _normalizedStdMessagesNamesProvider.GetName(msg) + (lastIndex == i ? " // " : ", // ") + msg.Title).
                ToArray();
            var stubContent = string.Join("\r\n" + intendation, lines);
            var fileContent = templateStr.Replace(StubToken, stubContent);

            File.WriteAllText(Path.Combine(_outDir, "EMessageId.h"), fileContent, Encoding.Default);
        }

        private string getTypeNameForVariable(Variable variable)
        {
            string typeName = _simpleTypes.Contains(variable.GreisType)
                                  ? string.Format("Types::{0}", variable.GreisType)
                                  : string.Format("{0}CustomType::UniquePtr_t", getLowerCamelCase(variable.GreisType));
            if (!variable.IsScalar)
            {
                if (variable.GreisType == GreisTypes.a1.ToString())
                {
                    if (variable.DimensionsCount > 1)
                    {
                        throw new NotSupportedException();
                    }
                    typeName = "std::string";
                }
                else
                {
                    for (int i = 0; i < variable.DimensionsCount; i++)
                    {
                        typeName = string.Format("std::vector<{0}>", typeName);
                    }
                }
            }
            return typeName;
        }

        private string getFieldNameForVariable(Variable variable)
        {
            return "_" + getLowerCamelCase(variable.Name);
        }

        private string getAccessorNameForVariable(Variable variable)
        {
            var fieldName = getLowerCamelCase(variable.Name);
            return char.ToUpper(fieldName[0]) + fieldName.Substring(1);
        }

        private string getLowerCamelCase(string s)
        {
            return CustomTypeNameCustomizer.ValidateNameAsVariable(
                CustomTypeNameCustomizer.ReplaceIdField(
                    CustomTypeNameCustomizer.NormalizeNameToLowerCamelCase(s)));
        }
    }
}