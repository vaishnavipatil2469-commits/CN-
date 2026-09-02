#include <iostream>
#include <string>
using namespace std;

string divideCRC(string data, string generator)
{
    int n = generator.length();

    for (int i = 0; i <= data.length() - n; i++)
    {
        if (data[i] == '1')
        {
            for (int j = 0; j < n; j++)
            {
                data[i + j] =
                    (data[i + j] == generator[j]) ? '0' : '1';
            }
        }
    }

    return data.substr(data.length() - n + 1);
}

int main()
{
    string receivedData, generator;

    cout << "========== CRC RECEIVER SIDE ==========\n";

    cout << "Enter Received Data: ";
    cin >> receivedData;

    cout << "Enter Generator: ";
    cin >> generator;

    // Number of extra bits
    int extraBits = generator.length() - 1;

    cout << "\nReceived Data : "
         << receivedData << endl;

    cout << "Generator: "
         << generator << endl;

    cout << "Extra 0 Bits: "
         << extraBits << endl;

    
    string remainder = divideCRC(receivedData, generator);

    cout << "CRC Remainder: "
         << remainder << endl;

    
    bool error = false;

    for (char bit : remainder)
    {
        if (bit != '0')
        {
            error = true;
            break;
        }
    }

    if (error)
    {
        cout << "\nResult: ERROR DETECTED!" << endl;
    }
    else
    {
        cout << "\nResult: NO ERROR" << endl;
        cout << "Data received successfully." << endl;
    }

    cout << "========================================\n";

    return 0;
}
//Enter Received Data: 1000111010100
//Enter Generator: 1100

//Received Data : 1000111010100
//Generator: 1100
//Extra 0 Bits: 3
//CRC Remainder: 000

//Result: NO ERROR
//Data received successfully.