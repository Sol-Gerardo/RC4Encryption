import binascii

KEY = ""

def xor(data, key):
    payload_enc = bytearray()
    j = 0
    for i, byte in enumerate(data):
        payload_enc.append(byte ^ ord(key[i % len(key)]))

    # Convert to hexadecimal for visibility
    hex_payload = binascii.hexlify(payload_enc)
    formatted_output = ''

    for i in range(0, len(hex_payload), 2): # Process two hex characters at a time
        byte_hex = hex_payload[i:i+2].decode('utf-8') # Decode to get a string 
        formatted_output += '0x' + byte_hex.upper() # Convert to uppercase

        if i < len(hex_payload) - 2: # Check if it is not the last byte
            formatted_output += "," # Add a comma for separation

        if(i // 2 + 1) % 10 == 0: # After every 10 bytes, add a newline
            formatted_output += '\n' 
    print(formatted_output)

def main():
    # Read payload from a file
    with open("", "rb") as file:
        payload = file.read()


    xor(payload, KEY)

if __name__ == "__main__":
    main()
