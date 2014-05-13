#include "Logger.h"

#include <QtCore/QtCore>
#include <iostream>

namespace ProjectBase
{
    void Logger::Initialize(int l)
    {
		if(l<0)l=5;
		this->LogLevel = l;
    }

    void Logger::Debug(const QString& message)
    {
		if (this->LogLevel>=5) 	std::cerr << message.toStdString() << std::endl;
    }

    void Logger::Trace(const QString& message)
    {
    	if (this->LogLevel>=4) 	std::cerr << message.toStdString() << std::endl;
    }

    void Logger::Info(const QString& message)
    {
    	if (this->LogLevel>=3) 	std::cerr << message.toStdString() << std::endl;
    }

    void Logger::Warn(const QString& message)
    {
    	if (this->LogLevel>=2) 	std::cerr << message.toStdString() << std::endl;
    }

    void Logger::Error(const QString& message)
    {
    	if (this->LogLevel>=1) 	std::cerr << message.toStdString() << std::endl;
    }

    void Logger::Fatal(const QString& message)
    {
    	if (this->LogLevel>=0) 	std::cerr << "FATAL:" << message.toStdString() << std::endl;
    }
}
