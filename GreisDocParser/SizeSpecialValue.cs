namespace GreisDocParser
{
    /// <summary>
    /// Для переменных:
    /// Возможен только вариант Fill (когда поле - динамический массив (с неизвестной длиной)).
    /// 
    /// Для структур и сообщений:
    /// Fill = Поля с динамической длиной заполняются равномерно по формуле fieldCount = (struct_size - static_fields_size) / (the_other_fields_size)
    /// Dynamic = Размеры полей требуется вычислять используя специальные алгоритмы.
    /// </summary>
    public enum SizeSpecialValue
    {
        Dynamic = -1,   // Size is computing according to unknown special logic
        Fill = -2,      // Size is computing with formula: (struct size) - (other fields size)
        FixedWithOptionalDataBlock = -3, // Size value is one of fixed values (with or without optional block)
    }
}