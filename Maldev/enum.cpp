//
// Created by Jerry Solis on 8/1/24.
//
#include <iostream>
using namespace std;

enum Weekdays {
    Monday,     // 0
    Tuesday,    // 1
    Wednesday,  // 2
    Thursday,   // 3
    Friday,     // 4
    Saturday,   // 5
    Sunday      // 6
};

int main() {
    // Defining a "Weekdays" enum variable
    enum Weekdays EnumName = Friday; // 4

    // Check the value of "EnumName"
    switch (EnumName) {
        case Monday:
            printf("Today is Monday!\n");
            break;
        case Tuesday:
            printf("Today is Tuesday!\n");
            break;
        case Wednesday:
            printf("Today is Wednesday!\n");
            break;
        case Thursday:
            printf("Today is Thursday!\n");
            break;
        case Friday:
            printf("Today is Friday!\n");
            break;
        case Saturday:
            printf("Today is Saturday!\n");
            break;
        case Sunday:
            printf("Today is Sunday!\n");
            break;
        default:
            break;
    }

    return 0;
}
