#ifndef BitConverter_h__
#define BitConverter_h__

namespace ProjectBase
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
        EByteOrder _machineByteOrder;
    public:

        BitConverter(EByteOrder byteOrder = LeastSignificantByte);

        inline void ToByteArray(unsigned int val, char* dst)
        {
            *((unsigned int*)dst) = val;
            if (_machineByteOrder != _byteOrder)
            {
                endianSwap(*((unsigned int*)dst));
            }
        }

        inline void ToByteArray(unsigned short val, char* dst)
        {
            *((unsigned short*)dst) = val;
            if (_machineByteOrder != _byteOrder)
            {
                endianSwap(*((unsigned short*)dst));
            }
        }

        inline void ToByteArray(int val, char* dst)
        {
            *((int*)dst) = val;
            if (_machineByteOrder != _byteOrder)
            {
                endianSwap(*((unsigned int*)dst));
            }
        }

        inline void ToByteArray(short val, char* dst)
        {
            *((short*)dst) = val;
            if (_machineByteOrder != _byteOrder)
            {
                endianSwap(*((unsigned short*)dst));
            }
        }

        inline void ToByteArray(float val, char* dst)
        {
            *((float*)dst) = val;
            if (_machineByteOrder != _byteOrder)
            {
                endianSwap(*((unsigned int*)dst));
            }
        }

        inline void ToByteArray(double val, char* dst)
        {
            *((double*)dst) = val;
            if (_machineByteOrder != _byteOrder)
            {
                endianSwap(*((unsigned long long*)dst));
            }
        }

        inline unsigned char GetUChar(const char* data)
        {
            unsigned const char* ucdata = reinterpret_cast<unsigned const char*>(data);
            return *ucdata;
        }

        inline unsigned short GetUShort(const char* data)
        {
            unsigned const char* ucdata = reinterpret_cast<unsigned const char*>(data);
            unsigned short val = (unsigned short)((((unsigned short)*ucdata) << 8) + (*(ucdata+1)));
            if (_byteOrder == LeastSignificantByte)
            {
                endianSwap(val);
            }
            return val;
        }

        inline unsigned int GetUInt(const char* data)
        {
            unsigned const char* ucdata = reinterpret_cast<unsigned const char*>(data);
            unsigned int val = (unsigned int)(
                                (((unsigned int)*ucdata) << 24) + 
                                (((unsigned int)*(ucdata+1)) << 16) + 
                                (((unsigned int)*(ucdata+2)) << 8) + 
                                (*(ucdata+3)));
            if (_byteOrder == LeastSignificantByte)
            {
                endianSwap(val);
            }
            return val;
        }

        /*inline unsigned long GetULong(const char* data)
        {
            unsigned const char* ucdata = reinterpret_cast<unsigned const char*>(data);
            unsigned long val = (unsigned long)(
                (((unsigned long)*(ucdata  )) << 56) + 
                (((unsigned long)*(ucdata+1)) << 48) + 
                (((unsigned long)*(ucdata+2)) << 40) + 
                (((unsigned long)*(ucdata+3)) << 32) + 
                (((unsigned long)*(ucdata+4)) << 24) + 
                (((unsigned long)*(ucdata+5)) << 16) + 
                (((unsigned long)*(ucdata+6)) << 8) + 
                                (*(ucdata+7)));
            if (_byteOrder == LeastSignificantByte)
            {
                endianSwap(val);
            }
            return val;
        }*/

        inline char GetChar(const char* data)
        {
            return *data;
        }

        inline short GetShort(const char* data)
        {
            unsigned short uval = GetUShort(data);
            int val = *(reinterpret_cast<short*>(&uval));
            return val;
        }

        inline int GetInt(const char* data)
        {
            unsigned int uval = GetUInt(data);
            int val = *(reinterpret_cast<int*>(&uval));
            return val;
        }

        inline float GetFloat(const char* data)
        {
            unsigned int uiVal = GetUInt(data);
            float fVal = *(reinterpret_cast<float*>(&uiVal));
            return fVal;
        }

        inline double GetDouble(const char* data)
        {
            unsigned int uiVal1 = GetUInt(data);
            unsigned int uiVal2 = GetUInt(data + 4);
            unsigned long long ulVal;
            if (_byteOrder == LeastSignificantByte)
            {
                ulVal = uiVal1 + ((unsigned long long)uiVal2 << 32);
            } else {
                ulVal = uiVal2 + ((unsigned long long)uiVal1 << 32);
            }
            double dVal = *(reinterpret_cast<double*>(&ulVal));
            return dVal;
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
