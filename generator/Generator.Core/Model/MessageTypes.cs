namespace Generator.Core.Model
{
    public enum MessageTypes
    {
        Unknown = 1,
        AlmanacsAndEphemeris,
    }

    public enum MessageKinds
    {
        NonStandardTextMessage = 1, 
        StandardTextMessage, 
        GreisStandardMessage, 
        ForeignStandardMessage, 
        UnknownStandardMessage,
    }
}