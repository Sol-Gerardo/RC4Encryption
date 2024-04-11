# Allocating Memory Using WinAPI

The following program uses HeapAlloc and GetProcessHeap to copy a cString to memory.

We verify the cString was copied to memory by using x64dbg and searching for the 
memory address output in the command line as shown in the image.

![alt text](allocMemImg.png)