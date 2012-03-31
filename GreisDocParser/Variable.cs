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
        /// ������ � �������� ������� �� ������ �� ������������, ����� ����������� ���������� � ����.
        /// </summary>
        /// <remarks>
        /// ������������ ��� ���� ������������.
        /// </remarks>
        [XmlArrayItem("Dimension")]
        public List<int> SizeOfDimensions { get; set; }

        /// <summary>
        /// �������� ������ ��� ����������� <paramref name="dimensionNumber"/>.
        /// </summary>
        /// <param name="dimensionNumber">����� �����������, ������� � 1.</param>
        /// <returns>�������� ������������� ������ ��� ���� �� �������� <c>SizeSpecialValue</c>.</returns>
        public int GetSizeForDimension(int dimensionNumber)
        {
            if (dimensionNumber == 0)
            {
                throw new FormatException("����������� 0 �������� �������� � �� ����� �������.");
            }
            if (dimensionNumber > DimensionsCount || dimensionNumber < 0)
            {
                throw new ArgumentOutOfRangeException("dimensionNumber");
            }

            return SizeOfDimensions[dimensionNumber - 1];
        }

        /// <summary>
        /// ����������� ������ ����������.
        /// </summary>
        /// <remarks>
        /// ������ ����� ����������� 0.
        /// �������� ������ ����� ����������� 1.
        /// ������� ����� ����������� 2.
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
        [XmlIgnore]
        public bool IsLinearArray { get { return DimensionsCount == 1; } }

        public override string ToString()
        {
            string dimStr = IsScalar 
                ? "" 
                : string.Concat(SizeOfDimensions.Select(v => string.Concat("[", v == (int) SizeSpecialValue.Fill ? "" : v.ToString(), "]")));
            return string.Format(@"{0} {1}{2}", GreisType, Name, dimStr);
        }
    }
}