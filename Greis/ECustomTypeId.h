#ifndef ECustomTypeId_h__
#define ECustomTypeId_h__

namespace Greis
{
    struct ECustomTypeId
    {
        enum Type
        {
            Unknown,
            ClkOffs,
            GPSAlm1,
            GPSEphemeris1,
            Header,
            SlotRec,
            Smooth,
            SvData0,
            SvData1,
            SvData2,
            UtcOffs
        };
    };
}

#endif // ECustomType_h__
