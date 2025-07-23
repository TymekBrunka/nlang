#include "stdbool.h"
#include "stdio.h"
#include <stdlib.h>

#include "types.h"

#ifndef _nlang_read_ctx
#define _nlang_read_ctx

#define NLANG_KWBL 8

// fifo queue of temporary characters read from specified context
typedef struct {
    union {
        FILE *file;
        char *string;
    } context;
    bool type;
    char kw_buf[NLANG_KWBL];
    char *read_offset;
    char *write_offset;
} nlang_read_context;

char nlang_read_from_ctx(nlang_read_context *ctx);
char nlang_read_from_ctx_copying(nlang_read_context *ctx);
void nlang_fill_ctx_kw_buf(nlang_read_context *ctx);
void nlang_fill_ctx_kw_buf_up_to(nlang_read_context *ctx, int length);
nlang_token nlang_fill_ctx_kw_buf_up_to_checked(nlang_read_context *ctx, nlang_token_data_stream *tok_data_stream, int length);
void nlang_align_ctx_kw_buf(nlang_read_context *ctx);
// void nlang_read_from_ctx_many(char* buf, nlang_read_context ctx, int length);
void nlang_clear_char_buf(char *buf, int length);

nlang_read_context *nlang_create_read_context(bool type, char *str_or_fpath);

#endif
