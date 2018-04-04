#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

void openmp1();
void openmp2();
void openmp3();

int main() {
    // openmp1();
    //    openmp2();
    openmp3();
    return 0;
}

void openmp1() {
    #pragma omp parallel for num_threads(2)
    for (int i = 0; i < 4; i++) {
        // sleep(i);
        int id = omp_get_thread_num();
        printf("Thread %d, task %d\n", id, i);
    }
}

void openmp2() {
    #pragma omp parallel num_threads(2)
    {
        for (int i = 0; i < 4; i++) {
            printf("Thread %d, task %d\n", omp_get_thread_num(), i);
        }
    }
}

void openmp3() {
    // omp_set_nested(1);
    #pragma omp parallel num_threads(2)
    {
        #pragma omp parallel num_threads(2)
        {
            for (int i = 0; i < 4; i++) {
                printf("Thread %d, task %d\n", omp_get_thread_num(), i);
            }
        }
    }
}
