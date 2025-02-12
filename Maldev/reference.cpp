//
// Created by Jerry Solis on 8/2/24.
//
#include <iostream>
using namespace std;

void add (int *a, int *b, int* result) {
    int A = *a; // A is now the same value of a passed in from the main function
    int B = *b; // B is now the same value of b passed in from the main function

    *result = B + A;
}

int main() {
    int x = 5;
    int y = 10;
    int sum = 0;

    add(&x, &y, &sum);
    // 'sum' now is 15.

    printf("The sum of %d + %d = %d\n", x, y, sum);

    return 0;
}