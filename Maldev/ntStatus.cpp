//
// Created by Jerry Solis on 8/5/24.
//
#include <Windows.h>
#include <stdio.h>

// Example non-working program
int main() {


    NTSTATUS STATUS = NativeSyscallExample(...);

    if(STATUS != STATUS_SUCCESS) {
        // printing the error in unsigned integer hexadecimal format
        printf("[!] NativeSyscallExampleFailed With Status: 0x%0.8X\n", STATUS);
    }

    return 0;
}