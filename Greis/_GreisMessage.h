#ifndef GreisMessage_h__
#define GreisMessage_h__

#include "ProjectBase/Macro.h"
#include "ProjectBase/SmartPtr.h"
#include "ProjectBase/InvalidOperationException.h"
#include <cassert>
#include <string>
#include <vector>
#include <map>
#include <boost/algorithm/string.hpp>
#include "GreisTypes.h"

#include <boost/format.hpp>
#include <QtXml/QtXml>
#include "ProjectBase/File.h"
#include "ProjectBase/Logger.h"

using std::string;
using std::vector;
using std::map;

using namespace ProjectBase;

namespace stringBoost = boost::algorithm;

#pragma pack (push, 1)

#define CHAR2_TO_USHORT(c_id) ((((unsigned short)(c_id)[0]) << 8) | (c_id)[1])

namespace Greis
{
    /*********************** General Purpose Messages **************************/

    // File Identifier
    /*class JPStdMessage_t : public StdMessage_t
    {
    public:
        SMART_PTR_T(JPStdMessage_t);
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
    	SMART_PTR_T(MFStdMessage_t);
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
    private:
    	// members here
    };

    /@*********************** Time Messages **************************@/

    // Receiver Time
    class RTStdMessage_t : public StdMessage_t
    {
    public:
    	SMART_PTR_T(RTStdMessage_t);
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
    private:
    	// members here
    };

    class StdMessageFactory_t
    {
    public:
        static StdMessage_t::SharedPtr_t Create(char* p_message, int p_length)
        {
            return StdMessage_t::SharedPtr_t(new StdMessage_t(p_message, p_length));
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
    };*/
}

#pragma pack(pop)

//VALIDATE_TYPE_SIZE(Isp2mRecord, 6);

#endif // GreisMessage_h__