//
// Created by Jerry Solis on 8/2/24.
//
#include <iostream>
using namespace std;

union ExampleUnion {
    int IntegerVar;
    char CharVar;
    float FloatVar;
} exUnion;

int main () {
    exUnion.IntegerVar = 1;
    printf("exUnion.IntegerVar: %d\n\n", exUnion.IntegerVar);

    exUnion.CharVar = 'G';
    printf("exUnion.CharVar: %c\n\n", exUnion.CharVar);

    exUnion.FloatVar = 1.07;
    printf("exUnion.FloatVar: %f\n\n", exUnion.FloatVar);

    // Prints float value but converts to integer
    printf("exUnion.IntegerVar: %d\n\n", exUnion.IntegerVar);

    return 0;
}