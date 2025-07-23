#include "parser/tokenizer.h"
#define _nlang_token_printer_implementation
#include "utils/token_printer.h"
#include "stdio.h"

int main() {

    char string[] = "!!= if (else) if else while";

    nlang_read_context* ctx = nlang_create_read_context(true, string);
    nlang_token_data_stream* data_stream = {0}; 

    for (int i = 0; i < 14; i++) {
        printf("kw buf \x1b[32mpre\x1b[0m: '%s'\n", ctx->kw_buf);
        printf("to be read: '%s'\n", ctx->context.string);
        NLANG_TOKEN_TYPE n = nlang_get_token(ctx, data_stream);
        printf("kw buf \x1b[33mpost\x1b[0m: '%s'\n", ctx->kw_buf);
        printf("to be read: '%s'\n", ctx->context.string);
        printf("cur kwbuf: %.*s\n", (int)(ctx->write_offset - ctx->read_offset), ctx->read_offset);
        printf("  wof: %d\n", ctx->write_offset - ctx->kw_buf);
        printf("  rof: %d\n", ctx->read_offset - ctx->kw_buf);
        printf("\x1b[34m%s\x1b[0m\n", nlang_get_token_name(n));
        nlang_align_ctx_kw_buf(ctx);
    }
}
