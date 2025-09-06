#include "types.h"

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#ifndef _NLANG_READER
#define _NLANG_READER

    typedef enum {
        NLANG_READER_STRING,
        NLANG_READER_FILE
    } NLANG_READER_TYPE;

    typedef struct {
        NLANG_READER_TYPE type;
        union {
            char* string;
            FILE* file;
        } context;
    } nlang_read_context;

    typedef struct {
        nlang_string contents;
        char* read_pointer;
    } nlang_reader;

    //* 1 = read attempt after end
    int nlang_read_char(nlang_reader* reader, nlang_read_context* ctx);

    int nlang_read_chars_many(nlang_reader* reader, nlang_read_context* ctx, int n);

    nlang_read_context nlang_create_read_context(void* filepath_or_string, NLANG_READER_TYPE type);

    nlang_reader nlang_create_reader();

#endif
