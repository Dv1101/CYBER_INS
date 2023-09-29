#include<bits/stdc++.h>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    string plaintext;
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    int n = static_cast<int>(ceil(plaintext.length()/5.00));
    cout<<n;
    int m = 5;

    vector<vector<char>> arr(n, vector<char>(5 * m, 'x'));

    int it = 0;
    int charit = 0;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0 ; j<m; j++)
        {
            if (it < plaintext.length()) {
                arr[i][j] = plaintext[charit];
                charit++;
                it++;
            }
        }
    }

    cout<<endl<<"--------------------Matrix------------------"<<endl;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0 ; j<m; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    string cipherText;

    cout<<endl<<"Enter 5 digit Key (Enter key between 0-4)"<<endl;
    int key;
    cin>>key;
    int decryptKey = key;

    while(key>0)
    {
        int lastDigit = key%10;
        key = key/10;

        for(int i=0; i<n; i++)
        {
            cipherText += arr[i][lastDigit];
        }
    }

    cout<<endl<<"--------------------Cipher Text------------------"<<endl;
    cout<<cipherText<<endl;

    it=0;
    //decryption
    while (decryptKey > 0) {
        int lastDigit = decryptKey % 10;
        decryptKey = decryptKey / 10;

        for (int i = 0; i < n; i++) {
            arr[i][lastDigit] = cipherText[it];
            it++;
        }
    }

    cout<<endl<<"--------------------Matrix------------------"<<endl;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0 ; j<m; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<"--------------------Decrypted Plain Text------------------"<<endl;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0 ; j<m; j++)
        {
            if(arr[i][j] != 'x')
            {
                cout<<arr[i][j];
            }
        }
    }

    return 0;
}