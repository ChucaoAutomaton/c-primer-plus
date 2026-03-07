#include<stdio.h>
#include<stdlib.h>
int main() {
    FILE *out = fopen("test_input.txt", "w");
    if (out == NULL) {
        fprintf(stderr, "Can't open the file!\n");
        exit(EXIT_FAILURE);
    }

    fpos_t cur, p;
    fgetpos(out, &p);

    for (int i = 0; i < 1000; i++) {
        putc('a' + (i % 26), out);
        fgetpos(out, &cur);
        fsetpos(out, &p);
        printf("%lld\n", cur);
    }
    fclose(out);
    return 0;
}