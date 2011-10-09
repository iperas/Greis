using System.Collections.Generic;
using System.IO;
using System.Xml.Serialization;

namespace GreisDocParser
{
    public class MetaInfo
    {
        private static readonly XmlSerializer _serializer = new XmlSerializer(typeof(MetaInfo));

        public MetaInfo()
        {
            StandardMessages = new List<StandardMessage>();
            CustomTypes = new List<CustomType>();
        }

        public List<StandardMessage> StandardMessages { get; set; }
        public List<CustomType> CustomTypes { get; set; }

        public void ToFile(string filename)
        {
            using (var outFile = File.Create(filename))
            {
                _serializer.Serialize(outFile, this);
            }
        }
    }
}