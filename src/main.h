#if _WIN64 || __amd64__
#define PORTABLE_64_BIT
#else
#define PORTABLE_32_BIT
#endif

#ifdef GOLANG_LIB
#ifdef PORTABLE_64_BIT
#include "../goLib/goLib64.h"
#endif
#ifdef PORTABLE_32_BIT
#include "../goLib/goLib32.h"
#endif
#endif
