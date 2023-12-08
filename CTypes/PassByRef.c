#include <stdlib.h>
#include <stdio.h>

void add(int *a, int *b, int *result) {
    int A = *a; // A is now the same value of a passed in from the main function
    int B = *b; // B is now the same value of b passed in from main function

    *result = B + A;
}

int main() {
    int x = 5;
    int y = 10;
    int sum = 0;

    add(&x, &y, &sum);

    // 'sum' now is 15
    printf("Sum is now: %d\n", sum);

    return 0;
}