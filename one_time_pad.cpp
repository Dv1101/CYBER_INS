#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string generate_key(int message_length) {
    static const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const int charset_length = sizeof(charset) - 1;

    string key;
    srand(static_cast<unsigned>(time(0))); // Initialize random seed

    for (int i = 0; i < message_length; ++i) {
        key += charset[rand() % charset_length];
    }

    return key;
}

string encrypt(const string& message, const string& key) {
    string encrypted;
    for (size_t i = 0; i < message.length(); ++i) {
        char message_char = message[i];
        char key_char = key[i];
        int message_ord = message_char - 'A';
        int key_ord = key_char - 'A';
        char encrypted_char = ((message_ord + key_ord) % 26) + 'A';
        encrypted += encrypted_char;
    }
    return encrypted;
}

string decrypt(const string& encrypted_message, const string& key) {
    string decrypted;
    for (size_t i = 0; i < encrypted_message.length(); ++i) {
        char encrypted_char = encrypted_message[i];
        char key_char = key[i];
        int encrypted_ord = encrypted_char - 'A';
        int key_ord = key_char - 'A';
        char decrypted_char = ((encrypted_ord + 26 - key_ord) % 26) + 'A';
        decrypted += decrypted_char;
    }
    return decrypted;
}

int main() {
    cout<<"ONE TIME PAD - DHRUV VARIA"<<endl;
    cout<<"Enter plain Text : ";
    string message;
    getline(cin, message);
    
    string key = generate_key(message.length());
    cout<<endl<<"------Generated Random Key------------"<<endl;
    cout<<key<<endl;

    // Encryption
    string encrypted_message = encrypt(message, key);
    cout << "Encrypted message: " << encrypted_message << endl;

    // Decryption
    string decrypted_message = decrypt(encrypted_message, key);
    cout << "Decrypted message: " << decrypted_message << endl;

    return 0;
}
