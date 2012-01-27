namespace GreisDocParser
{
    /// <summary>
    /// Для переменных возможен только вариант Dynamic (когда массив динамический, с неизвестной длиной).
    /// </summary>
    public enum SizeSpecialValue
    {
        Dynamic = -1,   // Size is computing according unknown special logic
        Fill = -2,      // Size is computing by formula: (struct size) - (other fields size)
        Fixed = -3,      // Size is fixed but not specified directly
    }
}