#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>

/** 
  * The following code demonstrates payload 
  * storage in the PE-File text section.
*/

int main() {
	void* exec_mem;
	BOOL result;
	HANDLE thread;
	DWORD mem_protect = 0;

	// Payload
	unsigned char payload[] = ":)";

	unsigned int payload_len = sizeof(payload);

	// Allocate memory buffer for payload
	exec_mem = VirtualAlloc(0, payload_len, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	printf("%s: 0x%p\n", "payload address", (void*)payload);
	printf("%s: 0x%p\n", "exec_mem address", (void*)exec_mem);


	// Store payload contents in exec_mem or new buffer 
	RtlMoveMemory(exec_mem, payload, payload_len);

	// Make the buffer executable 
	result = VirtualProtect(exec_mem, payload_len, PAGE_EXECUTE_READ, &mem_protect);

	printf("[+] Press <Enter> to Execute Payload ...");
	getchar();
	// Execute the payload using a thread
	if (result) {
		thread = CreateThread(0,0, (LPTHREAD_START_ROUTINE) exec_mem, 0, 0, 0);
		WaitForSingleObject(thread, -1);
	}

	return 0;
}