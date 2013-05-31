#include "Logger.h"

#include <QtCore/QtCore>
#include <iostream>

//apache log4cxx
#pragma warning(push)
#pragma warning(disable: 4231 4250)
//warning C4231: nonstandard extension used : 'extern' before template explicit instantiation	c:\libs\apache\apache-log4cxx-0.10.0\src\main\include\log4cxx\rolling\timebasedrollingpolicy.h	221	p2jbTestApp
//warning C4250: 'log4cxx::rolling::TimeBasedRollingPolicy' : inherits 'log4cxx::rolling::RollingPolicyBase::log4cxx::rolling::RollingPolicyBase::setOption' via dominance
/*#include <log4cxx/rolling/rollingfileappender.h>
#include <log4cxx/logger.h>
#include <log4cxx/consoleappender.h>
#include <log4cxx/logmanager.h>
#include <log4cxx/patternlayout.h>
#include <log4cxx/rolling/timebasedrollingpolicy.h>
#include <log4cxx/helpers/simpledateformat.h>
#include <log4cxx/helpers/stringhelper.h>
#include <log4cxx/xml/domconfigurator.h>*/
#pragma warning(pop)

namespace ProjectBase
{
    void Logger::Initialize(const QString& configFile)
    {
        //log4cxx::xml::DOMConfigurator::configure(configFile.toStdWString());
        //_logger = log4cxx::Logger::getRootLogger();
    }

    void Logger::Debug(const QString& message)
    {
    	std::cout << message.toStdString() << std::endl;
        //LOG4CXX_DEBUG(_logger, message.toStdWString());
    }

    void Logger::Trace(const QString& message)
    {
    	std::cout << message.toStdString() << std::endl;
        //LOG4CXX_TRACE(_logger, message.toStdWString());
    }

    void Logger::Info(const QString& message)
    {
    	std::cout << message.toStdString() << std::endl;
        //LOG4CXX_INFO(_logger, message.toStdWString());
    }

    void Logger::Warn(const QString& message)
    {
    	std::cout << message.toStdString() << std::endl;
        //LOG4CXX_WARN(_logger, message.toStdWString());
    }

    void Logger::Error(const QString& message)
    {
    	std::cout << message.toStdString() << std::endl;
        //LOG4CXX_ERROR(_logger, message.toStdWString());
    }

    void Logger::Fatal(const QString& message)
    {
    	std::cout << message.toStdString() << std::endl;
        //LOG4CXX_FATAL(_logger, message.toStdWString());
    }
}
