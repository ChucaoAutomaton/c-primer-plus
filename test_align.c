#include<stdio.h>
#include<stdlib.h>
int main () {
    double d1 = 0;
    char c1 = 0;
    char c2 = 0;
    double d2 = 0;
    char c3 = 0;
    char _Alignas(double) c4 = 0;
    typedef unsigned int ui;
    printf("Alignof(char) = %zd\n", _Alignof(char));
    printf("Alignof(double) = %zd\n", _Alignof(double));
    printf("&d1 = %p, %d\n", &d1, 0);
    printf("&c1 = %p, %d\n", &c1, (int)(&c1) - (int)(&d1));
    printf("&c2 = %p, %d\n", &c2, (int)(&c2) - (int)(&c1));
    printf("&d2 = %p, %d\n", &d2, (int)(&d2) - (int)(&c2));
    printf("&c3 = %p, %d\n", &c3, (int)(&c3) - (int)(&d2));
    printf("&c4 = %p, %d\n", &c4, (int)(&c4) - (int)(&c3));
}