# libs
import random

# The characters that can be used in the process, the user can use only use this set of chars 
DS = "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^-'abcdefghijklmnopqrstuvwxyz{|}~"

# Encryption function
def encrypt(plaintext, key):
    encryptedText = ""
    for char in plaintext:
        if char in DS:
            index = (DS.index(char) + key) % len(DS)
            encryptedText += DS[index]
        else:
            encryptedText += char
    return encryptedText

# Decryption function
def decrypt(encryptedText, key):
    plaintext = ""
    for char in encryptedText:
        if char in DS:
            index = (DS.index(char) - int(key)) % len(DS)
            plaintext += DS[index]
        else:
            plaintext += char
    return plaintext

# App Menu
print("\n\t\t Caesar Cipher Encrypt/Decrypt Application\n\n ")
print("1. Encrypt a message\n")
print("2. Decrypt a message\n")
menuChoice = input(">>")


if(menuChoice == "1"):

    plaintext = input("\nEnter the message you want to encrypt : ")
    while len(plaintext) < 15:
        plaintext = input("The message should be 15 characters minimum, Enter the message again:  ")
    # Key Generation
    key = random.randint(1, 75)
    # Encrypt with key
    encryptedText = encrypt(plaintext, key)
    with open("encryption", "w") as f:
        f.write(encryptedText)
    print(f"\nOriginal Message (Plaintext): {plaintext}")
    print(f"Key: {key}")
    print(f"Encryption result: {encryptedText}")
    print("\nEncryption result saved in a file\n")

elif(menuChoice == "2"):
    encryptedText = input("\nEnter the encrypted text you want to decrypt : ")
    key = input("Enter the key : ")
    # Decrypt with key
    decrypted_plaintext = decrypt(encryptedText, key)
    # Saving the result into a file
    with open("decryption.txt", "w") as f:
        f.write(decrypted_plaintext)
    print(f"Decrypted result: {decrypted_plaintext}")
    print("\nDecryption result saved in a file\n")

else:
    print("Choose 1 or 2")

"""
Example #1

Original Message (Plaintext): Ahmad Raed Jawabreh
Key: 8
Encryption result: Ipuil Ziml Ri0ijzmp

Exapme #2
Original Message (Plaintext): i am ahmad jawabreh
Key: 26
Encryption result: 4 {8 {38{~ 5{B{|=03


"""