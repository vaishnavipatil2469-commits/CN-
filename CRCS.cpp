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
    string data, generator;

    cout << "========== CRC SENDER SIDE ==========\n";

    cout << "Enter Data Bits: ";
    cin >> data;

    cout << "Enter Generator: ";
    cin >> generator;

    // Number of extra zero bits
    int extraBits = generator.length() - 1;

    cout << "\nOriginal Data Bits       : " << data << endl;
    cout << "Generator                : " << generator << endl;
    cout << "Number of Extra 0 Bits   : " << extraBits << endl;

    // Add extra zeros
    string dataWithZeros = data + string(extraBits, '0');

    cout << "Data + Extra 0 Bits      : "
         << dataWithZeros << endl;

    // Calculate CRC
    string crc = divideCRC(dataWithZeros, generator);

    cout << "CRC Remainder             : "
         << crc << endl;

    // Final transmitted data
    string transmittedData = data + crc;

    cout << "Transmitted Data          : "
         << transmittedData << endl;

    cout << "\n======================================\n";

    return 0;
}


// ========== CRC SENDER SIDE ==========
//Enter Data Bits: 10000111010
//Enter Generator: 1100

//Original Data Bits       : 10000111010
//Generator                : 1100
//Number of Extra 0 Bits   : 3
//Data + Extra 0 Bits      : 10000111010000
//CRC Remainder             : 100
//Transmitted Data          : 10000111010100