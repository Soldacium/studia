#include <iostream>
#include <math.h>
using namespace std;

template <typename AnyType> 
void display(AnyType a){
	cout << a << endl;
}

template <typename AnyType>
void display(AnyType a, int lenH, int lenV){
	for (int i = 0; i < lenH; i++){
		for (int j = 0; j < lenV; j++)
		cout << a[i][j] << endl;
	}
}