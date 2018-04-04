#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

int main() {
    int i = 0;
    #pragma omp parallel for num_threads(2)
    for (i = 0; i < 5; i++) {
        sleep(i);
        printf("Thread %d, iteration %d\n", omp_get_thread_num(), i);
    }
    return 0;
}
