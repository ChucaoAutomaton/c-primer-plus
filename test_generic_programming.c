#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAP(x) _Generic(x, double : 0, int : 1)

void showDouble() {
    puts("it is double!");
}

void showIntergrater() {
    puts("it is int!");
}

typedef void (*my_pointer)(int c);

int main() {
    my_pointer *arr = (my_pointer *)calloc(2, sizeof(my_pointer));
    arr[0] = showDouble;
    arr[1] = showIntergrater;
    arr[MAP(0)](0);
    arr[MAP(1.0)](1.0);
}