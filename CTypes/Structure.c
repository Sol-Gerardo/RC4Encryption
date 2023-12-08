#include <stdlib.h>
#include <stdio.h>

typedef struct _STRUCT_NAME {
    int num1;
    int num2;
} STRUCT_NAME, *PSTRUCT_NAME;

int main() {
    struct _STRUCT_NAME struct1 = {0};
    STRUCT_NAME struct2 = {0};
    PSTRUCT_NAME struct3 = &struct1;

    struct1.num1 = 10;
    struct1.num2 = 11;
     
    printf("struct1: %d, %d\n", struct1.num1, struct1.num2);

    struct2.num1 = 12;
    struct2.num2 = 13;
    
    struct3->num1 = 14;
    struct3->num2 = 15;
    
    printf("struct2: %d, %d\n", struct2.num1, struct2.num2);
    printf("struct3: %d, %d\n", (*struct3).num1, (*struct3).num2);
    printf("struct1: %d, %d\n", struct1.num1, struct1.num2);

    return 0;
}