#ifndef BitConverter_h__
#define BitConverter_h__

namespace Util
{
    class BitConverter
    {
    public:
        enum EByteOrder
        {
            MostSignificantByte,
            LeastSignificantByte
        };

    private:
        EByteOrder _byteOrder;

    public:

        BitConverter(EByteOrder byteOrder)
        {
            _byteOrder = byteOrder;
        }

        inline unsigned short GetUShort(const char* data)
        {
            unsigned const char* ucdata = reinterpret_cast<unsigned const char*>(data);
            unsigned short val = (unsigned short)((*ucdata << 8) + (*(ucdata+1)));
            if (_byteOrder == LeastSignificantByte)
            {
                endianSwap(val);
            }
            return val;
        }

        inline unsigned short GetUInt(const char* data)
        {
            unsigned const char* ucdata = reinterpret_cast<unsigned const char*>(data);
            unsigned int val = (unsigned int)((*ucdata << 24) + (*(ucdata+1) << 16) + (*(ucdata+2) << 8) + (*(ucdata+3)));
            if (_byteOrder == LeastSignificantByte)
            {
                endianSwap(val);
            }
            return val;
        }

    private:
        inline static void endianSwap(unsigned short& x)
        {
            x = (unsigned short)
                ((x>>8) | 
                (x<<8));
        }

        inline static void endianSwap(unsigned int& x)
        {
            x = (x>>24) | 
                ((x<<8) & 0x00FF0000) |
                ((x>>8) & 0x0000FF00) |
                (x<<24);
        }

        // __int64 for MSVC, "long long" for gcc
        inline static void endianSwap(unsigned long long& x)
        {
            x = (x>>56) | 
                ((x<<40) & 0x00FF000000000000) |
                ((x<<24) & 0x0000FF0000000000) |
                ((x<<8)  & 0x000000FF00000000) |
                ((x>>8)  & 0x00000000FF000000) |
                ((x>>24) & 0x0000000000FF0000) |
                ((x>>40) & 0x000000000000FF00) |
                (x<<56);
        }
    };
}

#endif // BitConverter_h__
