using System.Collections.Generic;
using System.IO;
using System.Xml.Serialization;

namespace Generator.Core.Model
{
    public class MetaInfo
    {
        private static readonly XmlSerializer Serializer = new XmlSerializer(typeof(MetaInfo));

        public MetaInfo()
        {
            this.StandardMessages = new List<StandardMessage>();
            this.CustomTypes = new List<CustomType>();
        }

        public List<StandardMessage> StandardMessages { get; set; }
        public List<CustomType> CustomTypes { get; set; }

        public void ToXmlFile(string fileName)
        {
            var dirName = Path.GetDirectoryName(fileName);
            if (dirName != null)
            {
                Directory.CreateDirectory(dirName);
            }

            using (var outFile = File.Create(fileName))
            {
                Serializer.Serialize(outFile, this);
            }
        }

        public static MetaInfo FromXmlFile(string filename)
        {
            using (var inFile = File.OpenRead(filename))
            {
                var metaInfo = (MetaInfo) Serializer.Deserialize(inFile);
                return metaInfo;
            }
        }
    }
}