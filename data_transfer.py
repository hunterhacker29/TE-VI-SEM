import authentication
import random

# A5 Encryption (stream cipher using Kc)
def A5(Kc, data):
    # Ensure that both Kc and data are in bytes
    key_stream = Kc * (len(data) // len(Kc) + 1)  # Repeat Kc to match data length
    encrypted_data = bytearray()  # Create a mutable bytearray to hold encrypted data

    # Encrypt the data by XORing with key_stream
    for d, k in zip(data.encode(), key_stream[:len(data)]):  # Convert data to bytes
        encrypted_data.append(d ^ k)

    return encrypted_data

# GSM Data Transfer (Encryption and Decryption)
def gsm_data_transfer(Kc, data):
    print(f"Original data: {data}")
    
    # Encrypt the data
    encrypted_data = A5(Kc, data)
    print(f"Encrypted data (bytes): {encrypted_data}")
    
    # Decrypt the data (XOR again to decrypt)
    decrypted_data = A5(Kc, encrypted_data.decode(errors='ignore'))  # XOR again to decrypt
    print(f"Decrypted data: {decrypted_data.decode(errors='ignore')}")  # Decode the bytes back to string
    
if __name__ == '__main__':
    # Example usage
    IMSI = "123456789012345"
    RAND = str(random.getrandbits(128))  # Random 128-bit number
    Ki = "1234567890abcdef"  # A mock key (Ki from SIM card)
    data = "This is a test message."
    Kc = authentication.gsm_authentication(IMSI, RAND, Ki)
    gsm_data_transfer(Kc, data)
