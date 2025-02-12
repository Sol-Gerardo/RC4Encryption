//
// Created by Jerry Solis on 8/5/24.
//

#include <Windows.h>
#include <Lmcons.h>
#include <stdio.h>

int main() {
    char username[UNLEN + 1];
    DWORD username_len = UNLEN + 1;

    if (!GetUserNameA(username, &username_len )) {
        printf("[-] GetUserNameA API Function Failed With Error: %d\n", GetLastError());
    }
    else {
        printf("[+] Username: %s\n", username);
    }

    return 0;
}