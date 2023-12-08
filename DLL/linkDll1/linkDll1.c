#include <Windows.h> 
#include <stdio.h>

// Constructing a new data type that represents HelloWorld's function pointer
typedef void (WINAPI* HelloWorldFunctionPointer)();

void call() {
	// Attempt to get the handle of the DLL
	HMODULE hModule = GetModuleHandleA("Dll.dll");

	if (hModule == NULL) {
		// If the DLL is not loaded in memory, use LoadLibrary to load it
		hModule = LoadLibraryA("Dll.dll");
	}

	// pHelloWorld stores HelloWorld's function address
	PVOID pHelloWorld = GetProcAddress(hModule, "HelloWorld");

	// Typecasting pHelloWorld to be of type HelloWorldFunctionPointer
	HelloWorldFunctionPointer HelloWorld = (HelloWorldFunctionPointer)pHelloWorld;

	// Invoke HelloWorld
	HelloWorld();
}

int main() {
	printf("[+] This program will load Dll.dll.");

	call();

	getchar();
	return 0;
}