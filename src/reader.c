#include "reader.h"
#include "utils/dyn_arrays.h"

#define can_read_from_itself reader->read_pointer < reader->contents.items

#define get_char_file()                         \
    if (feof(ctx->context.file)) {              \
        c = '\0';                               \
        ret = 1;                                \
    } else {                                    \
        c = fread(&c, 1, 1, ctx->context.file); \
    }

#define get_char_string()       \
    c = *ctx->context.string;   \
    ctx->context.string++;      \
    if (c == '\n') {            \
        ret = 1;                \
    }


int nlang_read_char(nlang_reader* reader, nlang_read_context* ctx) {
    char c;
    int ret = 0;

    if (can_read_from_itself) {
        reader->read_pointer++;
        return 0;
    }

    if (ctx->type == NLANG_READER_FILE) {
        get_char_file();
    } else {
        get_char_string();
    }

    da_append(&reader->contents, c);

    return ret;
}

int nlang_read_chars_many(nlang_reader* reader, nlang_read_context* ctx, int n) {
    char c;
    int ret = 0;
    if (ctx->type == NLANG_READER_FILE) {
        for (int i = 0; i < n - (reader->contents.items - reader->read_pointer) && ret == 0; i++) {
            get_char_file();
            da_append(&reader->contents, c);
        }
    } else {
        for (int i = 0; i < n - (reader->contents.items - reader->read_pointer) && ret == 0; i++) {
            get_char_string();
            da_append(&reader->contents, c);
        }
    }

    return ret;
}

nlang_read_context nlang_create_read_context(void* filepath_or_string, NLANG_READER_TYPE type) {
    nlang_read_context ctx = {0};

    ctx.type = type;
    if (type == NLANG_READER_FILE) {
        ctx.context.file = fopen(filepath_or_string, "r");
    } else {
        ctx.context.string = filepath_or_string;
    }

    return ctx;
}

nlang_reader nlang_create_reader() {
    nlang_reader reader = {0};
    reader.contents.items = calloc(256, 1);
    reader.contents.capacity = 256;
    reader.read_pointer = reader.contents.items;

    return reader;
}
