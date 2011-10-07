#ifndef SINGLETON_H
#define SINGLETON_H

//#define MT_SUPPORT_BOOST
#define SHAREDPTR_QT

#ifdef SHAREDPTR_BOOST
#include <boost/shared_ptr.hpp>
#endif
#ifdef SHAREDPTR_QT
#include <QSharedPointer>
#endif
#ifdef MT_SUPPORT_BOOST
#include <boost/thread/thread.hpp>
#endif

namespace Util
{
    template<class T>
    class Singleton
    {
    public:
        static T& Instance()
        {
#ifdef MT_SUPPORT_BOOST
            static boost::mutex _mutex;
            boost::mutex::scoped_lock scoped_lock(_mutex);
#endif
#ifdef SHAREDPTR_BOOST
            static boost::shared_ptr<T> _impl;
            if (!_impl.get())
            {
                _impl.reset(new T);
            }
            return *_impl.get();
#endif
#ifdef SHAREDPTR_QT
            static QSharedPointer<T> _impl;
            if (_impl.isNull())
            {
                _impl = QSharedPointer<T>(new T);
            }
            return *_impl;
#endif
        }
    private:
        Singleton(const Singleton&);
        Singleton& operator=(const Singleton&);
    };
}

#define SINGLETON_BLOCK(ClassName)\
protected:\
    friend class ::Util::Singleton<ClassName>;\
    ClassName(ClassName const&) {}\
    ClassName inline& operator=(ClassName const&) { return *this; }\
private:

#define SINGLETON_INSTANCE(ClassName) ::Util::Singleton<ClassName>::Instance()

#endif // SINGLETON_H
