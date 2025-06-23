#include "utils/dyn_arrays.h"
#include "utils/read_ctx.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "stdbool.h"
#ifndef _nlang_parser
#define _nlang_parser

    typedef enum {
        NLANG_INVALID = -1,
        NLANG_PROCEED,
        NLANG_EOF,
        NLANG_INDENT,
        // NLANG_NEWLINE,
        NLANG_PARENTHESIS_OPEN,
        NLANG_PARENTHESIS_CLOSE,
        NLANG_BRACKET_OPEN,
        NLANG_BRACKET_CLOSE,
        NLANG_SINGLE_QUOTE,
        NLANG_DOUBLE_QUOTE,
        
        NLANG_FUNC,
        NLANG_INDENTIFIER,
        NLANG_FUNC_PARAM_OPEN,
        NLANG_FUNC_PARAM_CLOSE,
        NLANG_FUNC_PARAM_DECL_OPEN,
        NLANG_FUNC_PARAM_DECL_CLOSE,

        NLANG_KW_IF,
        NLANG_KW_ELSE,
        NLANG_KW_ELSE_IF,
        NLANG_KW_WHILE,
        NLANG_KW_FOR,

        NLANG_KW_THIS,

        NLANG_KW_THAT,
        NLANG_KW_WHEN,
        NLANG_KW_DURING,
    } NLANG_TOKEN;

    typedef struct {
        const NLANG_TOKEN *items;
        size_t count;
        size_t capacity;
    } nlang_token_stream;

    NLANG_TOKEN nlang_get_token(nlang_read_context ctx);
    nlang_token_stream nlang_get_token_stream(nlang_read_context ctx);

#endif
