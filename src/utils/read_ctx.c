#include "read_ctx.h"

char nlang_read_from_ctx(nlang_read_context ctx) {
    char c;
    if (ctx.type) {
         c = *ctx.context.string;
        ctx.context.string++;
    } else {
        c = fread(&c, 1, 1, ctx.context.file);
    }
    return c;
}

void nlang_read_from_ctx_many(char* buf, nlang_read_context ctx, int length) {
    for (int i = 0; i < length; i++) {
        if (ctx.type) {
             *buf = *ctx.context.string;
            ctx.context.string++;
        } else {
            *buf = fread(buf, 1, 1, ctx.context.file);
        }
        if (*buf == '\0') break;
        buf++;
    }
}

void nlang_clear_buf(char* buf, int length) {
    for (int i = 0; i < length; i++) {
        *buf = 0;
        buf++;
    }
}
