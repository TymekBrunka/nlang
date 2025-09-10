#include "debug/debug.h"
#include "string.h"

void nlang_pprint_reader(nlang_reader* reader) {
    char bg[20] = "~~~~~~~~~~~~~~~~~~~~";
    char content_items[20] = {0};
    char read_index[20] = {0};
    int length = reader->contents.count < 20 ? reader->contents.count : 20;

    memcpy(content_items, bg, 20);
    memcpy(content_items, reader->contents.items + reader->contents.count - length, length);

    length = reader->contents.count - reader->read_index < 20 ? reader->contents.count - reader->read_index : 20;

    memcpy(read_index, bg, 20);
    memcpy(read_index, reader->contents.items + reader->read_index, length);

    printf(
        "+---\x1b[32m READER \x1b[33m#%zu \x1b[0m------------------------+\n" \
        "|                                                    |\n" \
        "| \x1b[34mcontents\x1b[33m.items       \x1b[0m[20] = \x1b[33m[\x1b[32m%-.20s\x1b[33m]\x1b[0m |\n" \
        "| \x1b[34mcontents\x1b[33m.read_index^ \x1b[0m[20] = \x1b[33m[\x1b[32m%-.20s\x1b[33m]\x1b[0m |\n" \
        "| \x1b[34mcontents\x1b[31m.read_index       \x1b[0m= \x1b[31m%-22zu\x1b[0m |\n" \
        "| \x1b[34mcontents\x1b[31m.count            \x1b[0m= \x1b[31m%-22zu\x1b[0m |\n" \
        "| \x1b[34mcontents\x1b[31m.capacity         \x1b[0m= \x1b[31m%-22zu\x1b[0m |\n" \
        "+----------------------------------------------------+\n"
        ,
        (uintptr_t)reader,
        content_items,
        read_index,
        reader->read_index,
        reader->contents.count,
        reader->contents.capacity
    );
}
