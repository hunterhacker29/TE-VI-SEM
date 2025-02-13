import hashlib
from Crypto.Cipher import AES
import random

# A3: Simplified Signed Response calculation
def A3(RAND, Ki):
    # This should be replaced by the real A3 algorithm
    # Here, we'll just mock it as a hash of RAND and Ki for simplicity
    return hashlib.md5(RAND.encode('utf-8') + Ki.encode('utf-8')).hexdigest()[:8]

# A8: Simplified Encryption Key calculation
def A8(RAND, Ki):
    # This should be replaced by the real A8 algorithm
    # Mocking with a simple AES encryption key generation
    cipher = AES.new(Ki.encode('utf-8'), AES.MODE_ECB)
    
    # Ensure RAND is a 16-byte multiple by padding
    rand_bytes = RAND.encode('utf-8')
    padded_rand = rand_bytes.ljust(16, b'\0')  # Pad to 16 bytes if necessary

    # If RAND is too large, we need to truncate or hash it to fit into a 16-byte block
    if len(padded_rand) > 16:
        padded_rand = hashlib.md5(padded_rand).digest()  # Hash if RAND is too large
    
    encrypted = cipher.encrypt(padded_rand)
    return encrypted[:8]  # 64-bit Kc

# GSM Authentication Simulation
def gsm_authentication(IMSI, RAND, Ki):
    print(f"IMSI: {IMSI}")
    print(f"RAND: {RAND}")
    
    # Step 1: MS calculates SRES and Kc
    SRES = A3(RAND, Ki)
    Kc = A8(RAND, Ki)
    
    print(f"SRES: {SRES}")
    print(f"Kc: {Kc.hex()}")
    
    return Kc  # For data encryption

if __name__ == '__main__':
    # Example usage
    IMSI = "123456789012345"
    RAND = str(random.getrandbits(128))  # Random 128-bit number
    Ki = "1234567890abcdef"  # A mock key (Ki from SIM card)
    Kc = gsm_authentication(IMSI, RAND, Ki)
