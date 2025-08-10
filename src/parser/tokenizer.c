#include "tokenizer.h"
#include "utils/dyn_arrays.h"
#include <stdint.h>
#include <string.h>

#define nlang_fill_ctx_kw_buf_up_to_checked_and_return_if_incorrect(ctx, length)       \
    tok = nlang_fill_ctx_kw_buf_up_to_checked((ctx), data_stream, (length));           \
    printf("tok.token = %s\n", nlang_get_token_name(tok.token));                       \
    if (tok.token == NLANG_IDENTIFIER || tok.token == NLANG_INVALID) {                 \
        printf("detected: %s\n", tok.token == NLANG_IDENTIFIER ? "ident" : "invalid"); \
        return tok.token;                                                              \
    }

#define nlang_kw(kw, token)                                \
    if (!strncmp(ctx->kw_buf, (kw), sizeof((kw)) - 1)) {   \
        ctx->read_offset = ctx->kw_buf + sizeof((kw)) - 1; \
        return (token);                                    \
    } 

NLANG_TOKEN_TYPE nlang_get_token(nlang_read_context *ctx, nlang_token_data_stream* data_stream) {
    char c;
    // uint8_t offset = 0;

    // *(kw_buf + offset) = nlang_read_from_context(ctx);
    c = nlang_read_from_ctx_copying(ctx);
    ctx->read_offset++;

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
    case '<': {
        c = nlang_read_from_ctx_copying(ctx);
        if (c == '=') {
            ctx->read_offset++;
            return NLANG_LESS_OR_EQUAL;
        } else {
            return NLANG_LESS_THAN;
        }
    }
    case '>': {
        c = nlang_read_from_ctx_copying(ctx);
        if (c == '=') {
            ctx->read_offset++;
            return NLANG_MORE_OR_EQUAL;
        } else {
            return NLANG_MORE_THAN;
        }
    }
    case '\0':
        return NLANG_EOF;
    case '(': {
        return NLANG_PROCEED;
    }
    case ')': {
        return NLANG_PROCEED;
    }
    case '{': {
        return NLANG_PROCEED;
    }
    case '}': {
        return NLANG_PROCEED;
    }
    case ' ':
        return NLANG_POT_SKIP;
    }

    ctx->read_offset++;
    // nlang_fill_ctx_kw_buf(ctx);

    nlang_token tok = {0};

    nlang_fill_ctx_kw_buf_up_to_checked_and_return_if_incorrect(ctx, 3);
    nlang_kw("if", NLANG_KW_IF);
    nlang_kw("Ok", NLANG_KW_OK);
    nlang_kw("fn", NLANG_KW_FN);
    nlang_fill_ctx_kw_buf_up_to_checked_and_return_if_incorrect(ctx, 4);
    nlang_kw("Err", NLANG_KW_ERR);
    nlang_kw("for", NLANG_KW_FOR);
    nlang_kw("try", NLANG_KW_TRY);
    nlang_fill_ctx_kw_buf_up_to_checked_and_return_if_incorrect(ctx, 5);
    nlang_kw("else", NLANG_KW_ELSE);
    nlang_kw("this", NLANG_KW_THIS);
    nlang_kw("that", NLANG_KW_THAT);
    nlang_kw("when", NLANG_KW_WHEN);
    nlang_fill_ctx_kw_buf_up_to_checked_and_return_if_incorrect(ctx, 6);
    nlang_kw("while", NLANG_KW_WHILE);
    nlang_kw("catch", NLANG_KW_CATCH);
    nlang_kw("match", NLANG_KW_MATCH);
    nlang_fill_ctx_kw_buf_up_to_checked_and_return_if_incorrect (ctx, 7);
    nlang_kw("during", NLANG_KW_DURING);
    // nlang_fill_ctx_kw_buf_up_to(ctx, 7);

    return NLANG_INVALID;
}
