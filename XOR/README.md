# implant.cpp
Takes in the payload and decrypts it using the xor encrypted method.
XOR is a two-way encryption method meaning as long as we have the encryption 
we can decrypt or encrypt the payload.

# xorencrypt.py 
This file allows us to encrypt the payload, once encrypted 
we can paste it into the implant file without AV deleting.
 
At the moment these programs are not stealthy and will be detected 
by Windows AV. The encryption and decryption portions do work but 
a stronger encryption implementation is needed. 
This project is a work in progress.