# DLL Loading Examples using Windows API

## Overview

This repository showcases a variety of projects that demonstrate the use of the Windows API for dynamically loading DLLs.

## Techniques and Functions

The projects utilize key Windows API functions such as `call()`, `GetProcAddress`, `LoadLibrary`, and `GetModuleHandle`. These functions are important in loading a DLL dynamically or accessing it if it's already loaded into the system's memory.

## Verifying DLL Loading

For verifying the successful loading of DLLs, it is recommended to use tools like Process Hacker. This is a monitoring tool that allows you to view the modules associated with executable processes, which allows us to verify if a DLL was loaded by the application.

## Command Line Execution with rundll32

`rundll32.exe`, which allows the execution of a DLL directly from the command line or terminal. This approach eliminates the need for a separate calling program or an integrated development environment (IDE).

## File Path Considerations

When working with DLLs, ensure to specify the absolute file path to the DLL file unless it resides in the same directory as the executable. This ensures that your application correctly locates and loads the desired DLL.