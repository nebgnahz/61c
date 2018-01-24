#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int main() {
    int (*fp)(int, int) = add;
    printf("1 + 1 = %d, %p\n", (*fp)(1, 1), fp);

    fp = sub;
    printf("2 - 1 = %d, %p\n", (*fp)(2, 1), fp);

    return 0;
}
