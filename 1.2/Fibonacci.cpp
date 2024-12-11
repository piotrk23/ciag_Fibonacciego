#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// Function to check if a number is prime
bool isPrime(long long num)
{
    if (num < 2)
        return false;
    for (long long i = 2; i <= sqrt(num); ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
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

    long long fib1 = 0, fib2 = 1;

    for (int i = 1; i <= 40; ++i)
    {
        long long nextFib;
        if (i == 1)
            nextFib = 0;
        else if (i == 2)
            nextFib = 1;
        else
            nextFib = fib1 + fib2;

        if (isPrime(nextFib))
        {
            outFile << nextFib << "\n";
        }

        if (i > 2)
        {
            fib1 = fib2;
            fib2 = nextFib;
        }
    }

    outFile.close();
    return 0;
}
