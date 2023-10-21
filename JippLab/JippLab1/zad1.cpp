// JippLab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int factorialIteration(int x) {
    int res = 1;
    for (int i = 2; i <= x; i++) {
        res *= i;
    }
    return res;
}

long int factorialRecursion(int n) {
    if (n >= 1)
        return n * factorialRecursion(n - 1);
    else
        return 1;
}

int fibbonacci(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return (fibbonacci(n - 1) + fibbonacci(n - 2));
    }
}

int isPrime(int n) {
    int i;

    if (n == 2)
        return 1;

    if (n % 2 == 0)
        return 0;

    for (i = 3; i <= sqrt(n); i += 2)
        if (n % i == 0)
            return 0;

    return 1;
}

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
