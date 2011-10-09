namespace GreisDocParser
{
    public enum SizeSpecialValues
    {
        Dynamic = -1,   // Size is computing according unknown special logic
        Fill = -2,      // Size is computing by formula: (struct size) - (other fields size)
    }
}