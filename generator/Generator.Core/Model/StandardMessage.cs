using System;
using System.Collections.Generic;
using System.Xml.Serialization;

namespace Generator.Core.Model
{
    [Serializable]
    public class StandardMessage : CustomType
    {
        public StandardMessage()
        {
            this.Codes = new List<string>();
            this.Type = MessageTypes.Unknown;
        }

        [XmlAttribute]
        public string Title { get; set; }
        [XmlArrayItem("Code")]
        public List<string> Codes { get; set; }
        [XmlAttribute]
        public ValidationType Validation { get; set; }
        [XmlAttribute]
        public MessageTypes Type { get; set; }

        public override string ToString()
        {
            return this.Title;
        }
    }
}