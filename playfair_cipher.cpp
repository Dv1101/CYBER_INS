#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to prepare the key for the Playfair cipher
string prepareKey(string key) {
    string preparedKey = "";
    bool taken[26] = {false};

    for (char c : key) {
        if (c == 'J') {
            c = 'I'; // Replace J with I
        }
        if (!taken[c - 'A']) {
            preparedKey += c;
            taken[c - 'A'] = true;
        }
    }

    // Fill the rest of the matrix with unused letters
    for (char c = 'A'; c <= 'Z'; c++) {
        if (c != 'J' && !taken[c - 'A']) {
            preparedKey += c;
            taken[c - 'A'] = true;
        }
    }

    return preparedKey;
}

// Function to generate the Playfair matrix
vector<vector<char>> generateMatrix(string key) {
    vector<vector<char>> matrix(5, vector<char>(5));
    string preparedKey = prepareKey(key);
    int index = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = preparedKey[index++];
        }
    }

    return matrix;
}

// Function to find the position of a character in the matrix
void findPosition(vector<vector<char>> matrix, char ch, int &row, int &col) {
    if (ch == 'J') {
        ch = 'I';
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == ch) {
                row = i;
                col = j;
                return;
            }
        }
    }
}

// Function to encrypt a plaintext using Playfair cipher
string playfairEncrypt(string plaintext, string key) {
    vector<vector<char>> matrix = generateMatrix(key);
    string encryptedText = "";

    for (int i = 0; i < plaintext.length(); i += 2) {
        char first = plaintext[i];
        char second = (i + 1 < plaintext.length()) ? plaintext[i + 1] : 'X';

        int row1, col1, row2, col2;
        findPosition(matrix, first, row1, col1);
        findPosition(matrix, second, row2, col2);

        if (row1 == row2) {
            encryptedText += matrix[row1][(col1 + 1) % 5];
            encryptedText += matrix[row2][(col2 + 1) % 5];
        } else if (col1 == col2) {
            encryptedText += matrix[(row1 + 1) % 5][col1];
            encryptedText += matrix[(row2 + 1) % 5][col2];
        } else {
            encryptedText += matrix[row1][col2];
            encryptedText += matrix[row2][col1];
        }
    }

    return encryptedText;
}

// Function to decrypt a ciphertext using Playfair cipher
string playfairDecrypt(string ciphertext, string key) {
    vector<vector<char>> matrix = generateMatrix(key);
    string decryptedText = "";

    for (int i = 0; i < ciphertext.length(); i += 2) {
        char first = ciphertext[i];
        char second = (i + 1 < ciphertext.length()) ? ciphertext[i + 1] : 'X';

        int row1, col1, row2, col2;
        findPosition(matrix, first, row1, col1);
        findPosition(matrix, second, row2, col2);

        if (row1 == row2) {
            decryptedText += matrix[row1][(col1 + 4) % 5];
            decryptedText += matrix[row2][(col2 + 4) % 5];
        } else if (col1 == col2) {
            decryptedText += matrix[(row1 + 4) % 5][col1];
            decryptedText += matrix[(row2 + 4) % 5][col2];
        } else {
            decryptedText += matrix[row1][col2];
            decryptedText += matrix[row2][col1];
        }
    }

    return decryptedText;
}

int main() {
    string key, plaintext, ciphertext;

    cout << "Enter the key (no spaces, uppercase letters only): ";
    cin >> key;

    cout << "Enter the plaintext (uppercase letters only): ";
    cin >> plaintext;

    ciphertext = playfairEncrypt(plaintext, key);
    cout << "Encrypted Text: " << ciphertext << endl;

    string decryptedText = playfairDecrypt(ciphertext, key);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
