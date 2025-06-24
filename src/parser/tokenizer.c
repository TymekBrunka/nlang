#include "utils/dyn_arrays.h"
#include "tokenizer.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define nlang_kw(kw, token)                                \
    if (!strncmp(ctx->kw_buf, (kw), sizeof( (kw) ) - 1)) { \
        ctx->read_offset = ctx->kw_buf + sizeof( (kw) ) - 1;              \
        return (token);                                    \
    }

NLANG_TOKEN_TYPE nlang_get_token(nlang_read_context* ctx) {
    char c;
    // uint8_t offset = 0;
    
    // *(kw_buf + offset) = nlang_read_from_context(ctx);
    printf("kw_buf pre: %s\n", ctx->kw_buf);
    c = nlang_read_from_ctx_copying(ctx);
    printf("kw_buf: %s\n", ctx->kw_buf);

    switch (c) {
        case '!': {
            c = nlang_read_from_ctx(ctx);
            printf("co ty robisz: %s\n", ctx->kw_buf);
            if (c == '=') {
                ctx->read_offset++;
                return NLANG_NOT_EQUALS;
            } else {
                return NLANG_BANG;
            }
        }
        case '\0': return NLANG_EOF;
        case '(': return NLANG_PARENTHESIS_OPEN;
        case ')': return NLANG_PARENTHESIS_CLOSE;
        case '{': return NLANG_BRACKET_OPEN;
        case '}': return NLANG_BRACKET_CLOSE;
        case ' ': return NLANG_POT_SKIP;
    }

    nlang_fill_ctx_kw_buf(ctx);

    nlang_kw("if", NLANG_KW_IF);
    nlang_kw("for", NLANG_KW_FOR);
    nlang_kw("this", NLANG_KW_WHILE);
    nlang_kw("that", NLANG_KW_WHILE);
    nlang_kw("when", NLANG_KW_WHILE);
    nlang_kw("while", NLANG_KW_WHILE);
    nlang_kw("during", NLANG_KW_WHILE);
    nlang_kw("else if", NLANG_KW_ELSE_IF);
    nlang_kw("else", NLANG_KW_ELSE);

    return NLANG_INVALID;
}
