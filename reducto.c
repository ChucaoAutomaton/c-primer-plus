#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main (int argc, char *argv[]){
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
    }
    else {
        FILE *in, *out;
        int ch, cnt = 0;
        in = fopen(argv[1], "r");
        if (in == NULL) {
            fprintf(stderr, "I couldn't open the file \"%s\"!\n", argv[1]);
            exit(EXIT_FAILURE);
        }
        int len = strlen(argv[1]);
        char *new_file_name = (char *)calloc(len + 5, sizeof (char));
        sprintf(new_file_name, "%s", argv[1]);
        strcpy(new_file_name + len, ".red");
        out = fopen(new_file_name, "w");
        if (out == NULL) {
            fprintf(stderr, "Can't create output file.\n");
            free(new_file_name);
            exit(EXIT_FAILURE);
        }
        free(new_file_name);
        while ((ch = getc(in)) != EOF) {
            if (cnt % 3 == 0) {
                putc(ch, out);
            }
            cnt++;
        }
        if (fclose(in) != 0 || fclose(out) != 0) {
            fprintf(stderr, "Can't close the file.\n");
        }
        fprintf(stdout, "Completed!");
        return 0;
    }
}