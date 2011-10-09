using System;
using System.Collections.Generic;
using System.Xml.Serialization;

namespace GreisDocParser
{
    [Serializable]
    public class CustomType
    {
        public CustomType()
        {
            Variables = new List<Variable>();
            Size = (int) SizeSpecialValues.Dynamic;
        }

        [XmlAttribute]
        public string Name { get; set; }
        [XmlAttribute]
        public int Size { get; set; }
        public List<Variable> Variables { get; set; }

        public override string ToString()
        {
            return string.Format(@"{0} {{{1}}}", Name, Size == -1 ? "?" : Size.ToString());
        }
    }
}