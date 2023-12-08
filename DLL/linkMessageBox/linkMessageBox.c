#include <Windows.h>
#include <stdio.h>

typedef int (WINAPI* MessageBoxAFunctionPointer)(
	HWND		hWnd,
	LPCSTR		lpText,
	LPCSTR		lpCaption,
	UINT		uType
);

void call() {
	// Retrieving MessageBox's address, and saving it to 'pMessageBoxA' (MessageBoxA's function pointer)
	MessageBoxAFunctionPointer pMessageBoxA = 
		(MessageBoxAFunctionPointer)GetProcAddress(LoadLibraryA("user32.dll"), "MessageBoxA");

	if (pMessageBoxA != NULL) {
		// Calling MessageBox via its function pointer if not null
		pMessageBoxA(NULL, "Displaying text using MessageBox WinAPI", "MessageBox Caption", MB_OK);
	}
}

int main() {
	printf("[+] This program will call the Windows API MessageBox function.");

	call();

	getchar();
	return 0;
}