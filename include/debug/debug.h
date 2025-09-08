#include "types.h"
#include "reader.h"

#if !defined(_NLANG_DEBUG) && defined(_DEBUG)
#define _NLANG_DEBUG

#include <wchar.h>
#include <locale.h>

void nlang_pprint_reader(nlang_reader* reader);

#elif !defined(_NLANG_DEBUG) && !defined(_DEBUG)
#define _NLANG_DEBUG

#define nlang_pprint_reader(reader)

#endif
