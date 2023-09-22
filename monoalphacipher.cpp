#include <iostream>
#include <map>

using namespace std;

string encrypt(string plaintext, const map<char, char>& cipherMap) {
    string ciphertext;
    for (char c : plaintext) {
        if (isalpha(c)) {
            char uppercase_c = toupper(c);
            if (cipherMap.count(uppercase_c) > 0) {
                ciphertext += cipherMap.at(uppercase_c);
            } else {
                ciphertext += c; // For non-alphabetic characters, just append them as they are.
            }
        } else {
            ciphertext += c; // For non-alphabetic characters, just append them as they are.
        }
    }
    return ciphertext;
}

string decrypt(string ciphertext, const map<char, char>& cipherMap) {
    string plaintext;
    for (char c : ciphertext) {
        if (isalpha(c)) {
            char uppercase_c = toupper(c);
            bool found = false;
            for (const auto& pair : cipherMap) {
                if (pair.second == uppercase_c) {
                    plaintext += pair.first;
                    found = true;
                    break;
                }
            }
            if (!found) {
                plaintext += c; // If the character is not found in the cipher map, just append it as it is.
            }
        } else {
            plaintext += c; // For non-alphabetic characters, just append them as they are.
        }
    }
    return plaintext;
}

int main() {
    map<char, char> cipherMap;

    cipherMap['A'] = 'Z';
    cipherMap['B'] = 'Y';
    cipherMap['C'] = 'X';
    cipherMap['D'] = 'W';
    cipherMap['E'] = 'V';
    cipherMap['F'] = 'U';
    cipherMap['G'] = 'T';
    cipherMap['H'] = 'S';
    cipherMap['I'] = 'R';
    cipherMap['J'] = 'Q';
    cipherMap['K'] = 'P';
    cipherMap['L'] = 'O';
    cipherMap['M'] = 'N';
    cipherMap['N'] = 'M';
    cipherMap['O'] = 'L';
    cipherMap['P'] = 'K';
    cipherMap['Q'] = 'J';
    cipherMap['R'] = 'I';
    cipherMap['S'] = 'H';
    cipherMap['T'] = 'G';
    cipherMap['U'] = 'F';
    cipherMap['V'] = 'E';
    cipherMap['W'] = 'D';
    cipherMap['X'] = 'C';
    cipherMap['Y'] = 'B';
    cipherMap['Z'] = 'A';

    string plaintext;
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    string ciphertext = encrypt(plaintext, cipherMap);
    cout << "Ciphertext: " << ciphertext << endl;

    cout << "Enter the Ciphertext: ";
    getline(cin, ciphertext);
    string decryptedText = decrypt(ciphertext, cipherMap);
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}
