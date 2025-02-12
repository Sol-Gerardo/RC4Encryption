//
// Created by Jerry Solis on 8/5/24.
//
#include <Windows.h>
#include <stdio.h>

int main() {
    // This is needed to store the handle to the file object
    // the 'INVALID_HANDLE_VALUE' is just to initialize the variable
    HANDLE hFile = INVALID_HANDLE_VALUE;

    LPCWSTR filePath = L"C:\\Users\\jerry\\Desktop\\maldev.txt";

    // Call CreateFileW with the file path
    // The additional parameters are directly from the documentation
    hFile = CreateFileW
            (
                    filePath, GENERIC_ALL, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL
            );

    // On failure CreateFileW returns INVALID_HANDLE_VALUE
    // GetLastError() is another Windows API that retrieves the error code of the previously executed WinAPI function
    if(hFile == INVALID_HANDLE_VALUE) {
        printf("[-] CreateFileW API function Failed With Error: %d\n", GetLastError());

        return -1;
    }

    return 0;
}