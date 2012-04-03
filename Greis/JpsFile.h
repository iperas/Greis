#ifndef JpsFile_h__
#define JpsFile_h__

#include "GreisMessageStream.h"
#include <vector>
#include <boost/utility.hpp>
#include "Epoch.h"
#include "ProjectBase/SmartPtr.h"
#include "StdMessages/RcvTimeStdMessage.h"
#include "StdMessages/RcvDateStdMessage.h"

namespace Greis
{
    class JpsFile : private boost::noncopyable
    {
    public:
        SMART_PTR_T(JpsFile);

        static JpsFile::UniquePtr_t FromFile(QString filename);

        inline const std::vector<Message::UniquePtr_t>& Head() const { return _head; }
        inline std::vector<Message::UniquePtr_t>& Head() { return _head; }
        inline const std::vector<Epoch::UniquePtr_t>& Body() const { return _body; }
        inline std::vector<Epoch::UniquePtr_t>& Body() { return _body; }

        QByteArray ToByteArray() const;

        JpsFile()
        {
        }
    private:

        inline static void updateTimePart( RcvTimeStdMessage* msg, QDateTime &dateTime )
        {
            dateTime.setTime(QTime().addMSecs(msg->Tod()));
        }

        inline static void updateDatePart( RcvDateStdMessage* msg, QDateTime &dateTime ) 
        {
            dateTime.setDate(QDate(msg->Year(), msg->Month(), msg->Day()));
        }

        std::vector<Message::UniquePtr_t> _head;
        std::vector<Epoch::UniquePtr_t> _body;
    };
}

#endif // JpsFile_h__