// #include "reader.h"
#include "reader.h"

#ifndef _NLANG_READER_INTERNAL
#define _NLANG_READER_INTERNAL

    #define NLANG_MAX_KW_LEN 8
    //* 1 = read attempt after end
    int nlang_read_char(nlang_reader* reader, nlang_read_context* ctx);

    int nlang_read_chars_many(nlang_reader* reader, nlang_read_context* ctx, int n);

    nlang_token nlang_read_for_token(nlang_reader* reader, nlang_read_context* ctx, int n);

#endif
