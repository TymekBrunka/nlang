#include "parser_reading.h"
#include "utils/defines.h"
#include "utils/dyn_arrays.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char nlang_read_from_ctx(nlang_read_context *ctx) {
    char c;
    if (ctx->read_offset == ctx->write_offset) {
        if (ctx->type) {
            c = *ctx->context.string;
            ctx->context.string++;
        } else {
            c = fread(&c, 1, 1, ctx->context.file);
        }
        return c;
    }

    c = *ctx->read_offset;
    ctx->read_offset++;
    return c;
}

char nlang_read_from_ctx_copying(nlang_read_context *ctx) {
    char c;
    if (ctx->read_offset == ctx->write_offset) {
        if (ctx->type) {
            c = *ctx->context.string;
            ctx->context.string++;
        } else {
            c = fread(&c, 1, 1, ctx->context.file);
        }
        *ctx->write_offset = c;
        ctx->write_offset++;
        return c;
    }

    c = *ctx->read_offset;
    // ctx->buf_offset--;
    return c;
}

void nlang_fill_ctx_kw_buf(nlang_read_context *ctx) {
    char c;
    for (; ctx->write_offset < ctx->kw_buf + NLANG_KWBL - 1; ctx->write_offset++) {
        if (ctx->type) {
            c = *ctx->context.string;
            ctx->context.string++;
        } else {
            c = fread(&c, 1, 1, ctx->context.file);
        }
        *ctx->write_offset = c;
    }
}

void nlang_fill_ctx_kw_buf_up_to(nlang_read_context *ctx, int length) {
    char c;
    for (; ctx->write_offset < ctx->kw_buf + length; ctx->write_offset++) {
        if (ctx->type) {
            c = *ctx->context.string;
            ctx->context.string++;
        } else {
            c = fread(&c, 1, 1, ctx->context.file);
        }
        *ctx->write_offset = c;
    }
}

// checked variant of method above, which can tell whether it read keyword or
// indentifier
nlang_token nlang_fill_ctx_kw_buf_up_to_checked(nlang_read_context *ctx, nlang_token_data_stream *tok_data_stream, int length) {
    char c;
    int8_t indent_length = 0;
    nlang_token tok = {.token = NLANG_PROCEED, .data_index = -1};

    for (; ctx->write_offset < ctx->kw_buf + length; ctx->write_offset++, indent_length++) {
        // read
        if (ctx->type) {
            c = *ctx->context.string;
            ctx->context.string++;
        } else {
            c = fread(&c, 1, 1, ctx->context.file);
        }
        *ctx->write_offset = c;

        // check
        if (c == '!' ||
            c == '=' ||
            c == '<' ||
            c == '>' ||
            c == '(' ||
            c == ')' ||
            c == '{' ||
            c == '}' ||
            c == ' ' ||
            c == '\0'
        ) {
            printf("activated, c = '%1s'\n", &c);

            printf("<next str: %s\n", ctx->context.string);
            printf("<cur kwbuf: %.*s\n", (int)(ctx->write_offset - ctx->read_offset), ctx->read_offset);

            // ctx->read_offset = ctx->write_offset;
            if (indent_length != 0) {
                nlang_ident_string str = {
                    .items = (char *)calloc(1, length),
                    .capacity = length,
                    .count = 0
                };
                // void* fix = &str;
                da_append_many(&str, ctx->kw_buf, length);
                da_append(tok_data_stream, &str);
            }

            tok.token = NLANG_IDENTIFIER;
            tok.data_index = indent_length > 0 ? tok_data_stream->count - 1 : -1;
            return tok;
        };

        // could be valid kw / ident
        if (c < 'a' && c > 'z' &&
            c < 'A' && c > 'Z' &&
            c < '0' && c > '9' &&
            (length > 0 && c >= '0' && c <= '9') && // both must start with a non-numeric character
            c != '_'
        ) {
            tok.token = NLANG_INVALID;
            return tok;
        }
    }

    // ctx->write_offset++;
    printf(">char#: %d\n", (int)indent_length);
    printf(">wof: %s\n", ctx->write_offset);
    printf(">rof: %s\n", ctx->read_offset);
    printf(">wof: %d\n", ctx->write_offset - ctx->kw_buf);
    printf(">rof: %d\n", ctx->read_offset - ctx->kw_buf);

    return tok;
}

void nlang_align_ctx_kw_buf(nlang_read_context *ctx) {
    char *end = ctx->kw_buf + NLANG_KWBL - 1;
    if (ctx->read_offset == ctx->kw_buf) {
        ctx->read_offset = ctx->kw_buf;
        return;
    }

    char *prev = ctx->kw_buf;
    char *next = ctx->read_offset;
    end = ctx->write_offset;
    for (; next <= end; prev++, next++) {
        *prev = *next;
    }
    ctx->write_offset -= ctx->read_offset - ctx->kw_buf;
    ctx->read_offset = ctx->kw_buf;
}

// void nlang_read_from_ctx_many(char* buf, nlang_read_context ctx, int length)
// {
//     for (int i = 0; i < length; i++) {
//         if (ctx->type) {
//              *buf = *ctx->context.string;
//             ctx->context.string++;
//         } else {
//             *buf = fread(buf, 1, 1, ctx->context.file);
//         }
//         if (*buf == '\0') break;
//         buf++;
//     }
// }

void nlang_clear_char_buf(char *buf, int length) {
    for (int i = 0; i < length; i++) {
        *buf = 0;
        buf++;
    }
}

nlang_read_context *nlang_create_read_context(bool type, char *str_or_fpath) {
    nlang_read_context *ctx = (nlang_read_context *)calloc(sizeof(nlang_read_context), 1);
    ctx->type = type;
    if (type) {
        ctx->context.string = str_or_fpath;
    } else {
        ctx->context.file = fopen(str_or_fpath, "r");
    }
    ctx->write_offset = ctx->kw_buf;
    ctx->read_offset = ctx->kw_buf;
    return ctx;
}
