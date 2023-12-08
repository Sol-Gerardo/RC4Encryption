#include "stdio.h"
#include "Windows.h"

typedef void (WINAPI* HelloWorldFunctionPointer)();

int main() {
	// Attempt to get the handle of the DLL
	HMODULE hModule = GetModuleHandleA("Dll.dll");

	if (hModule == NULL) {
		// If the DLL is not loaded in memory, use LoadLibrary to load it
		hModule = LoadLibraryA("Dll.dll");
	}

	PVOID pHelloWorld = GetProcAddress(hModule, "HelloWorld"); // pHelloWorld stores HelloWorld's function address

	HelloWorldFunctionPointer HelloWorld = (HelloWorldFunctionPointer)pHelloWorld;

	getchar();
	return 0;
}