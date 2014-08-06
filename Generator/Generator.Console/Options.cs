using CommandLine;
using CommandLine.Text;

namespace Geenrator.Console
{
    public class Options
    {
        public const string GenXmlCommand = "gen-xml";
        public const string GenCppCommand = "gen-cpp";
        public const string GenSqlCommand = "gen-sql";

        [Option('c', "command", Required = true, HelpText = "Command: gen-xml, gen-cpp, gen-sql")]
        public string Command { get; set; }

        [Option('s', "source", Required = true, HelpText = "Source file (XML meta file or Greis manual as a simple text file)")]
        public string SourceFile { get; set; }

        [Option('t', "target", Required = true, HelpText = "Target directory for the output. Output data has fixed filename that cannot be changed.")]
        public string Target { get; set; }

        [Option('b', "database", DefaultValue = "world", HelpText = "Database name that will be used by the sql baseline generator while generating baseline.sql, `world` by default.")]
        public string DatabaseName { get; set; }

        [HelpOption(HelpText = "Display this help screen.")]
        public string GetUsage()
        {
            var help = new HelpText("Greis code-gen tool");
            help.AddOptions(new Options());
            return help;
        }
    }
}