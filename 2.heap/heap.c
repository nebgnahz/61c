#include <stdio.h>
#include <stdlib.h>

int main() {
    int c[3] = {1, 2, 3};

    int* p = (int*) malloc(3 * sizeof(int));
    // int* p = (int *) calloc(3, sizeof(int));

    if (p == NULL) {
        perror("failed to allocate memory on heap");
        exit(1);
    }

    printf("c[0](@%p) = %d\n", c, c[0]);
    printf("c[1](@%p) = %d\n", c + 1, c[1]);
    printf("c[2](@%p) = %d\n", c + 2, c[2]);

    printf("p[0](@%p) = %d\n", p, p[0]);
    printf("p[1](@%p) = %d\n", p + 1, p[1]);
    printf("p[2](@%p) = %d\n", p + 2, p[2]);

    free(p);
    return 0;
}
