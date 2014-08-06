using System;
using System.Diagnostics;
using System.IO;
using System.Text;
using Comindware.Localization.Lib.Utils;
using GreisDocParser;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Generator.Tests
{
    [DeploymentItem("TestData", "TestData")]
    [DeploymentItem(@"Templates\Sql", @"Templates\Sql")]
    [DeploymentItem(@"Templates\Cpp", @"Templates\Cpp")]
    [TestClass]
    public class IntegrationTests
    {
        public TestContext TestContext { get; set; }

        [TestMethod]
        public void ShouldGenerateMetaXml()
        {
            var text = File.ReadAllText(@"TestData\\greis-manual.txt", Encoding.Default);
            var actualFile = Path.Combine(TestContext.TestResultsDirectory, "meta-info.xml");

            var metaInfo = MetaInfoGenerator.FromUserManual(text);
            metaInfo.ToXmlFile(actualFile);

            CompareFiles(@"TestData\\meta-info.xml", actualFile);
        }

        [TestMethod]
        public void ShouldGenerateSqlBaseline()
        {
            var metaInfo = MetaInfo.FromXmlFile(@"TestData\\meta-info.xml");
            var actualFile = Path.Combine(TestContext.TestResultsDirectory, "baseline.sql");

            var generator = new MySqlBaselineGenerator(metaInfo, "world");
            generator.GenerateMysqlBaseline(actualFile);

            CompareFiles(@"TestData\\baseline.sql", actualFile);
        }

        private static void CompareFiles(string expectedFile, string actualFile)
        {
            var encoding = new UTF8Encoding(false);
            var expected = File.ReadAllText(expectedFile, encoding);
            var actual = File.ReadAllText(actualFile, encoding);
            Assert.AreEqual(expected, actual);
        }
    }
}
