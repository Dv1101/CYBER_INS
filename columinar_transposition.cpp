#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

void encryption(string s)
{
    char array[s.size()];
    for(int i=0; i<s.size(); i++)
    {
        array[i] = s[i];
    }
    char matrix [4][4];
    int row =0, col =0;
    
    for(char c : array)
    {
            if(row != 4)
            {
                matrix[row][col] = c;
                row++;
            }
            else{
                row=0;
                col++;
            }
    }
    string cipher;
    for(int col=0; row<4; row++)
    {
        for(int row=0; row<4; row++)
        {
            string s(1, matrix[row][col]);
            
            cipher.append(s);
        }
    }
    cout<<cipher;
}

void decryption(string s, int k)
{
    
}



int main()
{
    string s;
    int k;
    bool flag = true;

    while(flag)
    {
        int choice;
        cout<<"Enter choice :";
        cout<<"\n1) Encryption -";
        cout<<"\n2) Decryption -";
        cout<<"\n3) Exit\n\n";
        cin>>choice;

        switch (choice)
        {
            case 1:
                cout<<"Enter string and key value :";
                cin>>s;
                encryption(s);
                break;

            case 2:
                cout<<"Enter string and key value :";
                cin>>s>>k;
                decryption(s, k);
                break;

            case 3:
                flag = false;
                break;
            
            default:
                cout<<"\n !!!! Invalid choice   !!!! \n";
                break;
        }
    }
    
    
}