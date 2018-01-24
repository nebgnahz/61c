#include <stdio.h>

void simple_pointer();
void pointer_arithmetic();
void danger();

int main() {
    // simple_pointer();
    // pointer_arithmetic();
    danger();
    return 0;
}

void simple_pointer() {
    int x = 0x61c;
    int y = 0x2A;
    int* p = &y;
    int** pp = &p;

    printf(" x: %x, address: %p\n", x, &x);
    printf(" y: %x, address: %p\n", y, &y);
    printf(" p: %p, address: %p => (%x)\n", p, &p, *p);
    printf("pp: %p, address: %p => (%p)\n", pp, &pp, *pp);
}

void pointer_arithmetic() {
    int x = 0x61c;
    int* p = &x;
    printf(" x: %x, address: %p\n", x, &x);
    printf(" p: %p, (p + 1): %p\n", p, (p + 1));
    printf(" p: %p, (p + 1): %p\n", p, ((char*) p + 1));
}

void danger() {
    int x = 0x61c;
    int* p = (int *) x;
    printf(" p: %p, address: %p => (%x)\n", p, &p, *p);
}
