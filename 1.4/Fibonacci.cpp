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

int countOnes(const string& binary)
{
    return count(binary.begin(), binary.end(), '1');
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

    for(const auto& num : fibonacci)
    {
        string binary = toBinary(num);
        if (countOnes(binary) == 6)
        {
            outFile << binary << "\n";
        }
    }

    outFile.close();
    return 0;
}
