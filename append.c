#include<stdio.h>
#include<stdlib.h>
#define MAX_LEN 50
#define BUF_LEN 4096

int main() {
    puts("Enter name of destination file:");
    char *p_dest_file_name = (char *)calloc(MAX_LEN + 1, sizeof (char));
    char *p_src_file_name = (char *)calloc(MAX_LEN + 1, sizeof (char));
    fscanf(stdin, "%50s", p_dest_file_name);
    FILE *out = fopen(p_dest_file_name, "ab");
    if (out == NULL) {
        fprintf(stderr, "Can't open the file %s!\n", p_dest_file_name);
        free(p_dest_file_name);
        free(p_src_file_name);
        exit(EXIT_FAILURE);
    }

    if(setvbuf(out, NULL, _IOFBF, BUF_LEN) != 0) {
        puts("Can't create the buffer!");
        free(p_dest_file_name);
        free(p_src_file_name);
        exit(EXIT_FAILURE);
    }


    while (1) {
        puts("Enter name of source file(Enter # to quit):");
        fscanf(stdin, "%50s", p_src_file_name);
        
        if (p_src_file_name[0] == '#') {
            break;
        }

        FILE *in = fopen(p_src_file_name, "rb");
        if (in == NULL) {
            fprintf(stderr, "Can't open this file %s! Please input the correct file name\n", p_src_file_name);
            continue;
        }

        if (setvbuf(in, NULL, _IOFBF, BUF_LEN) != 0) {
            puts("Can't create the buffer!");
            free(p_dest_file_name);
            free(p_src_file_name);
            exit(EXIT_FAILURE);
        }

        int cnt;
        static char tmp[MAX_LEN];
        while ((cnt = fread(tmp, sizeof (char), BUF_LEN, in)) != 0) {
            fwrite(tmp, sizeof (char), cnt, out);
        }
        
        if(fclose(in) != 0) {
            fscanf(stderr, "Can't close the %s!\n", p_src_file_name);
            free(p_dest_file_name);
            free(p_src_file_name);
            exit(EXIT_FAILURE);
        }
        puts("Successfully!");
    }

    puts("Completed");
    free(p_dest_file_name);
    free(p_src_file_name);
    if(fclose(out) != 0) {
        fscanf(stderr, "Can't close the %s!\n", p_dest_file_name);
        exit(EXIT_FAILURE);
    }
    return 0;
}