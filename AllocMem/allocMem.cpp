//
// Created by Jerry Solis on 8/2/24.
//

#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
    // Allocating a memory buffer of *100* bytes

    // Method 1 - Using malloc()
    PVOID pAddress1 = malloc(100);

    // Method 2 - Using HeapAlloc()
    PVOID pAddress2 = HeapAlloc(GetProcessHeap(), 0, 100);

    // Method 3 - Using LocalAlloc()
    PVOID pAddress = LocalAlloc(LPTR, 100);

    return 0;
}