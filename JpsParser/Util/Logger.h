#ifndef Logger_h__
#define Logger_h__

#include "Util/Singleton.h"

//apache log4cxx
#pragma warning(push)
#pragma warning(disable: 4231 4250)
//warning C4231: nonstandard extension used : 'extern' before template explicit instantiation	c:\libs\apache\apache-log4cxx-0.10.0\src\main\include\log4cxx\rolling\timebasedrollingpolicy.h	221	p2jbTestApp
//warning C4250: 'log4cxx::rolling::TimeBasedRollingPolicy' : inherits 'log4cxx::rolling::RollingPolicyBase::log4cxx::rolling::RollingPolicyBase::setOption' via dominance
#include <log4cxx/rolling/rollingfileappender.h>
#include <log4cxx/logger.h>
#include <log4cxx/consoleappender.h>
#include <log4cxx/logmanager.h>
#include <log4cxx/patternlayout.h>
#include <log4cxx/rolling/timebasedrollingpolicy.h>
#include <log4cxx/helpers/simpledateformat.h>
#include <log4cxx/helpers/stringhelper.h>
#include <log4cxx/xml/domconfigurator.h>
#pragma warning(pop)

namespace Util
{
    class Logger
    {
        SINGLETON_BLOCK(Logger)
    private:
        log4cxx::LoggerPtr _logger;
    public:

        Logger() {}

        void Initialize(const QString& configFile)
        {
            log4cxx::xml::DOMConfigurator::configure(configFile.toStdWString());
            _logger = log4cxx::Logger::getRootLogger();
        }

        void Debug(const QString& message)
        {
            LOG4CXX_DEBUG(_logger, message.toStdWString());
        }

        void Trace(const QString& message)
        {
            LOG4CXX_TRACE(_logger, message.toStdWString());
        }

        void Info(const QString& message)
        {
            LOG4CXX_INFO(_logger, message.toStdWString());
        }

        void Warn(const QString& message)
        {
            LOG4CXX_WARN(_logger, message.toStdWString());
        }

        void Error(const QString& message)
        {
            LOG4CXX_ERROR(_logger, message.toStdWString());
        }

        void Fatal(const QString& message)
        {
            LOG4CXX_FATAL(_logger, message.toStdWString());
        }
    };
}

#define sLogger SINGLETON_INSTANCE(::Util::Logger)

#endif // Logger_h__