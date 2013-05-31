#ifndef SINGLETON_H
#define SINGLETON_H

//#define MT_SUPPORT_BOOST

#include <memory>
#include <boost/utility.hpp>
#ifdef MT_SUPPORT_BOOST
#include <boost/thread/thread.hpp>
#endif
#include "ProjectBase/SmartPtr.h"

namespace ProjectBase
{
    template<class T>
    class Singleton : boost::noncopyable
    {
    public:
        static T& Instance()
        {
#ifdef MT_SUPPORT_BOOST
            static boost::mutex _mutex;
            boost::mutex::scoped_lock scoped_lock(_mutex);
#endif
            static std::unique_ptr<T> _impl;
            if (!_impl.get())
            {
                _impl = make_unique<T>();
            }
            return *_impl.get();
        }
    private:
        Singleton(const Singleton&);
        Singleton& operator=(const Singleton&);
    };
}

#define SINGLETON_BLOCK(ClassName)\
protected:\
    friend class ::ProjectBase::Singleton<ClassName>;\
    ClassName(ClassName const&) {}\
    ClassName inline& operator=(ClassName const&) { return *this; }\
private:

#define SINGLETON_INSTANCE(ClassName) ::ProjectBase::Singleton<ClassName>::Instance()

#endif // SINGLETON_H
