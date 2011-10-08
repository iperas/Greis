#ifndef SharedPtr_h__
#define SharedPtr_h__

#include <boost/shared_ptr.hpp>

#define SHARED_PTR_T(t) typedef boost::shared_ptr<##t> Pointer_t;
#define SHARED_PTR_NEW(t) t::Pointer_t(new t());
#define NULL_PTR_DECL static const Pointer_t null_ptr;
#define NULL_PTR_IMPL(t) const t::Pointer_t t::null_ptr = t::Pointer_t();

#endif // SharedPtr_h__