// #include "reader.h"
#include "reader.h"

#ifndef _NLANG_READER_INTERNAL
#define _NLANG_READER_INTERNAL

    #define NLANG_MAX_KW_LEN 8

    //* reads extra n or code_readed_length characters to keep early returns while having quadratic growth
    //
    //* 1 = read attempt after end
    int nlang_read_request(nlang_reader* reader, nlang_read_context* ctx, int n);

    #define nlang_read_request_handled

    #define nlang_read_pointer reader->contents.items[reader->read_index]

#endif
