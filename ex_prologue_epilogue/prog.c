#include <stdio.h>

void foo(int x) {
    int a;
    a = x;
    printf("a = %d\n", a);
}

void bar() {
    int b = 5;
    foo(b);
}

int main() {
    bar();
    return 0;
}
