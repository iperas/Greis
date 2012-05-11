using System;
using System.Collections.Generic;
using System.Linq;
using System.Xml.Serialization;

namespace GreisDocParser
{
    [Serializable]
    public class CustomType
    {
        private const string BeginOfOptionalDataBlockLine = "Optional data block";
        private const string EndOfOptionalDataBlockLine = "End of optional data block";

        public CustomType()
        {
            Variables = new List<Variable>();
            Size = (int)SizeSpecialValue.Dynamic;
        }

        [XmlAttribute]
        public string Name { get; set; }
        [XmlAttribute]
        public int Size { get; set; }
        public List<Variable> Variables { get; set; }

        [XmlIgnore]
        public bool ContainsOptionalDataBlock
        {
            get { return Variables.Any(v => v.Comment.Contains(BeginOfOptionalDataBlockLine)); }
        }

        [XmlIgnore]
        public Variable FirstOptionalDataBlockVariable
        {
            get
            {
                Variable prevVar = null;
                foreach (var variable in Variables)
                {
                    if (prevVar != null && prevVar.Comment.Contains(BeginOfOptionalDataBlockLine))
                    {
                        return variable;
                    }
                    prevVar = variable;
                }
                throw new Exception(
                    string.Format("`Optional data block` mark has not been found in comment of '{0}' Type.", 
                    ToString()));
            }
        }

        [XmlIgnore]
        public Variable LastOptionalDataBlockVariable
        {
            get
            {
                var variable = Variables.FirstOrDefault(v => v.Comment.Contains(EndOfOptionalDataBlockLine));
                if (variable != null)
                {
                    return variable;
                }
                throw new Exception(
                    string.Format("`End of optional data block` mark has not been found in comment of '{0}' Type.", 
                    ToString()));
            }
        }

        public override string ToString()
        {
            return string.Format(@"{0} {{{1}}}", Name, Size == (int)SizeSpecialValue.Dynamic ? "?" : Size.ToString());
        }
    }
}