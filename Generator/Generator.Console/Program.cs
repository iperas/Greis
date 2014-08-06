using System;
using System.IO;
using System.Text;
using CommandLine;
using Generator.Core;
using Generator.Core.Model;
using NLog;
using NLog.Config;

namespace Generator.Console
{
    class Program
    {
        private const string NLogConfig = "NLog.config";
        private const string DefaultMetaFileName = "meta-info.xml";
        private const string DefaultSqlFileName = "baseline.sql";

        public static int Main(string[] args)
        {
            var options = new Options();
            if (!Parser.Default.ParseArguments(args, options))
            {
                return 1;
            }

            try
            {
                InitializeLogging();
                CheckFile(options.SourceFile);
                switch (options.Command)
                {
                case Options.GenXmlCommand:
                    GenerateMetaXml(options.SourceFile, options.Target);
                    break;
                case Options.GenCppCommand:
                    GenerateCppCode(options.SourceFile, options.Target);
                    break;
                case Options.GenSqlCommand:
                    GenerateSqlBaseline(options.SourceFile, options.Target, options.DatabaseName);
                    break;
                }
            }
            catch (Exception ex)
            {
                System.Console.WriteLine(ex);
                return 1;
            }

            return 0;
        }

        private static void GenerateCppCode(string metaFile, string targetDir)
        {
            var metaInfo = MetaInfo.FromXmlFile(metaFile);
            var cppGen = new CppCodeGenerator(metaInfo);
            cppGen.Generate(targetDir);
        }

        private static void InitializeLogging()
        {
            LogManager.Configuration = new XmlLoggingConfiguration(Path.Combine(PathHelper.StartupPath, NLogConfig));
        }

        private static void GenerateSqlBaseline(string metaFile, string targetDir, string databaseName)
        {
            var metaInfo = MetaInfo.FromXmlFile(metaFile);
            var generator = new MySqlBaselineGenerator(metaInfo, databaseName);
            generator.Generate(Path.Combine(targetDir, DefaultSqlFileName));
        }

        private static void GenerateMetaXml(string sourceFile, string targetDir)
        {
            var text = File.ReadAllText(sourceFile, Encoding.Default);
            var metaInfo = MetaInfoGenerator.FromUserManual(text);
            metaInfo.ToXmlFile(Path.Combine(targetDir, DefaultMetaFileName));
        }

        private static void CheckFile(string fileName)
        {
            if (!File.Exists(fileName))
            {
                throw new Exception(string.Format("The file {0} does not exist.", fileName));
            }
        }
    }
}
