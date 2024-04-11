#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char* cString = "Sol-Gerardo";
	PVOID pAddress = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, 100);


	memcpy(pAddress, cString, strlen(cString));


	printf("[+] Base address of allocated memory: 0x%p\n", pAddress);
	printf("[+] Press <Enter> to Quit ...");

	getchar();
}