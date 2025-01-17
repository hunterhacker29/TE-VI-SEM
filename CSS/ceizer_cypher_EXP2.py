encrypt = []
decrypt = []
alphabet_dict = {chr(i + 97): i for i in range(26)}
print(alphabet_dict)

text = "ADVAIT"  
key = 77
new_text = list(text.lower())

string = ''.join(new_text)
print("Text is :", string)

inverse_dict = dict(zip(alphabet_dict.values(), alphabet_dict.keys()))

# Encrypt 
for i in range(len(new_text)):
    val = new_text[i]
    new_val = alphabet_dict[val]
    mod = (new_val + key) % 26 
    enc = inverse_dict.get(mod)
    encrypt.append(enc)

string1 = ''.join(encrypt)
print("Encrypted text : ", string1)

# decrypt 
for i in range(len(string1)):
    val = string1[i]
    new_val = alphabet_dict[val]
    mod = (new_val - key) % 26 
    enc = inverse_dict.get(mod)
    decrypt.append(enc)

string2 = ''.join(decrypt)
print("After decrypt text : ", string2)
