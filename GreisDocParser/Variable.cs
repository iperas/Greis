using System;
using System.Collections.Generic;
using System.Linq;
using System.Xml.Serialization;

namespace GreisDocParser
{
    [Serializable]
    public class Variable
    {
        public Variable()
        {
            Dimensions = new List<int>();
        }

        [XmlAttribute]
        public string Type { get; set; }
        [XmlAttribute]
        public string Name { get; set; }
        [XmlAttribute]
        public List<int> Dimensions { get; set; }
        [XmlAttribute]
        public string RequiredValue { get; set; }
        public string Comment { get; set; }

        public override string ToString()
        {
            string dimStr;
            if (Dimensions.Count == 1 && Dimensions[0] == 1)
            {
                dimStr = "";
            } else
            {
                dimStr = string.Concat(Dimensions.Select(v => string.Concat("[", v == (int) SizeSpecialValues.Dynamic ? "" : v.ToString(), "]")));
            }
            return string.Format(@"{0} {1}{2}", Type, Name, dimStr);
        }
    }
}