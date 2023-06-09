#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void encryption(ifstream& file_in, ofstream& file_out, int k)
{
    string line;
    while (getline(file_in, line))
    {
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] >= 'a' && line[i] <= 'z')
            {
                line[i] = char((line[i] - 'a' + k) % 26 + 'a');
            }
            else if (line[i] >= 'A' && line[i] <= 'Z')
            {
                line[i] = char((line[i] - 'A' + k) % 26 + 'A');
            }
        }
        file_out << line << endl;
    }
}

void decryption(ifstream& file_in, ofstream& file_out, int k)
{
    string line;
    while (getline(file_in, line))
    {
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] >= 'a' && line[i] <= 'z')
            {
                line[i] = char((line[i] - 'a' - k + 26) % 26 + 'a');
            }
            else if (line[i] >= 'A' && line[i] <= 'Z')
            {
                line[i] = char((line[i] - 'A' - k + 26) % 26 + 'A');
            }
        }
        file_out << line << endl;
    }
}

int main()
{
    string inputFileName, outputFileName;
    int k;
    bool flag = true;

    while (flag)
    {
        int choice;
        cout << "Enter choice :";
        cout << "\n1) Encryption -";
        cout << "\n2) Decryption -";
        cout << "\n3) Exit\n\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter input file name, output file name, and key value: ";
            cin >> inputFileName >> outputFileName >> k;
            {
                ifstream file_in(inputFileName);
                ofstream file_out(outputFileName);
                if (file_in.is_open() && file_out.is_open())
                {
                    encryption(file_in, file_out, k);
                    file_in.close();
                    file_out.close();
                    cout << "Encryption completed.\n";
                }
                else
                {
                    cout << "Failed to open files.\n";
                }
            }
            break;

        case 2:
            cout << "Enter input file name, output file name, and key value: ";
            cin >> inputFileName >> outputFileName >> k;
            {
                ifstream file_in(inputFileName);
                ofstream file_out(outputFileName);
                if (file_in.is_open() && file_out.is_open())
                {
                    decryption(file_in, file_out, k);
                    file_in.close();
                    file_out.close();
                    cout << "Decryption completed.\n";
                }
                else
                {
                    cout << "Failed to open files.\n";
                }
            }
            break;

        case 3:
            flag = false;
            break;

        default:
            cout << "\n !!!! Invalid choice   !!!! \n";
            break;
        }
    }

    return 0;
}
