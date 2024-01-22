#include <iostream>
#include <math.h>
using namespace std;

int add(int a, int b)
{
	return a + b;
}

double add(int a, double b) {
	return a * 1.0 + b;
}

double* add(double a[2], double b[2]) {
	double arr[2] = { a[0] + b[0], a[1] + b[1] };
	return arr;
}

