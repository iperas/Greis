#pragma once

namespace Greis
{
    struct ECustomTypeId
    {
        enum Type
        {
            Unknown,
            CalBandsDelay,
            ClkOffs,
            ESI,
            ExtSpecData,
            GloDelays,
            GPSAlm1,
            GPSEphemeris1,
            GpsEphOptData,
            GpsEphReqData,
            GpsNavData1,
            GpsRawNavData1,
            Header,
            IonoParams1,
            SlotRec,
            Smooth,
            SpecData,
            SvData0,
            SvData1,
            SvData2,
            UtcOffs
        };
    };
}
