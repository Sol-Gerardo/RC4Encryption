# RC4 Encryption Project

## Introduction
This project showcases three different encryption methods using the RC4 algorithm.\
The primary focus is on the implementation of RC4 encryption and decryption using C.\
The code demonstrates how the same encryption method can be used for both encrypting and decrypting payloads, displaying the bidirectional convenience of RC4 encryption.

## Encryption Method 1: RC4 Basic Implementation
This method utilizes `RC4Context`, `RC4Init`, and `RC4Cipher` functions to initialize and perform RC4 encryption.\
The RC4 context uses the supplied key, while `rc4Cipher` is responsible for the encryption process and can also be used for decryption as well.

## Key components 
- `RC4Context`: A struct that holds the state of the RC4 stream.
- `rc4Init`: Function to initialize the RC4 context with a given key
- `rc4Cipher`: Function that performs the actual encryption and decryption. 

## Link to RC4 encryption functions 
https://www.oryx-embedded.com/doc/rc4_8c_source.html