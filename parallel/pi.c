#include <time.h>
#include <stdio.h>
#include <omp.h>

// pi = int_0^1{ 4.0 / 1 + x^2}
int main() {
    double start_time = omp_get_wtime();
    double start = clock();

    long num_steps = 100000000;
    double step = 1.0 / (double) num_steps;
    double pi = 0;
    double sum = 0;
    double x = 0;

    // #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < num_steps; i++) {
        x = (i + 0.5) * step;
        sum = sum + 4.0 / (1.0 + x * x);
    }
    pi = step * sum;

    double end_time = omp_get_wtime();

    clock_t end = clock();
    printf("Pi: %.17f\n", pi);
    printf("Time taken (real): %.3f sec\n", end_time - start_time);
    printf("Time taken (user): %Lf sec\n", (long double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
