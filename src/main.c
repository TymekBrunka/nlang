#include "stdio.h"
#include "parser/tokenizer.h"

int main() {

    char string[] = "!!=ifelse ifelsewhile";

    nlang_read_context* ctx = nlang_create_read_context(true, string);

    for (int i = 0; i < 6; i++) {
        NLANG_TOKEN_TYPE n = nlang_get_token(ctx);
        printf("kw buf: '%s'\n", ctx->kw_buf);
        printf("%d\n", n);
        nlang_align_ctx_kw_buf(ctx);
    }
}
