#include <iostream>
#include <math.h>
using namespace std;

void macierze() {
	int** matrix1;
	int **matrix2;
	int rows, cols;
	cout << "Liczba wierszy:" << endl;
	cin >> rows;
	cout << "Liczba kolumn" << endl;
	cin >> cols;
	matrix1 = new int* [rows]; 
	matrix2 = new int* [rows];
	for (int i = 0; i < rows; ++i) {
		matrix1[i] = new int[cols];
		matrix2[i] = new int[cols];
	}
}