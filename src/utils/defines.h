#ifndef _nlang_defines
#define _nlang_defines

// *
//  slightly modified code from https://github.com/tsoding/nob.h/blob/main/nob.h
// *

#ifndef NLANG_ASSERT
#include <assert.h>
#define NLANG_ASSERT assert
#endif /* NLANG_ASSERT */

#ifndef NLANG_REALLOC
#include <stdlib.h>
#define NLANG_REALLOC realloc
#endif /* REALLOC */

#ifndef NLANG_FREE
#include <stdlib.h>
#define NLANG_FREE free
#endif /* FREE */

#ifndef DA_INIT_CAP
#define DA_INIT_CAP 256
#endif

#endif
