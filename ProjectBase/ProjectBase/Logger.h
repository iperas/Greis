#ifndef Logger_h__
#define Logger_h__

#include "Singleton.h"
#include <boost/utility.hpp>
#include <log4cxx/logger.h>
#include <log4cxx/log4cxx.h>
#include <QtCore/QString>

namespace ProjectBase
{
    class Logger : boost::noncopyable
    {
        SINGLETON_BLOCK(Logger)
    private:
        log4cxx::LoggerPtr _logger;
    public:
        Logger() {}

        void Initialize(const QString& configFile);

        void Debug(const QString& message);
        void Trace(const QString& message);
        void Info(const QString& message);
        void Warn(const QString& message);
        void Error(const QString& message);
        void Fatal(const QString& message);
    };
}

#define sLogger SINGLETON_INSTANCE(::ProjectBase::Logger)

#endif // Logger_h__
