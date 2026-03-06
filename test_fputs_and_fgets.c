#include <stdio.h>
#define MAXN 5
int main() {
    char s[MAXN];
    while(fgets(s, MAXN, stdin) != NULL) {
        fputs(s, stdout);
    }
    return 0;
}