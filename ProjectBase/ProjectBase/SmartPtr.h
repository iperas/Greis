#ifndef SharedPtr_h__
#define SharedPtr_h__

#include <memory>

#define SMART_PTR_T(t) \
    typedef std::shared_ptr<##t> SharedPtr_t; \
    typedef std::unique_ptr<##t> UniquePtr_t;

#define NULL_PTR_DECL \
    static const SharedPtr_t sharedNullPtr; \
    static const UniquePtr_t uniqueNullPtr;

#define NULL_PTR_IMPL(t) \
    const t::SharedPtr_t t::sharedNullPtr = t::SharedPtr_t(); \
    const t::UniquePtr_t t::uniqueNullPtr = t::UniquePtr_t();

namespace ProjectBase
{
    /* 
    // uncomment when variadic templates will be implemented.
    template<typename T, typename... Args>
    std::unique_ptr<T> make_unique(Args&&... args)
    {
        return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
    }*/

    template<typename T>
    std::unique_ptr<T> make_unique()
    {
        return std::unique_ptr<T>(new T());
    }

    template<typename T, typename Arg1>
    std::unique_ptr<T> make_unique(Arg1&& arg1)
    {
        return std::unique_ptr<T>(new T(std::forward<Arg1>(arg1)));
    }

    template<typename T, typename Arg1, typename Arg2>
    std::unique_ptr<T> make_unique(Arg1&& arg1, Arg2&& arg2)
    {
        return std::unique_ptr<T>(new T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2)));
    }
}

#endif // SharedPtr_h__