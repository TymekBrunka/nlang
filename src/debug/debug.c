#include "debug/debug.h"
#include "string.h"

void nlang_pprint_reader(nlang_reader* reader) {
    char bg[60] = "░░░░░░░░░░░░░░░░░░░░";
    char content_items[60] = {0};
    char read_index[60] = {0};
    int length = reader->contents.count < 60 ? reader->contents.count : 60;

    strncpy(content_items, reader->contents.items, length);
    strncpy(content_items + length, bg + (length * 3), (20 - length) * 3);

    length = reader->contents.count < 60 ? reader->contents.count : 60;

    strncpy(read_index, reader->contents.items, length);
    strncpy(read_index + length, bg + (length * 3), (20 - length) * 3);

    printf(
        "┌──\x1b[32m READER \x1b[33m#%zu \x1b[0m────────────────────┐\n" \
        "│                                               │\n" \
        "│ \x1b[34mcontents\x1b[33m.items  \x1b[0m[20] = \x1b[33m[\x1b[32m%-.20s\x1b[33m]\x1b[0m │\n" \
        "│ \x1b[34mcontents\x1b[31m.length      \x1b[0m= \x1b[31m%-22zu\x1b[0m │\n" \
        "│ \x1b[34mcontents\x1b[31m.read_index  \x1b[0m= \x1b[31m%-22zu\x1b[0m │\n",
        (size_t)reader,
        content_items,
        reader->contents.count,
        reader->read_index
    );
}
