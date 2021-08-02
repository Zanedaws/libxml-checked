#if !defined __checkedc || defined NO_IMPLICIT_INCLUDE_CHECKED_HDRS

#ifdef __checkedc
#pragma CHECKED_SCOPE push
#pragma CHECKED_SCOPE off
#endif

#include_next <chvalid.h>

#ifdef __checkedc
#pragma CHECKED_SCOPE pop
#endif

#else // checkedc && implicit include enabled
#include <chvalid_checked.h>
#endif

