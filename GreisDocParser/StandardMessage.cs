using System;
using System.Collections.Generic;
using System.Xml.Serialization;

namespace GreisDocParser
{
    [Serializable]
    public class StandardMessage : CustomType
    {
        public StandardMessage()
        {
            Codes = new List<string>();
            Variables = new List<Variable>();
            Size = (int) SizeSpecialValues.Dynamic;
            Type = MessageTypes.Unknown;
        }

        [XmlAttribute]
        public string Title { get; set; }
        [XmlArrayItem("Code")]
        public List<string> Codes { get; set; }
        [XmlAttribute]
        public ValidationTypes Validation { get; set; }
        [XmlAttribute]
        public MessageTypes Type { get; set; }

        public override string ToString()
        {
            return Title;
        }
    }
}