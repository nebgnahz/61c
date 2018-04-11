#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
#pragma omp parallel for schedule(dynamic) num_threads(2)
    for (int i = 0; i < 4; i++) {
        int id = omp_get_thread_num();
        printf("thread %d, i = %d\n", id, i);
    }
    return 0;
}
