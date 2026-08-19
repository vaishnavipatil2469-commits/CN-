#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string code;

    cout << "===== RECEIVER SIDE =====" << endl;

    cout << "Enter received Hamming code: ";
    cin >> code;

    int n = code.length();

    // Check whether input contains only 0 and 1
    for (char c : code)
    {
        if (c != '0' && c != '1')
        {
            cout << "Invalid input! Enter only 0 and 1." << endl;
            return 0;
        }
    }

    // Hamming positions are numbered from right to left
    vector<int> h(n + 1);

    for (int i = 1; i <= n; i++)
    {
        h[i] = code[n - i] - '0';
    }

    // Find number of parity bits
    int r = 0;

    while ((1 << r) < (n + 1))
    {
        r++;
    }

    cout << "\nNumber of bits = " << n << endl;
    cout << "Number of parity bits = " << r << endl;

    // Calculate error position
    int errorPosition = 0;

    cout << "\nReceiver Parity Values:" << endl;

    for (int p = 0; p < r; p++)
    {
        int parityPosition = (1 << p);
        int parity = 0;

        for (int i = 1; i <= n; i++)
        {
            if (i & parityPosition)
            {
                parity = parity ^ h[i];
            }
        }

        cout << "R" << parityPosition << " = " << parity << endl;

        if (parity == 1)
        {
            errorPosition += parityPosition;
        }
    }

    cout << "\nError Position = " << errorPosition << endl;

    // Check and correct error
    if (errorPosition == 0)
    {
        cout << "No Error Detected!" << endl;
    }
    else if (errorPosition <= n)
    {
        cout << "Error Detected at Position "
             << errorPosition << endl;

        // Correct the error
        h[errorPosition] = h[errorPosition] ^ 1;

        cout << "Error Corrected!" << endl;
    }
    else
    {
        cout << "Invalid error position!" << endl;
        return 0;
    }

        cout << "\nCorrected Hamming Code = ";

    for (int i = n; i >= 1; i--)
    {
        cout << h[i];
    }

    cout << endl;

    cout << "Original Data = ";

    for (int i = n; i >= 1; i--)
    {   
     if ((i & (i - 1)) != 0)
        {
            cout << h[i];
        }
    }

    cout << endl;

    return 0;
}