namespace Generator.Core.Model
{
    /// <summary>
    /// ��� ����������:
    /// �������� ������ ������� Fill (����� ���� - ������������ ������ (� ����������� ������)).
    /// 
    /// ��� �������� � ���������:
    /// Fill = ���� � ������������ ������ ����������� ���������� �� ������� fieldCount = (struct_size - static_fields_size) / (the_other_fields_size)
    /// Dynamic = ������� ����� ��������� ��������� ��������� ����������� ���������.
    /// </summary>
    public enum SizeSpecialValue
    {
        Dynamic = -1,   // Size is computing according to unknown special logic
        Fill = -2,      // Size is computing with formula: (struct size) - (other fields size)
        FixedWithOptionalDataBlock = -3, // Size value is one of fixed values (with or without optional block)
    }
}