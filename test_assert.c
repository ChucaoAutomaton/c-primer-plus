#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
void show() {
    assert(1 > 2);
    puts("look at my eyes");
}
int main() {
    _Static_assert(1 < 2, "haha");
    show();
    puts("a");
    return 0;
}