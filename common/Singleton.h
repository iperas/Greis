#ifndef SINGLETON_H
#define SINGLETON_H

#include <memory>
#include "SmartPtr.h"

namespace Common
{
    template<class T>
    class Singleton
    {
    public:
        static T& Instance()
        {
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
    friend class ::Common::Singleton<ClassName>;\
    ClassName(ClassName const&)=delete;\
    ClassName inline& operator=(ClassName const&) { return *this; }\
private:

#define SINGLETON_INSTANCE(ClassName) ::Common::Singleton<ClassName>::Instance()

#endif // SINGLETON_H
