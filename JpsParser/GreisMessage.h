#ifndef GreisMessage_h__
#define GreisMessage_h__

#include "Util/Macro.h"
#include "Util/SharedPtr.h"
#include "Util/InvalidOperationException.h"
#include <cassert>
#include <string>
#include <vector>
#include <map>
#include <boost/algorithm/string.hpp>
#include "GreisTypes.h"
#include "GreisChecksum.h"

#include <boost/format.hpp>
#include <QtXml/QtXml>
#include "Util/File.h"
#include "Util/Logger.h"

using std::string;
using std::vector;
using std::map;

using namespace Util;

namespace stringBoost = boost::algorithm;

#pragma pack (push, 1)

#define CHAR2_TO_USHORT(c_id) ((((unsigned short)(c_id)[0]) << 8) | (c_id)[1])

namespace Greis
{
    enum EMessageType
    {
        NonStdTextMessage,
        UnknownStdMessage,
        JPStdMessage,
        MFStdMessage,
        RTStdMessage
    };

    class Message_t
    {
    private:
        const EMessageType _type;
    public:
        SHARED_PTR_T(Message_t);
        NULL_PTR_DECL;

        Message_t(EMessageType p_type) : _type(p_type)
        {
        }

        virtual string toString() const = 0;
        virtual bool validate() const = 0;

        inline EMessageType type() const { return _type; }
    };

    class NonStdTextMessage_t : public Message_t
    {
    public:
        SHARED_PTR_T(NonStdTextMessage_t);
        NULL_PTR_DECL;

        // Zero-length non-standard Text Message
        NonStdTextMessage_t(char p_eom) : Message_t(NonStdTextMessage)
        {
            id = 0;
            eom = p_eom;
        }

        // Non-standard Text Message
        NonStdTextMessage_t(char p_id, string p_body, char p_eom) : Message_t(NonStdTextMessage)
        {
            id = p_id;
            body = p_body;
            eom = p_eom;
        }

        virtual string toString() const
        {
            string eomStr = eom == '\r' ? "\\r" : (eom == '\n' ? "\\n" : string(1, eom));
            string ret = boost::str(boost::format("<NonStdTextMessage id=0x%1$02X body_length=%2% eom='%3%'>%4%</NonStdTextMessage>") % (int)id % body.size() % eomStr % body);
            return ret;
        }

        virtual bool validate() const
        {
            if (body.size() > 0 && (id < min_id || id > max_id))
                return false;
            if (!isEom(eom))
                return false;
            return true;
        }

        inline static bool isEom(char ch) { return ch == '\r' || ch == '\n'; }

        char id;
        string body;
        char eom;

        static const char min_id = 33;
        static const char max_id = 47;
    };

    class StdMessage_t : public Message_t
    {
    public:
        SHARED_PTR_T(StdMessage_t);
        NULL_PTR_DECL;

        StdMessage_t(char* p_message, int p_length)
            : Message_t(UnknownStdMessage), _message(p_length)
        {
            memcpy(&_message[0], p_message, p_length);
        }

        virtual string toString() const
        {
            return toString("StdMessage");
        }

        virtual bool validate() const
        {
            string aId = id();
            if (aId[0] < min_id_char || aId[0] > max_id_char || 
                aId[1] < min_id_char || aId[1] > max_id_char)
                return false;
            return true;
        }

        inline string id() const { return string(&_message[0], 2); }
        inline static int headSize() { return _headSize; }
        inline int bodySize() const { return _message.size() - _headSize; }
        inline int fullSize() const { return headSize() + bodySize(); }
        inline const char* body() const
        {
            if (bodySize() == 0)
                throw InvalidOperationException();
            return &_message[_headSize];
        }
        inline const char* message() const { return &_message[0]; }

        static const char min_id_char = 48;
        static const char max_id_char = 126;

    protected:
        StdMessage_t(char* p_message, int p_length, EMessageType p_msgType)
            : Message_t(p_msgType), _message(p_length)
        {
            memcpy(&_message[0], p_message, p_length);
        }

        string toString(const string& tagName) const
        {
            string ret = boost::str(boost::format("<%1% id='%2%' body_length=%3%>%4%</%1%>") % tagName % id() % bodySize() % bodyToString());
            return ret;
        }

        // Переопределить в потомках для корректного отображения содержимого в toString(tagName)
        virtual string bodyToString() const
        {
            string ret;
            for (vector<char>::const_iterator it = _message.begin() + 5; it != _message.end(); ++it)
            {
                char ch = *it;
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

        bool validateChecksum8ascii() const
        {
            // expected
            if (bodySize() <= 2)
                throw Exception("Body too small.");
            bool bOk;
            Types::u1 expected = QString::fromAscii(body() + bodySize() - 2, 2).toUInt(&bOk, 16);
            if (!bOk)
                return false;
            // actual
            Types::u1 actual = ChecksumChecker::cs8(&_message[0], _headSize + bodySize() - 2);
            /*Types::u1 actual = ChecksumChecker::cs8(_id.c_str(), 2);
            actual = ChecksumChecker::cs8(_bodyLenStr.c_str(), 3, actual);
            if (bodySize() > 2)
                actual = ChecksumChecker::cs8(body(), bodySize() - 2, actual);*/
            // check
            return expected == actual;
        }

        bool validateChecksum8bin() const
        {
            // expected
            if (bodySize() <= 1)
                throw Exception("Body too small.");
            Types::u1 expected = ((Types::u1*)body())[bodySize() - 1];
            // actual
            Types::u1 actual = ChecksumChecker::cs8(&_message[0], _headSize + bodySize() - 1);
            /*Types::u1 actual = ChecksumChecker::cs8(_id.c_str(), 2);
            actual = ChecksumChecker::cs8(_bodyLenStr.c_str(), 3, actual);
            if (bodySize() > 2)
                actual = ChecksumChecker::cs8(body(), bodySize() - 1, actual);*/
            // check
            return expected == actual;
        }

    private:
        vector<char> _message; // Id&Len&Body
    protected:
        static const int _headSize = 5;
    };

    /*********************** General Purpose Messages **************************/

    // File Identifier
    class JPStdMessage_t : public StdMessage_t
    {
    public:
        SHARED_PTR_T(JPStdMessage_t);
        NULL_PTR_DECL;

        JPStdMessage_t(char* p_message, int p_length) : StdMessage_t(p_message, p_length, JPStdMessage),
            _fileTypeId(p_message + _headSize, 5),
            _description(p_message + _headSize + 5, p_length - 5 - _headSize)
        {
            stringBoost::trim(_description);
        }

        virtual string toString() const
        {
            return StdMessage_t::toString("JPStdMessage");
        }

        virtual bool validate() const
        {
            bool good = StdMessage_t::validate() && 
                        bodySize() == expectedLength && 
                        fileTypeId() == javadGnssId;
            return good;
        }

        inline string fileTypeId() const { return _fileTypeId; }
        inline string description() const { return _description; }

        static const string javadGnssId;
        static const string javadGnssDescriptionFormat;
        static const int expectedLength = 85;
    protected:
        virtual string bodyToString() const
        {
            return fileTypeId() + description();
        }
    private:
        string _fileTypeId; // File type identifier
        string _description; // Human-readable stream description
    };

    // Messages Format
    class MFStdMessage_t : public StdMessage_t
    {
    public:
    	SHARED_PTR_T(MFStdMessage_t);
    	NULL_PTR_DECL;
    
    	MFStdMessage_t(char* p_message, int p_length) 
    		: StdMessage_t(p_message, p_length, MFStdMessage)
    	{
    		// init members here
    	}
    
    	virtual string toString() const
    	{
    		return StdMessage_t::toString("MFStdMessage");
        }

        virtual bool validate() const
        {
            bool good = StdMessage_t::validate() && bodySize() == expectedLength && validateChecksum8ascii();
            return good;
        }

        struct BodyStruct
        {
            Types::a1 id[2];        // JP identifier
            Types::a1 majorVer[2];  // Format major version as decimal (e.g., '01')
            Types::a1 minorVer[2];  // Format minor version as decimal
            Types::a1 order;        // Bytes order
                                    // '0' - LSB first
                                    // '1' - MSB first
            Types::a1 cs[2];        // Checksum formatted as hexadecimal
        };
        VALIDATE_TYPE_SIZE(BodyStruct, 9);
    
    	inline const BodyStruct* bodyStruct() const
        {
            return reinterpret_cast<const BodyStruct*>(body());
        }

        static const int expectedLength = 9;
    protected:
    	/*virtual string bodyToString() const
    	{
    		// return body as string definition
    	}*/
    private:
    	// members here
    };

    /*********************** Time Messages **************************/

    // Receiver Time
    class RTStdMessage_t : public StdMessage_t
    {
    public:
    	SHARED_PTR_T(RTStdMessage_t);
    	NULL_PTR_DECL;
    
    	RTStdMessage_t(char* p_message, int p_length) 
    		: StdMessage_t(p_message, p_length, RTStdMessage)
    	{
    		// init members here
    	}
    
    	virtual string toString() const
    	{
    		return StdMessage_t::toString("RTStdMessage");
    	}
    
    	virtual bool validate() const
    	{
    		bool good = StdMessage_t::validate() && bodySize() == expectedLength && validateChecksum8bin();
    		return good;
        }

        // static consts here
        static const int expectedLength = 5;
    	
    	struct BodyStruct
    	{
            Types::u4 tod; // Tr modulo 1 day (86400000 ms) [ms]
            Types::u1 cs; // Checksum
        };
    	VALIDATE_TYPE_SIZE(BodyStruct, expectedLength);
    	
    	// Member getters here
    	inline const BodyStruct* bodyStruct() const
    	{
    		return reinterpret_cast<const BodyStruct*>(body());
    	}
    protected:
    	/*virtual string bodyToString() const
    	{
    		// return body as string definition
    	}*/
    private:
    	// members here
    };

    /*
    // <Full name>
    class <NAME>StdMessage_t : public StdMessage_t
    {
    public:
        SHARED_PTR_T(<NAME>StdMessage_t);
        NULL_PTR_DECL;

        <NAME>StdMessage_t(char* p_data, int p_length) : StdMessage_t(<NAME>, p_length, <NAME>StdMessage)
        {
            // init members here
        }

        virtual string toString() const
        {
            return StdMessage_t::toString("<NAME>StdMessage");
        }

        // Member getters here

        // static consts here
    protected:
        virtual string bodyToString() const
        {
            // return body as string definition
        }
    private:
        // members here
    };
    */

    class StdMessageFactory_t
    {
    public:
        static StdMessage_t::Pointer_t Create(char* p_message, int p_length)
        {
            return StdMessage_t::Pointer_t(new StdMessage_t(p_message, p_length));
            /*EMessageType id = idToEnumMap(p_message);
            switch(id)
            {
            case JPStdMessage:
                return JPStdMessage_t::Pointer_t(new JPStdMessage_t(p_message, p_length));
            case MFStdMessage:
                return MFStdMessage_t::Pointer_t(new MFStdMessage_t(p_message, p_length));
            case RTStdMessage:
                return RTStdMessage_t::Pointer_t(new RTStdMessage_t(p_message, p_length));
            case UnknownStdMessage:
                return StdMessage_t::Pointer_t(new StdMessage_t(p_message, p_length));
            default:
                throw Exception("Invalid EMessageType value.");
            }*/
        }
    private:
        static EMessageType idToEnumMap(char* p_id)
        {
            typedef map<unsigned short,EMessageType> aMapType;
            static aMapType aMap;
            if (aMap.size() == 0)
            {
                aMap[CHAR2_TO_USHORT("JP")] = JPStdMessage;
                aMap[CHAR2_TO_USHORT("MF")] = MFStdMessage;
                aMap[CHAR2_TO_USHORT("~~")] = RTStdMessage;
            }
            aMapType::iterator it = aMap.find(CHAR2_TO_USHORT(p_id));
            return it != aMap.end() ? it->second : UnknownStdMessage;
        }
    };
}

#pragma pack(pop)

//VALIDATE_TYPE_SIZE(Isp2mRecord, 6);

#endif // GreisMessage_h__