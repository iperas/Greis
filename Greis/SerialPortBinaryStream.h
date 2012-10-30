#pragma once

#include <boost/asio.hpp>
#include <vector>
#include <QtCore/QtCore>

#include "IBinaryStream.h"

namespace Greis
{
    class SerialPortBinaryStream : public IBinaryStream
    {
    private:
        boost::asio::io_service _io;
        boost::asio::serial_port _serial;

        QByteArray _peekedData;
    public:
        SMART_PTR_T(SerialPortBinaryStream);
        
        /**
         * Constructor.
         * \param portName device name, example "/dev/ttyUSB0" or "COM4"
         * \param baudRate communication speed, example 9600 or 115200
         * \throws boost::system::system_error if cannot open the
         * serial device
         */
        SerialPortBinaryStream(std::string portName, unsigned int baudRate) : _io(), _serial(_io, portName)
        {
            _serial.set_option(boost::asio::serial_port_base::baud_rate(baudRate));
        }

        void write(QByteArray data)
        {
            boost::asio::write(_serial, boost::asio::buffer(data.data(), data.size()));
        }

        QByteArray read(qint64 maxlen)
        {
            QByteArray data(maxlen, 0);

            size_t read = boost::asio::read(_serial, boost::asio::buffer(data.data(), data.size()));
            data.resize(read);
            data = _peekedData + data;
            _peekedData.clear();
            return data;
        }

        QByteArray peek(qint64 maxlen)
        {
            return _peekedData = read(maxlen);
        }

        qint64 read(char * data, qint64 maxSize)
        {
            qint64 read = 0;
            if (_peekedData.size() > 0)
            {
                memcpy(data, _peekedData.data(), _peekedData.size());
                maxSize -= _peekedData.size();
                read += _peekedData.size();
                _peekedData.clear();
            }

            read += boost::asio::read(_serial, boost::asio::buffer(data, maxSize));
            return read;
        }

        qint64 peek(char * data, qint64 maxSize)
        {
            QByteArray buf(maxSize, 0);
            qint64 read = boost::asio::read(_serial, boost::asio::buffer(buf.data(), buf.size()));
            memcpy(data, _peekedData.data(), _peekedData.size());
            return read;
        }
    };
}
