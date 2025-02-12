#include <iostream>
using namespace std;

typedef struct _STRUCTURE_NAME {
    int ID;
    int Age;
} STRUCTURE_NAME, *PSTRUCTURE_NAME;

int main() {
    STRUCTURE_NAME struct1 = { 0 }; // initialize all elements of struct1

    struct1.ID = 1470; // initialize the ID element
    struct1.Age = 34; // initialize the Age element

    printf("ID: %d\n", struct1.ID);
    printf("Age: %d\n\n", struct1.Age);

    STRUCTURE_NAME struct2 = { .ID = 1996, .Age = 28}; // initialize both the ID and the Age elements

    printf("ID: %d\n", struct2.ID);
    printf("Age: %d\n\n", struct2.Age);

    PSTRUCTURE_NAME structpointer = &struct1; // structpointer is a pointer to the 'struct1' structure

    // Updating the ID member
    structpointer->ID = 8765;
    printf("The structure's ID member is now: %d\n", structpointer->ID);

    return 0;
}