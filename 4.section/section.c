#include <stdio.h>

/////////////////
//
// 2
//
/////////////////

int foo(int *arr, size_t n) {
    return n ? arr[0] + foo(arr + 1, n - 1) : 0;
}

int foo2(int *arr, size_t n) {
    if (n != 0) {
        return arr[0] + foo(arr + 1, n - 1);
    } else {
        return 0;
    }
}

int bar(int* arr, size_t n) {
    int sum = 0, i;
    for (i = n; i > 0; i--) {
        sum += !arr[i - 1];
    }
    return sum;
}

int bar2(int* arr, size_t n) {
    int sum = 0;
    int i = 0;
    for (i = n; i > 0; i--) {
        int x = !arr[i - 1];
        sum += x;
    }
    return sum;
}

void baz(int x, int y) {
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}

void problem_2() {
    int x[3] = {1, 2, 3};
    printf("%d\n", foo(x, 2));
    printf("%d\n", foo(x, 3));

    int y[3] = {1, 0, 3};
    printf("%d\n", bar(y, 3));
}

/////////////////
//
// 3.1
//
/////////////////
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void problem_3_1() {
    int x = 1;
    int y = 2;
    swap(&x, &y);
    printf("%d %d\n", x, y);
}

/////////////////
//
// 3.2
//
/////////////////
int my_strlen(char* str) {
    int count = 0;
    while (*str != '\0') {
        count++;
        str++;
    }
    return count;
}

int my_strlen2(char* str) {
    int count = -1;
    while (count++, *str++) {}
    return count;
}

int my_strlen3(char* str) {
    char* p = str;
    while (*p++) {}
    return p - str - 1;
}

void problem_3_2() {
    char str[] = "cs61c";
    printf("%d\n", my_strlen(str));
    printf("%d\n", my_strlen2(str));
    printf("%d\n", my_strlen3(str));
}

int main() {
    problem_2();
    problem_3_1();
    problem_3_2();
    return 0;
}
