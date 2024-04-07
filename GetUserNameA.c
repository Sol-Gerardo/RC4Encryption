#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    char username[20];
    DWORD usernameLen = 20;
    
    printf("[+] Getting the current user's username.");
    printf("\n[+] Press <Enter> to continue.");
    getchar(); // Pause for user input
    
    if(!GetUserNameA(username, &usernameLen)) {
        printf("\n[-] GetFileName API Function Failed With Error : %d\n", GetLastError());
    } 
    else {
        printf("\n[+] The current user's username is: %s\n", username);
    }

    getchar(); // To pause before exiting



    return 0;
}