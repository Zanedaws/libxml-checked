#if !defined __checkedc || defined NO_IMPLICIT_INCLUDE_CHECKED_HDRS

#ifdef __checkedc
#pragma CHECKED_SCOPE push
#pragma CHECKED_SCOPE off
#endif

#include_next <c14n.h>

#ifdef __checkedc
#pragma CHECKED_SCOPE pop
#endif

#else // checkedc && implicit include enabled
#include <c14n_checked.h>
#endif

