#include "parser_reading.h"
#include <stdio.h>

char nlang_read_from_ctx(nlang_read_context* ctx) {
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

char nlang_read_from_ctx_copying(nlang_read_context* ctx) {
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

void nlang_fill_ctx_kw_buf(nlang_read_context* ctx) {
    char c;
    for (;ctx->write_offset < ctx->kw_buf + NLANG_KWBL - 1; ctx->write_offset++) {
        if (ctx->type) {
            c = *ctx->context.string;
            ctx->context.string++;
        } else {
            c = fread(&c, 1, 1, ctx->context.file);
        }
        *ctx->write_offset = c;
    }
}

void nlang_align_ctx_kw_buf(nlang_read_context* ctx) {
    if (ctx->read_offset == ctx->kw_buf || ctx->read_offset == ctx->kw_buf + NLANG_KWBL - 1) {
        ctx->read_offset = 0;
        return;
    }

    char* prev = ctx->kw_buf;
    char* next = ctx->read_offset;
    char* end = ctx->write_offset;
    for (;next <= end; prev++, next++) {
        *prev = *next;
    }
    ctx->read_offset = ctx->kw_buf;
    ctx->write_offset -= ctx->read_offset - ctx->kw_buf;
}

// void nlang_read_from_ctx_many(char* buf, nlang_read_context ctx, int length) {
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

void nlang_clear_char_buf(char* buf, int length) {
    for (int i = 0; i < length; i++) {
        *buf = 0;
        buf++;
    }
}

nlang_read_context* nlang_create_read_context(bool type, char* str_or_fpath) {
    nlang_read_context* ctx = (nlang_read_context*)calloc(sizeof(nlang_read_context), 1);
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
