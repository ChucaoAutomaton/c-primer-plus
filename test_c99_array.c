#include <stdio.h>
#include <inttypes.h>
#include <conio.h>
int main() {
    int arr[] = {0, 1, 2, 3, [0] = 4, 5, 6};
    int sz = sizeof arr / sizeof arr[0];
    for (int i = 0; i < sz; i++) {
        printf("%d %d\n", i, arr[i]);
    }
    return 0;
}