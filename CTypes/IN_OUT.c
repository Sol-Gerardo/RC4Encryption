#include <Windows.h>
#include <stdio.h>

BOOL func(IN int inputVal, OUT int* num) {
    // Setting the vlaue of num to 123
    *num = 123;

    // Returning boolean value
    return TRUE;
}

int main() {
    int a = 0;
    int inputVal = 100; // Example input value

    printf("[+]This program will use a pointer to set the value of a to 123 using pointers.\n");
    printf("[+] The purpose of this program is to demonstrate the WinAPI IN and OUT parameter.\n");

    // 'func' will return true
    // 'a' will contain the value 223 (100 + 23)
    func(inputVal, &a);

    printf("[+]The new value of 'a' is %d\n", a);

    getchar();
    return 0;
}
