#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const string DS = "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^-'abcdefghijklmnopqrstuvwxyz{|}~ ";

string encrypt(string plaintext, int key) {
    string encryptedText = "";
    for (char& c : plaintext) {
        if (DS.find(c) != string::npos) {
            int index = (DS.find(c) + key) % DS.size();
            encryptedText += DS[index];
        } else {
            encryptedText += c;
        }
    }
    return encryptedText;
}

string decrypt(string encryptedText, int key) {
    string plaintext = "";
    for (char& c : encryptedText) {
        if (DS.find(c) != string::npos) {
            int index = (DS.find(c) - key + DS.size()) % DS.size();
            plaintext += DS[index];
        } else {
            plaintext += c;
        }
    }
    return plaintext;
}

int main() {
    srand(time(nullptr));

    cout << "\n\t\t Caesar Cipher Encrypt/Decrypt Application\n\n ";
    cout << "1. Encrypt a message\n";
    cout << "2. Decrypt a message\n";
    cout << ">>";
    string menuChoice;
    cin >> menuChoice;

    if (menuChoice == "1") {
        string plaintext;
        cout << "\nEnter the message you want to encrypt : ";
        getline(cin >> ws, plaintext);
        while (plaintext.length() < 15) {
            cout << "The message should be 15 characters minimum, Enter the message again: ";
            getline(cin >> ws, plaintext);
        }

        int key = rand() % 75 + 1;
        string encryptedText = encrypt(plaintext, key);

        ofstream outfile("encryption.txt");
        outfile << encryptedText;
        outfile.close();

        cout << "\nOriginal Message (Plaintext): " << plaintext << endl;
        cout << "Key: " << key << endl;
        cout << "Encryption result: " << encryptedText << endl;
        cout << "\nEncryption result saved in a file\n";
    } else if (menuChoice == "2") {
        string encryptedText;
        cout << "\nEnter the encrypted text you want to decrypt : ";
        getline(cin >> ws, encryptedText);
        int key;
        cout << "Enter the key : ";
        cin >> key;

        string decrypted_plaintext = decrypt(encryptedText, key);

        ofstream outfile("decryption.txt");
        outfile << decrypted_plaintext;
        outfile.close();

        cout << "Decrypted result: " << decrypted_plaintext << endl;
        cout << "\nDecryption result saved in a file\n";
    } else {
        cout << "Choose 1 or 2\n";
    }

    return 0;
}
