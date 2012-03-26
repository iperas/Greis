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
        private const string ConcreteStdMessageStubToken = "${ConcreteStdMessage}";
        private const string StdMessagesDir = "StdMessages";
        private readonly MetaInfo _metaInfo;
        private readonly string _cppEnvTemplatesDir;
        private string _outDir;
        private readonly CustomTypeNameCustomizer _normalizedNamesProvider;

        public CppEnvironmentGenerator(MetaInfo metaInfo, string cppEnvTemplatesDir)
        {
            _metaInfo = metaInfo;
            _cppEnvTemplatesDir = cppEnvTemplatesDir;

            _normalizedNamesProvider = new CustomTypeNameCustomizer(_metaInfo.StandardMessages, s => 
                                                                                                Regex.Replace(s.Name, "_([a-z])", match => match.Groups[1].Value.ToUpper()).Replace("_", ""));
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

            foreach (var msg in _metaInfo.StandardMessages)
            {
                var className = _normalizedNamesProvider.GetName(msg) + "StdMessage";

                var fileHContent = templateStrH.Replace(ConcreteStdMessageStubToken, className);
                var fileCppContent = templateStrCpp.Replace(ConcreteStdMessageStubToken, className);

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
                                     _normalizedNamesProvider.GetName(msg))).ToArray();
            var lines = _metaInfo.StandardMessages.OrderBy(msg => msg.Name).
                Select((msg, i) =>
                       string.Format("case EMessageId::{0}:\r\n" +
                                     "{1}    return StdMessage::UniquePtr_t(new {0}StdMessage(p_message, p_length));", 
                                     _normalizedNamesProvider.GetName(msg), intendation)
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
                                                     _normalizedNamesProvider.GetName(msg)))
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
                Select((msg, i) => _normalizedNamesProvider.GetName(msg) + (lastIndex == i ? " // " : ", // ") + msg.Title).
                ToArray();
            var stubContent = string.Join("\r\n" + intendation, lines);
            var fileContent = templateStr.Replace(StubToken, stubContent);

            File.WriteAllText(Path.Combine(_outDir, "EMessageId.h"), fileContent, Encoding.Default);
        }
    }
}