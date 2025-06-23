#include "stdio.h"
#include "parser/tokenizer.h"

nlang_read_context ctx = { .context.string = "hello", .type = true};

int main() {
    NLANG_TOKEN n = nlang_get_token(ctx);
    printf("%d\n", n);
}
