#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void encryption(string s, int k)
{
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='a' && s[i]<='z')
        {
            s[i]=char((s[i]-'a'+k)%26+'a');
        }
        else if(s[i]>='A' && s[i]<='Z')
        {
            s[i]=char((s[i]-'A'+k)%26+'A');
        }
    }
    cout<<s<<endl;
    cout<<endl;
}

void decryption(string s, int k)
{
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='a' && s[i]<='z')
        {
            s[i]=char((s[i]-'a'-k+26)%26+'a');
        }
        else if(s[i]>='A' && s[i]<='Z')
        {
            s[i]=char((s[i]-'A'-k+26)%26+'A');
        }
    }
    cout<<s<<endl;
    cout<<endl;
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
                cin>>s>>k;
                encryption(s, k);
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