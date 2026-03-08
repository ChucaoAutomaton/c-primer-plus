#if __STDC_VERSION__ != 201710
#error Not C17
#endif

#include<stdio.h>
#include<stdlib.h>
#define STRING "a nb"
#define SHOW(x,y) printf(#x" think "STRING);for(int j = 0; j < (y); j++)putchar('!');putchar('\n');
#define MERGE(y) player##y
#define PR(X, ...) printf("Message "#X": "__VA_ARGS__);
#ifdef STRING
    #undef STRING
    #define STRING "genshin nb"
#endif
#ifndef OSHEN
    #define OSHEN "genshin doesn't nb"
#endif

#include "test_macro.h"
#include "test_macro.h"

int main () {
    int player, player1 = 1, player2 = 2, player3 = 3;
    printf("%d %d %d\n", MERGE(1), MERGE(2), MERGE(3));
    for (int i = 0; i < 3; i++) {
        SHOW(i, i + 1)
    }
    
    puts("===============");
    PR(1, "x = %lf\n", 49.0)
    PR(2, "x = %s\n", "ERROR")

    puts("===============");
    printf(OSHEN"\n");

    puts("===============");
    Node nd = {0, NULL};
    printf("%d %p\n", nd.v, nd.p);

    puts("===============");
    puts(__DATE__);
    puts(__FILE__);
    printf("%d\n%d\n%d\n%lld\n", __LINE__, __STDC__, __STDC_HOSTED__, __STDC_VERSION__);
    puts(__TIME__);
    puts(__func__);
}