using System;
using System.Collections.Generic;
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
        private const string ConcreteStdMessageStubToken = "${ConcreteStdMessage}";
        private const string StdMessagesDir = "StdMessages";
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

            foreach (var msg in _metaInfo.StandardMessages)
            {
                var className = _normalizedStdMessagesNamesProvider.GetName(msg) + "StdMessage";

                // IncludesStubToken
                var includeLines = msg.Variables.Where(v => !_simpleTypes.Contains(v.GreisType)).
                    Select(v => string.Format("#include \"{0}CustomType.h\"", getLowerCamelCase(v.GreisType))
                        ).ToArray();
                var includeContent = string.Join("\r\n", includeLines);
                if (includeLines.Length > 0)
                {
                    includeContent = "\r\n\r\n" + includeContent;
                }

                // ClassFieldsStubToken
                var fields = new List<string>();
                foreach (var variable in msg.Variables)
                {
                    var field = string.Format("{0} {1};", 
                        getTypeNameForVariable(variable), getFieldNameForVariable(variable));

                    fields.Add(field);
                }
                var fieldsContent = string.Join("\r\n" + fieldsListIntendation, fields.ToArray());

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
                var fieldsAccesorsContent = string.Join("\r\n" + fieldsAccessorsListIntendation, 
                    fieldsAccessors.ToArray()).TrimEnd();

                // ConcreteStdMessageStubToken
                var fileHContent = templateStrH.Replace(IncludesStubToken, includeContent).
                    Replace(ClassFieldsStubToken, fieldsContent).
                    Replace(ClassFieldsAccessorsStubToken, fieldsAccesorsContent).
                    Replace(ConcreteStdMessageStubToken, className);
                var fileCppContent = templateStrCpp.Replace(ConcreteStdMessageStubToken, className);

                // Write
                File.WriteAllText(Path.Combine(_outDir, StdMessagesDir, className + ".h"), fileHContent, 
                                  Encoding.Default);
                File.WriteAllText(Path.Combine(_outDir, StdMessagesDir, className + ".cpp"), fileCppContent, 
                                  Encoding.Default);
            }
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
                                  : string.Format("{0}CustomType", getLowerCamelCase(variable.GreisType));
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