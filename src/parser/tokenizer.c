#include "utils/dyn_arrays.h"
#include "tokenizer.h"
#include <string.h>
#include <stdint.h>
#include <stdio.h>

#define nlang_kw(kw, token)                                    \
    nlang_read_from_ctx_many(kw_buf, ctx, 8);                  \
    if (!strncmp(kw_buf, (kw), sizeof( (kw) ) - 1)) return (token);

NLANG_TOKEN nlang_get_token(nlang_read_context ctx) {
    char kw_buf[8] = {0};
    // uint8_t offset = 0;
    
    // *(kw_buf + offset) = nlang_read_from_context(ctx);
    kw_buf[0] = nlang_read_from_ctx(ctx);

    switch (kw_buf[0]) {
        case '\0': return NLANG_EOF;
        case '(': return NLANG_PARENTHESIS_OPEN;
        case ')': return NLANG_PARENTHESIS_CLOSE;
        case '{': return NLANG_BRACKET_OPEN;
        case '}': return NLANG_BRACKET_CLOSE;
    }

    nlang_kw("if", NLANG_KW_IF);
    nlang_kw("else", NLANG_KW_ELSE);
    nlang_kw("else if", NLANG_KW_ELSE_IF);
    nlang_kw("while", NLANG_KW_WHILE);
    nlang_kw("for", NLANG_KW_FOR);

    return NLANG_EOF;
}
