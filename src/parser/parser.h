#include "utils/dyn_arrays.h"
#ifndef _nlang_parser
#define _nlang_parser

    typedef enum {
        N_INVALID = -1,
        N_EOF,
        N_INDENT,
        // N_NEWLINE,
        N_PARENTHESIS_OPEN,
        N_PARENTHESIS_CLOSE,
        N_BRACKET_OPEN,
        N_BRACKET_CLOSE,
        N_SINGLE_QUOTE,
        N_DOUBLE_QUOTE,
        
        N_FUNC,
        N_FUNC_PARAM_OPEN,
        N_FUNC_PARAM_CLOSE,
        N_FUNC_PARAM_DECL_OPEN,
        N_FUNC_PARAM_DECL_CLOSE,
    } TOKEN;

    TOKEN nlang_get_token();

#endif
