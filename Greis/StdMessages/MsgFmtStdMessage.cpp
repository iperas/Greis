#include "MsgFmtStdMessage.h"
#include <cassert>
#include "ChecksumComputer.h"
#include "ProjectBase/Logger.h"
#include <iostream>

namespace Greis
{
    MsgFmtStdMessage::MsgFmtStdMessage( const char* pc_message, int p_length ) 
        : _id(pc_message, 2), _bodySize(p_length - HeadSize())
    {
        char* p_message = const_cast<char*>(pc_message);
        
        p_message += HeadSize();
    
        _serializer.Deserialize(p_message, 2, _idField);
        p_message += 2;
        _serializer.Deserialize(p_message, 2, _majorVer);
        p_message += 2;
        _serializer.Deserialize(p_message, 2, _minorVer);
        p_message += 2;
        _serializer.Deserialize(p_message, _order);
        p_message += sizeof(_order);
        _serializer.Deserialize(p_message, 2, _cs);
        p_message += 2;

        _isCorrect = (p_message - pc_message == p_length);
        if (!_isCorrect)
        {
            sLogger.Debug(QString("The message %1 is incorrect. Excepted size is %2 whilst the actual size is %3.")
                .arg(QString::fromStdString(ToString())).arg(p_length).arg(p_message - pc_message));
        }
    }
    
    MsgFmtStdMessage::MsgFmtStdMessage( const std::string& p_id, int p_size ) 
        : _id(p_id), _bodySize(p_size - HeadSize())
    {
    }

    std::string MsgFmtStdMessage::ToString() const
    {
        return toString("MsgFmtStdMessage");
    }
    
    bool MsgFmtStdMessage::Validate() const
    {
        if (!_isCorrect || !StdMessage::Validate())
        {
			std::cout << "Trivial check failed! isCorrect:" << _isCorrect << std::endl;
            return false;
        }

        auto message = ToByteArray();
        return validateChecksum8Ascii(message.data(), message.size());
    }
    
    void MsgFmtStdMessage::RecalculateChecksum()
    {
        if (!_isCorrect)
        {
            return;
        }
        auto message = ToByteArray();
        auto cs = ChecksumComputer::ComputeCs8(message, message.size() - 1);
        auto ba = QString::number(cs, 16).toAscii();
        _cs[0] = ba[0]; _cs[1] = ba[1];
    }

    QByteArray MsgFmtStdMessage::ToByteArray() const
    {
        QByteArray result;
        if (!_isCorrect)
        {
            return result;
        }

        result.append(headToByteArray());

        _serializer.Serialize(_idField, result);
        _serializer.Serialize(_majorVer, result);
        _serializer.Serialize(_minorVer, result);
        _serializer.Serialize(_order, result);
        _serializer.Serialize(_cs, result);
        
        assert(result.size() == Size());
        return result;
    }
}
