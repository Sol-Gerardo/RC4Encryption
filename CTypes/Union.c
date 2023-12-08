#include <stdio.h>
#include <stdlib.h>

union ExampleUnion {
    int IntegerVar;
    char CharVar;
    float FloatVar;
} ExUnion;

int main() {
    ExUnion.IntegerVar = 15;

    printf("The value in IntegerVar is: %d\n", ExUnion.IntegerVar);
    printf("The value in CharVar is: %c\n", ExUnion.CharVar);
    printf("The value in FloatVar is: %f\n", ExUnion.FloatVar);
    
    ExUnion.FloatVar = 20.0;

    printf("\nThe value in IntegerVar is: %d\n", ExUnion.IntegerVar);
    printf("The value in CharVar is: %c\n", ExUnion.CharVar);
    printf("The value in FloatVar is: %f\n", ExUnion.FloatVar);

    ExUnion.CharVar = 'A';

    printf("\nThe value in IntegerVar is: %d\n", ExUnion.IntegerVar);
    printf("The value in CharVar is: %c\n", ExUnion.CharVar);
    printf("The value in FloatVar is: %f\n", ExUnion.FloatVar);

    return 0;
}