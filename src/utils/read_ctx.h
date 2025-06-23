#include "stdio.h"
#include "stdbool.h"

#ifndef _nlang_read_ctx
#define _nlang_read_ctx

    typedef struct {
        union {
            FILE* file;
            char* string;
        } context;
        bool type;
    } nlang_read_context;

    char nlang_read_from_ctx(nlang_read_context ctx);
    void nlang_read_from_ctx_many(char* buf, nlang_read_context ctx, int length);
    void nlang_clear_buf(char* buf, int length);

#endif
