#include <iostream>
#include <map>

using namespace std;

string encrypt(string plaintext, const map<char, char>& cipherMap) {
    string ciphertext;
    for (char c : plaintext) {
        if (cipherMap.count(c) > 0) {
            ciphertext += cipherMap.at(c);
        } else {
            ciphertext += c;
        }
    }
    return ciphertext;
}

string decrypt(string ciphertext, const map<char, char>& cipherMap) {
    string plaintext;
    for (char c : ciphertext) {
        bool found = false;
        for (const auto& pair : cipherMap) {
            if (pair.second == c) {
                plaintext += pair.first;
                found = true;
                break;
            }
        }
        if (!found) {
            plaintext += c;
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
