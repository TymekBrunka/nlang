#include "types.h"
#ifndef _nlang_token_printer
#define _nlang_token_printer

extern char* NLANG_TOKEN_NAMES[sizeof(NLANG_TOKEN_TYPE) * 16];

#define nlang_get_token_name(tok) NLANG_TOKEN_NAMES[(tok) + 1] + 6 //6 is length of "NLANG"

#endif
