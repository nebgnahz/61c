#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
void danger();

int main() {
    danger();
    return 0;
}

void danger() {
    int x = 0x61c;
    int* p = x;
    printf(" p: %p, address: %p => (%x)\n", p, &p, *p);
}

char* get_user_input() {
    char buf[10];
    fgets(buf, 10, stdin);
    return buf;
}

void do_something_else() {
    char buf[10] = { 'x', 'y' };
}

int main2() {
    char* msg = get_user_input();
    do_something_else();
    printf("%c\n", msg[0]);
}
