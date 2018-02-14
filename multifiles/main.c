#include <stdio.h>

#include "add.h"
#include "sub.h"
#include "mul.h"

int main() {
    printf("1 + 1 = %d\n", add(1, 1));
    printf("2 - 1 = %d\n", sub(2, 1));
    printf("2 * 1 = %d\n", mul(2, 1));
    return 0;
}
