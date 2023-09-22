#include<iostream>
#include<string>
using namespace std;

void encryption(int key_arr[2][2], int txt_arr[2][2])
{
    int val1, val2, val3, val4;

    val1 = (key_arr[0][0] * txt_arr[0][0]) + (key_arr[0][1] * txt_arr[1][0]);
    val2 = (key_arr[1][0] * txt_arr[0][0]) + (key_arr[1][1] * txt_arr[1][0]);
    
    val3 = (key_arr[0][0] * txt_arr[0][1]) + (key_arr[0][1] * txt_arr[1][1]);
    val4 = (key_arr[1][0] * txt_arr[0][1]) + (key_arr[1][1] * txt_arr[1][1]);
    
    int remainder1 = val1 % 26;
    int remainder2 = val2 % 26;
    int remainder3 = val3 % 26;
    int remainder4 = val4 % 26;

    char c1 = (char)(remainder1 + 65);
    char c2 = (char)(remainder2 + 65);
    char c3 = (char)(remainder3 + 65);
    char c4 = (char)(remainder4 + 65);

    string hillCipher;
    hillCipher.push_back(c1);
    hillCipher.push_back(c2);
    hillCipher.push_back(c3);
    hillCipher.push_back(c4);
    
    cout<<endl<<"************************************"<<endl;
    cout<<"Hill Cipher text is : ";
    cout<<hillCipher;
    cout<<endl<<"************************************"<<endl<<endl;

}

int gcdExtended(int a, int b, int& x, int& y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;
    int gcd = gcdExtended(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;

    return gcd;
}

int modInverse(int a, int m) {
    int x, y;
    int gcd = gcdExtended(a, m, x, y);

    if (gcd != 1) {
        cerr << "Inverse does not exist." << endl;
        exit(1);
    }

    return (x % m + m) % m;
}

void decryption(int key_arr[2][2], int txt_arr[2][2]) {
    int det = key_arr[0][0] * key_arr[1][1] - key_arr[0][1] * key_arr[1][0];
    int mod_det = (det % 26 + 26) % 26;

    int detInverse = modInverse(mod_det, 26);

    int inv_key_arr[2][2];

    inv_key_arr[0][0] = (key_arr[1][1] * detInverse) % 26;
    inv_key_arr[0][1] = (-key_arr[0][1] * detInverse + 26) % 26;
    inv_key_arr[1][0] = (-key_arr[1][0] * detInverse + 26) % 26;
    inv_key_arr[1][1] = (key_arr[0][0] * detInverse) % 26;

    int plain_arr[2][2];

    plain_arr[0][0] = (inv_key_arr[0][0] * txt_arr[0][0] + inv_key_arr[0][1] * txt_arr[1][0]) % 26;
    plain_arr[1][0] = (inv_key_arr[0][0] * txt_arr[0][1] + inv_key_arr[0][1] * txt_arr[1][1]) % 26;
                      //(inv_key_arr[1][0] * txt_arr[0][0] + inv_key_arr[1][1] * txt_arr[1][0])

    plain_arr[0][1] = (inv_key_arr[1][0] * txt_arr[0][0] + inv_key_arr[1][1] * txt_arr[1][0]) % 26;
    plain_arr[1][1] = (inv_key_arr[1][0] * txt_arr[0][1] + inv_key_arr[1][1] * txt_arr[1][1]) % 26;

    string plainText = "";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            char c = 'A' + (plain_arr[i][j] + 26) % 26;
            plainText += c;
        }
    }

    cout << endl << "************************************" << endl;
    cout << "Decrypted text is: " << plainText << endl;
    cout << "************************************" << endl << endl;
}


int main()
{
    cout<<"Enter key text : "<<endl;
    string key;
    getline(cin, key);

    int key_arr[2][2];
    int num_arr[4];

    for(int i=0; i<key.size(); i++)
    {
        char c = key[i];
        int temp = c;
        int converted = temp-65;
        num_arr[i] = converted;
    }

    int k=0;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            key_arr[i][j] = num_arr[k];
            k++;
        }
    }

    cout<<"Enter plain text : "<<endl;
    string txt;
    getline(cin, txt);

    int txt_arr[2][2];
    int txtnum_arr[4];

    for(int i=0; i<txt.size(); i++)
    {
        char c = txt[i];
        int temp = c;
        int converted = temp-65;
        txtnum_arr[i] = converted;
    }

    k=0;
    for(int i=0; i<2; i++)
    {
        txt_arr[i][0] = txtnum_arr[k];
        k++;
    }

    for(int i=0; i<2; i++)
    {
        txt_arr[i][1] = txtnum_arr[k];
        k++;
    }

    encryption(key_arr, txt_arr);

    cout << "Enter ciphertext : " << endl;
    string txtt;
    getline(cin, txtt);

    int txt_arrr[2][2];
    int txtnum_arrr[4];

    for (int i = 0; i < txtt.size(); i++) {
        char c = txtt[i];
        int temp = c;
        int converted = temp - 'A';
        txtnum_arrr[i] = converted;
    }

    k = 0;
    for (int i = 0; i < 2; i++) {
        txt_arrr[i][0] = txtnum_arrr[k];
        k++;
    }

    for (int i = 0; i < 2; i++) {
        txt_arrr[i][1] = txtnum_arrr[k];
        k++;
    }

    decryption(key_arr, txt_arrr);

    return 0;
}
