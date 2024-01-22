#include <iostream>
#include <string>
using namespace std;

void addToRef(int& a, int reps, int addedValue) {
	for (int i = 0; i < reps; i++) {
		a += addedValue;
	}
}