#include "algorytmy.h"
#include <math.h>
#include <time.h>

#define MIN -100
#define MAX 100

// UTILS
void swap(int* arr, int leftIndex, int rightIndex) {
	const temp = arr[leftIndex];
	arr[leftIndex] = arr[rightIndex];
	arr[rightIndex] = temp;
}

void fillArrayWithRandom(int* arr, int n) {
	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		arr[i] = (rand() % 100) * pow(-1,(rand() % 2));
	}
}

void fillArrayWithSorted(int* arr, int n) {
	int odst = n / (MAX - MIN) + 1;
	int currentFill = MIN;
	for (int i = 0; i < n; i++) {
		arr[i] = currentFill;
		if (i % odst == 0) {
			currentFill++;
		}
	}
}

void fillArrayWithSortedReverse(int* arr, int n) {
	int odst = n / (MAX - MIN) + 1;
	int currentFill = MAX;
	for (int i = 0; i < n; i++) {
		arr[i] = currentFill;
		if (i % odst == 0) {
			currentFill--;
		}
	}
}

// FIRST GROUP
// 
// OK
void insert_sort(int* arr, int n){
	int i, x, j;
	for (i = 1; i < n; i++){
		x = arr[i];
		j = i - 1;
		while (arr[j] > x && j >= 0){
			arr[j + 1] = arr[j]; j--;
		}
		arr[j + 1] = x;
	}
}

// OK
void bubble_sort(int* arr, int n) {
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j + 1] < arr[j]) {
				swap(arr, j, j + 1);
			}
		}	
	}
}

// OK
void selection_sort(int* arr, int n){
  int minIndex = 0;
  for (int i = 0; i < n - 1; i++) {
	minIndex = i;
	for (int j = i + 1; j < n; j++) {
	  if (arr[j] < arr[minIndex]) {
		minIndex = j;
	  }
	}
	swap(arr, minIndex, i);
  }
}


// SECOND GROUP

// QUICK SORT - OK
int partition(int* arr, int left, int right) {
	int arrayIndex = floor((right + left) / 2);
	int pivot = arr[arrayIndex];
	int i = left;
	int j = right;
	while (i <= j) {
		while (arr[i] < pivot) {
			i++;
		}
		while (arr[j] > pivot) {
			j--;
		}
		if (i <= j) {
			swap(arr, i, j);
			i++;
			j--;
		}
	}
	return i;
}

void quick_sort(int* arr, int n, int left, int right) {
  int index = 0;
  if (n > 1) {
    index = partition(arr, left, right); 
    if (left < index - 1) { 
      quick_sort(arr,n, left, index - 1);
    }
    if (index < right) { 
      quick_sort(arr,n, index, right);
    }
  }
}


void shell_sort(int* arr, int n){
	for (int gap = n / 2; gap > 0; gap /= 2){
		for (int i = gap; i < n; i += 1){
			int temp = arr[i];

			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];

			arr[j] = temp;
		}
	}
}

void heapify(int* arr, int n, int i){
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2; 

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i) {
		swap(arr, i, largest);

		heapify(arr, n, largest);
	}
}

void heap_sort(int* arr, int n){
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i > 0; i--) {
		swap(arr, 0, i);
		heapify(arr, i, 0);
	}
}

