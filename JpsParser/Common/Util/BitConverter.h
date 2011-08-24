#ifndef BitConverter_h__
#define BitConverter_h__

class BitConverter
{
public:
    inline static unsigned short getUShort(char* data)
    {
        unsigned char* ucdata = reinterpret_cast<unsigned char*>(data);
        return (unsigned short)((*ucdata << 8) + (*(ucdata+1)));
    }

    inline static unsigned int getUInt(char* data)
    {
        unsigned int value = *reinterpret_cast<unsigned int*>(data);
        endian_swap(value);
        return value;
    }

    inline static void endian_swap(unsigned short& x)
    {
        x = (unsigned short)
            ((x>>8) | 
             (x<<8));
    }

    inline static void endian_swap(unsigned int& x)
    {
        x = (x>>24) | 
            ((x<<8) & 0x00FF0000) |
            ((x>>8) & 0x0000FF00) |
            (x<<24);
    }

    // __int64 for MSVC, "long long" for gcc
    inline static void endian_swap(unsigned long long& x)
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

#endif // BitConverter_h__
