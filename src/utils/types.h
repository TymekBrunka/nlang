#include <stddef.h>

#ifndef _nlang_types
#define _nlang_types

    typedef enum {
        NLANG_INVALID = -1,
        NLANG_PROCEED,
        NLANG_POT_SKIP,
        NLANG_EOF,
        NLANG_INDENT,
        NLANG_COMMENT,
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

        NLANG_EQUALS,
        NLANG_BANG,
        NLANG_NOT_EQUALS,
        NLANG_EQUALSEQUALS,
        NLANG_LESS_THAN,
        NLANG_MORE_THAN,
        NLANG_LESS_OR_EQUAL,
        NLANG_MORE_OR_EQUAL,

        NLANG_KW_IF,
        NLANG_KW_ELSE,
        NLANG_KW_ELSE_IF,
        NLANG_KW_WHILE,
        NLANG_KW_FOR,

        NLANG_KW_THIS,

        NLANG_KW_THAT,
        NLANG_KW_WHEN,
        NLANG_KW_DURING,
    } NLANG_TOKEN_TYPE;

    typedef struct {
        NLANG_TOKEN_TYPE token;
        int data_index;
    } nlang_token;

    typedef struct {
        const NLANG_TOKEN_TYPE *items;
        size_t count;
        size_t capacity;
    } nlang_token_stream;

    typedef struct {
        const void *items;
        size_t count;
        size_t capacity;
    } nlang_token_data_stream;

#endif
