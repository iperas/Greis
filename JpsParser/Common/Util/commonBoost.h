#ifndef commonBoost_h__
#define commonBoost_h__

// foreach
//#include <boost/foreach.hpp>

//#define foreach BOOST_FOREACH

// format
/* USAGE:
 * cout << format("%1% %2% %3% %2% %1% \n") % "11" % "22" % "333"; // 'simple' style.
 * OR
 * cout << format("writing %s,  x=%s : %d-th step \n") % "toto" % 40.23 % 50;
 * OR
 * string msg = str( boost::format("Debug message %s") % some_msg_string );
 * OR
 * cout << format("(x,y) = (%1$+5d,%2$+5d) \n") % -23 % 35;     // Posix-Printf style
*/
#include <boost/format.hpp>

using boost::format;
using boost::wformat;
using boost::str;

// shared_ptr

#include <boost/shared_ptr.hpp>

#define SHARED_PTR_T(t) typedef boost::shared_ptr<##t> Pointer_t;
#define SHARED_PTR_CREATE(t) t::Pointer_t(new t());
#define NULL_PTR_DECL static const Pointer_t null_ptr;
#define NULL_PTR_IMPL(t) const t::Pointer_t t::null_ptr = t::Pointer_t();

#endif // commonBoost_h__