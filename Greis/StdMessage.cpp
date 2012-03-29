#include "StdMessage.h"
#include "GreisTypes.h"
#include "ChecksumComputer.h"
#include "boost/format.hpp"
#include "ProjectBase/BitConverter.h"
#include "RawStdMessage.h"

using std::string;
using std::vector;
using namespace ProjectBase;

namespace Greis
{
    StdMessage::StdMessage() : Message(EMessageKind::StdMessage)
    {
    }

    bool StdMessage::Validate() const
    {
        string aId = Id();
        if (aId[0] < MinIdValue || aId[0] > MaxIdValue || 
            aId[1] < MinIdValue || aId[1] > MaxIdValue)
            return false;
        return true;
    }

    bool StdMessage::validateChecksum8Ascii(char* p_message, int p_length)
    {
        // expected
        if (p_length < HeadSize() + 2)
        {
            throw Exception("Body too small.");
        }
        if (p_length == HeadSize() + 2)
        {
            return true;
        }
        bool bOk;
        Types::u1 expected = QString::fromAscii(p_message + p_length - 2, 2).toUInt(&bOk, 16);
        if (!bOk)
        {
            return false;
        }
        // actual
        Types::u1 actual = ChecksumComputer::ComputeCs8(p_message, p_length - 2);
        // check
        return expected == actual;
    }

    bool StdMessage::validateChecksum8Bin(char* p_message, int p_length)
    {
        // expected
        if (p_length < HeadSize() + 1)
        {
            throw Exception("Body too small.");
        }
        if (p_length == HeadSize() + 1)
        {
            return true;
        }
        Types::u1 expected = ((Types::u1*)p_message)[p_length - 1];
        // actual
        Types::u1 actual = ChecksumComputer::ComputeCs8(p_message, p_length - 1);
        // check
        return expected == actual;
    }

    std::string StdMessage::convertByteArrayToReadableString( char* p_message, int p_length )
    {
        string ret;
        for (int i = 0; i < p_length; ++i)
        {
            char ch = p_message[i];
            if (isprint((unsigned char)ch))
            {
                ret.push_back(ch);
            }
            else
            {
                ret.append(boost::str(boost::format("{0x%1$02X}") % (unsigned int)(unsigned char)ch));
            }
        }
        return ret;
    }

    std::string StdMessage::toString( const std::string& tagName ) const
    {
        auto messageBytes = ToByteArray();
        auto bodyStr = convertByteArrayToReadableString(messageBytes.data() + 5, messageBytes.size() - 5);
        string ret = boost::str(boost::format("<%1% id='%2%' body_length=%3%>%4%</%1%>") 
            % tagName % Id() % BodySize() % bodyStr);
        return ret;
    }

    QByteArray StdMessage::headToByteArray() const
    {
        QByteArray head;
        head.append(Id().c_str(), 2);
        auto bodySizeStr = QString::number(BodySize(), 16).rightJustified(3, '0', true);
        head.append(bodySizeStr.toAscii(), 3);
        return head;
    }

    class GreisSerializer
    {
    public:
        GreisSerializer(BitConverter::EByteOrder byteOrder) : _bitConverter(byteOrder)
        {
        }

        template<typename T>
        void Serialize(T val, QByteArray& outStream)
        {
            static_assert(std::is_arithmetic<T>::value && sizeof(T) > 1, "T is not a Greis type.");

            char buffer[sizeof(T)];
            _bitConverter.ToByteArray(val, buffer);
            outStream.append(buffer, sizeof(T));
        }

        template<typename T>
        void Serialize(const std::vector<T>& val, QByteArray& outStream)
        {
            for (auto it = val.begin(); it != val.end(); ++it)
            {
                Serialize(*it, outStream);
            }
        }

        template<typename T>
        void Serialize(const std::unique_ptr<T>& val, QByteArray& outStream)
        {
            outStream.append(val->ToByteArray());
        }

        void Serialize(char val, QByteArray& outStream)
        {
            outStream.append(val);
        }

        void Serialize(unsigned char val, QByteArray& outStream)
        {
            outStream.append(*((char*)&val));
        }

        void Serialize(const std::string& val, QByteArray& outStream)
        {
            outStream.append(val.c_str(), val.size());
        }

        template<typename T>
        T Deserialize(const char* data)
        {
            return sizeof(T);
        }

        /*template<typename T>
        void serialize(T* val, int size, QByteArray& outStream)
        {
            for (int i = 0; i < size; ++i)
            {
                serialize(val[i], outStream);
            }
        }

        template<typename T>
        void serialize(std::vector<T>* val, int size, QByteArray& outStream)
        {
            for (int i = 0; i < size; ++i)
            {
                serialize(&val[i][0], val[i].size(), outStream);
            }
        }*/


        /*template<>
        void serialize<std::string>(std::string val, QByteArray& outStream)
        {
            outStream.append(val.c_str(), val.size());
        }

        template<>
        void serialize<std::string&>(std::string& val, QByteArray& outStream)
        {
            outStream.append(val.c_str(), val.size());
        }*/

        /*template<>
        void serialize<const std::string&>(const std::string& val, QByteArray& outStream)
        {
            outStream.append(val.c_str(), val.size());
        }*/
    private:
        BitConverter _bitConverter;
    };

    void f()
    {
        GreisSerializer aaa(BitConverter::LeastSignificantByte);
        QByteArray asd;
        char a = 123;
        short b = 321;
        int c = 3211;
        long long d = 123123;
        std::string e = "asdasd";
        std::vector<int> h;
        h.push_back(123);
        unsigned char g = 123;
        auto zzz = make_unique<RawStdMessage>("test",0);
        
        aaa.Serialize(a, asd);
        aaa.Serialize(b, asd);
        aaa.Serialize(c, asd);
        aaa.Serialize(d, asd);
        aaa.Serialize(e, asd);
        aaa.Serialize(g, asd);
        aaa.Serialize(h, asd);
        aaa.Serialize(zzz, asd);

        int az;
        az = aaa.Deserialize<decltype(az)>(&a);
        //short az2 = aaa.deserialize(&a);
    }
}
