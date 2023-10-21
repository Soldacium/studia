#include <iostream>
using namespace std;
#define ROWS 4
#define COLS 5

void func(int array[ROWS][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            cout <<  array[i][j];
        }
    }
}


int main() {

}