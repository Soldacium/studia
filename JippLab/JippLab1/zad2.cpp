#include <iostream>
#include <math.h>
using namespace std;


int forIndex(int*& arr) {
    int arrSize = sizeof(arr) / sizeof(int);
    for (int i = 0; i < arrSize; i++) {
        cout << log10(arr[i]);
    }
}


int forPointer(int*& arr) {

    for (; *arr != -1; ++arr)
        printf("%d", *arr);
}

int whileIndex(int*& arr) {
    int arrSize = sizeof(arr) / sizeof(int);
    int i = 0;
    while (i < arrSize) {
        cout << log10(arr[i]);
        i++;
    }
}

int whilePointer(int*& arr) {
    while (*arr != -1) {
        printf("%d", *arr);
        ++arr;
    }
        
}


int main()
{
    std::cout << "Hello World!\n";
}