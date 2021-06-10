
#include <stdio.h>
#include <stdlib.h>
#include "algorytmy.h"
#include <time.h>



void save_ints(int *arr, int n) {
    FILE* file = fopen("dane.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d\n", arr[i]);
    }
    fclose(file);
}

void read_ints(int *arr)
{
    FILE* file = fopen("dane.txt", "r");
    int i = 0;
    int lineNum = 0;

    fscanf(file, "%d", &i);
    while (!feof(file))
    {
        fscanf(file, "%d", &i);
        arr[lineNum] = i;
        lineNum++;
    }
    fclose(file);
}

// for functions other than quicksort;
void testFunction(void(*f)(int* arr, int n), int n) {

    int* arr;

    arr = (int*)malloc(n * sizeof(int));
    read_ints(arr);

    clock_t begin, end;
    begin = clock();

    (*f)(arr, n);
    end = clock();
    printf("time to sort: %f \n", (double)(end - begin) / CLOCKS_PER_SEC);

}

testQuick(int n) {
    int* arr;

    arr = (int*)malloc(n * sizeof(int));
    read_ints(arr);

    clock_t begin, end;
    begin = clock();
    quick_sort(arr, n, 0, n - 1);
    end = clock();
    printf("time to sort: %f \n", (double)(end - begin) / CLOCKS_PER_SEC);

}


int main()
{
    // INIT
    int* arr;
    int n = -1;
    printf("wybierz wielkosc tablicy: ");
    while (n < 0 || n > 1000000) {
        scanf("%d",&n);
        printf("\n");
    }    
    
    arr = (int*)malloc(n * sizeof(int));    
    // RANDOM; possible Sorted and SortedReverse
    fillArrayWithRandom(arr, n);
    save_ints(arr, n); 

    // GROUP A
    /*
    printf("---- GROUP I ----\n");
    testFunction(bubble_sort, n);
    testFunction(selection_sort, n);
    testFunction(insert_sort, n);    

    printf("---- GROUP II ----\n");
    testFunction(shell_sort, n);    
    testQuick(n); 
    */
  
   
    // GROUP B

    testFunction(heap_sort, n);


    
    return 0;

}

