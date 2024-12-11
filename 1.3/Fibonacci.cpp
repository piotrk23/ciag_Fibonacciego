#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

string toBinary(long long num)
{
    string binary = "";
    while (num > 0)
    {
        binary = (num % 2 == 0 ? "0" : "1") + binary;
        num /= 2;
    }
    return binary;
}

int main()
{
    const char* fileName = "wyniki.txt";

    ofstream outFile(fileName);
    if (!outFile)
    {
        cerr << "Error: Could not open the file " << fileName << " for writing.\n";
        return 1;
    }

    vector<long long> fibonacci;
    long long fib1 = 0, fib2 = 1;

    fibonacci.push_back(fib1);
    fibonacci.push_back(fib2);

    for (int i = 3; i <= 40; ++i)
    {
        long long nextFib = fib1 + fib2;
        fibonacci.push_back(nextFib);
        fib1 = fib2;
        fib2 = nextFib;
    }

    vector<string> binaryRepresentations;
    size_t maxBinaryLength = 0;

    for (const auto& num : fibonacci)
    {
        string binary = toBinary(num);
        binaryRepresentations.push_back(binary);
        maxBinaryLength = max(maxBinaryLength, binary.length());
    }

    for (auto& binary : binaryRepresentations)
    {
        while (binary.length() < maxBinaryLength)
        {
            binary = "0" + binary;
        }
    }

    outFile << "Binary representations of Fibonacci numbers:\n";

    for (const auto& binary : binaryRepresentations)
    {
        outFile << binary << "\n";
    }

    outFile << "\nBinary Fractal Fibonacci:\n";
    for (const auto& binary : binaryRepresentations)
    {
        for (char bit : binary)
        {
            outFile << (bit == '1' ? '#' : ' ');
        }
        outFile << "\n";
    }

    outFile.close();
    return 0;
}
