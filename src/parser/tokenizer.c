#include "utils/dyn_arrays.h"
#include "tokenizer.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define nlang_kw(kw, token)                                   \
    nlang_fill_ctx_kw_buf_up_to(ctx, sizeof(kw) - 1);             \
    if (!strncmp(ctx->kw_buf, (kw), sizeof( (kw) ) - 1)) {    \
        ctx->read_offset = ctx->kw_buf + sizeof( (kw) ) - 1;  \
        return (token);                                       \
    }

NLANG_TOKEN_TYPE nlang_get_token(nlang_read_context* ctx) {
    char c;
    // uint8_t offset = 0;
    
    // *(kw_buf + offset) = nlang_read_from_context(ctx);
    c = nlang_read_from_ctx(ctx);

    switch (c) {
        case '!': {
            c = nlang_read_from_ctx_copying(ctx);
            if (c == '=') {
                ctx->read_offset++;
                return NLANG_NOT_EQUALS;
            } else {
                return NLANG_BANG;
            }
        }
        case '=': {
            c = nlang_read_from_ctx_copying(ctx);
            if (c == '=') {
                ctx->read_offset++;
                return NLANG_EQUALSEQUALS;
            } else {
                return NLANG_EQUALS;
            }
        }
        case '\0': return NLANG_EOF;
        case '(': {
            ctx->read_offset--;
            return NLANG_PROCEED;
        }  
        case ')': {
            ctx->read_offset--;
            return NLANG_PROCEED;
        }  
        case '{': {
            ctx->read_offset--;
            return NLANG_PROCEED;
        }  
        case '}': {
            ctx->read_offset--;
            return NLANG_PROCEED;
        }  
        case ' ': return NLANG_POT_SKIP;
    }

    ctx->read_offset++;
    // nlang_fill_ctx_kw_buf(ctx);

    nlang_kw("if", NLANG_KW_IF);
    nlang_kw("Ok", NLANG_KW_OK);
    nlang_kw("Err", NLANG_KW_ERR);
    nlang_kw("fn ", NLANG_KW_FN);
    nlang_kw("for", NLANG_KW_FOR);
    nlang_kw("try", NLANG_KW_TRY);
    nlang_kw("this", NLANG_KW_THIS);
    nlang_kw("that", NLANG_KW_THAT);
    nlang_kw("when", NLANG_KW_WHEN);
    nlang_kw("while", NLANG_KW_WHILE);
    nlang_kw("catch", NLANG_KW_CATCH);
    nlang_kw("match", NLANG_KW_MATCH);
    nlang_kw("during", NLANG_KW_DURING);
    nlang_kw("else if", NLANG_KW_ELSE_IF);
    nlang_kw("else", NLANG_KW_ELSE);

    return NLANG_INVALID;
}
