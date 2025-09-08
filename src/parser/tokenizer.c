#include "parser/tokenizer.h"
#include "reader_internal.h"

nlang_token nlang_get_token(nlang_reader* reader, nlang_read_context* ctx) {
    nlang_token tok = {NLANG_PROCEED, 0};
    int catch;
    if (nlang_read_char(reader, ctx) == 1) {
        tok.token = NLANG_EOF;
        return tok;
    }

    switch (reader->contents.items[reader->read_index]) {

        case '{': {
            tok.token = NLANG_BRACKET_OPEN;
            return tok;
        }

        case '}': {
            tok.token = NLANG_BRACKET_CLOSE;
            return tok;
        }

        case '(': {
            tok.token = NLANG_PARENTHESIS_OPEN;
            return tok;
        }

        case ')': {
            tok.token = NLANG_PARENTHESIS_OPEN;
            return tok;
        }

        case '!': {
            catch = nlang_read_char(reader, ctx);
            char c = reader->contents.items[reader->read_index];
            if (c == '=') {
                tok.token = NLANG_NOT_EQUALS;
                return tok;
            } else {
                reader->read_index--;
            }
        }

    }

    return tok;
}
