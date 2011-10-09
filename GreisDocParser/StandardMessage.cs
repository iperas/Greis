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
        }

        [XmlAttribute]
        public string Title { get; set; }
        [XmlArrayItem("Code")]
        public List<string> Codes { get; set; }
        public ValidationTypes Validation { get; set; }

        public override string ToString()
        {
            return Title;
        }
    }
}