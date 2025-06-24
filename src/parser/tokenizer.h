#include "utils/dyn_arrays.h"
#include "utils/parser_reading.h"
#include "utils/types.h"
#include <stdint.h>
#include <string.h>
#include "stdbool.h"
#ifndef _nlang_parser
#define _nlang_parser

    NLANG_TOKEN_TYPE nlang_get_token(nlang_read_context* ctx);
    nlang_token_stream nlang_get_token_stream(nlang_read_context* ctx);

#endif
