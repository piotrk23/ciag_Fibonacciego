#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    const char* fileName = "wyniki_1.txt";

    ofstream outFile(fileName);
    if (!outFile)
    {
        cerr << "Error: Could not open the file " << fileName << " for writing.\n";
        return 1;
    }

    long long fib1 = 0, fib2 = 1;

    for (int i = 2; i <= 40; ++i)
    {
        long long nextFib;
        nextFib = fib1 + fib2;

        if (i == 10 || i == 20 || i == 30 || i == 40)
        {
            outFile << nextFib << "\n";
        }

        fib1 = fib2;
        fib2 = nextFib;

    }

    outFile.close();
    return 0;
}

