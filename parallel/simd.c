#include <stdio.h>
#include <stdlib.h>
#include <x86intrin.h>

void print128_num(__m128i var) {
    int* val = (int*) &var;
    printf("Numerical: \t%d\t%d\t%d\t%d\n", val[0], val[1], val[2], val[3]);
}

static int product(int n, int* a) {
    int result[4];
    __m128i prod_v = _mm_set_epi32(1, 1, 1, 1);
    for (int i = 0; i < n / 4 * 4; i += 4) {
        prod_v = _mm_mullo_epi32(prod_v, _mm_loadu_si128((__m128i*) (a + i)));
        print128_num(prod_v);
    }
    _mm_storeu_si128((__m128i*) result, prod_v);
    for (int i = n / 4 * 4; i < n; i++) {
        result[0] *= a[i];
    }
    return result[0] * result[1] * result[2] * result[3];
}

int main(int argc, char* argv[]) {
    int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("%d\n", product(9, a));
    return 0;
}
