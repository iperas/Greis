using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using Generator.Core;
using Generator.Core.Model;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Generator.Tests
{
    [DeploymentItem("TestData", "TestData")]
    [DeploymentItem(@"Templates\Sql", @"Templates\Sql")]
    [DeploymentItem(@"Templates\Cpp", @"Templates\Cpp")]
    [DeploymentItem(@"Templates\Cpp\StdMessage", @"Templates\Cpp\StdMessage")]
    [DeploymentItem(@"Templates\Cpp\CustomType", @"Templates\Cpp\CustomType")]
    [TestClass]
    public class IntegrationTests
    {
        public TestContext TestContext { get; set; }

        [TestMethod]
        public void ShouldGenerateMetaXml()
        {
            var text = File.ReadAllText(@"TestData\greis-manual.txt", Encoding.Default);
            var actualFile = Path.Combine(TestContext.TestResultsDirectory, "meta-info.xml");

            var metaInfo = MetaInfoGenerator.FromUserManual(text);
            metaInfo.ToXmlFile(actualFile);

            CompareFiles(@"TestData\meta-info.xml", actualFile);
        }

        [TestMethod]
        public void ShouldGenerateSqlBaseline()
        {
            var metaInfo = MetaInfo.FromXmlFile(@"TestData\meta-info.xml");
            var actualFile = Path.Combine(TestContext.TestResultsDirectory, "baseline.sql");

            var generator = new MySqlBaselineGenerator(metaInfo, "world");
            generator.Generate(actualFile);

            CompareFiles(@"TestData\Out\baseline.sql", actualFile);
        }

        [TestMethod]
        public void ShouldGenerateCppCode()
        {
            var metaInfo = MetaInfo.FromXmlFile(@"TestData\meta-info.xml");
            var actualDir = Path.Combine(TestContext.TestResultsDirectory, "ActualCppCode");

            var generator = new CppCodeGenerator(metaInfo);
            generator.Generate(actualDir);

            CompareDirectories(@"TestData\Out\CppCode", actualDir);
        }

        private static void CompareDirectories(string expectedDir, string actualDir)
        {
            var expectedFiles = Directory.GetFiles(expectedDir, "*", SearchOption.AllDirectories)
                .Select(x => x.Substring(expectedDir.Length + 1)).ToArray();
            var actualFiles = Directory.GetFiles(actualDir, "*", SearchOption.AllDirectories)
                .Select(x => x.Substring(actualDir.Length + 1)).ToArray();

            var difference = new HashSet<string>(expectedFiles);
            difference.SymmetricExceptWith(actualFiles);

            if (difference.Any())
            {
                throw new Exception(string.Format("The directories differ:\r\n{0}", string.Join(Environment.NewLine, difference)));
            }

            foreach (var fileName in expectedFiles)
            {
                var expectedFileName = Path.Combine(expectedDir, fileName);
                var actualFileName = Path.Combine(actualDir, fileName);
                CompareFiles(expectedFileName, actualFileName);
            }
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
