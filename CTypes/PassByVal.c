#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) {
    int result = a + b;
    return result;
}

int main() {
    int x = 5;
    int y = 10;
    int sum = add(x, y); // x and y are passed by value

    printf("Result of sum is: %d\n", sum);

    return 0;
}