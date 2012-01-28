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
            SizeOfDimensions = new List<int>();
        }

        [XmlAttribute]
        public string GreisType { get; set; }
        [XmlAttribute]
        public string Name { get; set; }

        /// <summary>
        /// —писок с размером массива по каждой из размерностей, номер размерности начинаетс€ с нул€.
        /// </summary>
        /// <remarks>
        /// ѕредназначен дл€ нужд сериализации.
        /// </remarks>
        [XmlArrayItem("Dimension")]
        public List<int> SizeOfDimensions { get; set; }

        /// <summary>
        /// ѕолучить размер дл€ размерности <paramref name="dimensionNumber"/>.
        /// </summary>
        /// <param name="dimensionNumber">Ќомер размерности, начина€ с 1.</param>
        /// <returns>«аданный фиксированный размер или одно из значений <c>SizeSpecialValue</c>.</returns>
        public int GetSizeForDimension(int dimensionNumber)
        {
            if (dimensionNumber == 0)
            {
                throw new FormatException("–азмерность 0 €вл€етс€ скал€ром и не имеет размера.");
            }
            if (dimensionNumber > DimensionsCount || dimensionNumber < 0)
            {
                throw new ArgumentOutOfRangeException("dimensionNumber");
            }

            return SizeOfDimensions[dimensionNumber - 1];
        }

        /// <summary>
        /// –азмерность данной переменной.
        /// </summary>
        /// <remarks>
        /// —кал€р имеет размерность 0.
        /// Ћинейный массив имеет размерность 1.
        /// ћатрица имеет размерность 2.
        /// </remarks>
        [XmlIgnore]
        public int DimensionsCount
        {
            get { return SizeOfDimensions.Count; }
        }

        [XmlAttribute]
        public string RequiredValue { get; set; }
        public string Comment { get; set; }
        [XmlIgnore]
        public bool IsScalar { get { return DimensionsCount == 0; } }

        public override string ToString()
        {
            string dimStr = IsScalar 
                ? "" 
                : string.Concat(SizeOfDimensions.Select(v => string.Concat("[", v == (int) SizeSpecialValue.Fill ? "" : v.ToString(), "]")));
            return string.Format(@"{0} {1}{2}", GreisType, Name, dimStr);
        }
    }
}