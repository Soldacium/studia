#include <iostream>
#include <string>
using namespace std;

template <typename T>
T max(T tab, int size) {
	if (size <= 0) return;
	int currentMax = tab[0];
	for (int i = 1; i < size; i++) {
		if(tab[i] > currentMax) currentMax = tab[i]
	}
	return currentMax;

}