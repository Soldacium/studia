#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 10

// 13
void fillArray(int *array, int size){
    srand(time(NULL));
    // will print 4 because array is "just int", not array of ints, and int is 4 bytes
    printf("size: %d ",sizeof(array));

    for(int i = 0; i < size; i++){
        array[i] = (rand() % 10) + 1;
        checkArray(array,i+1);
    }

    return;
}

void checkArray(int *array, int size){
    printf("\n");
    static int numOfOperations = 0;
    for(int i = 0; i < size; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    // will print 4 because array is "just int", not array of ints, and int is 4 bytes
    printf("size: %d ",sizeof(array));
    numOfOperations += 1;
    printf("total operations: %d", numOfOperations);
    return;
}

// 24 & 25
void program2(){
    //random array
    int arr2d[N][N];
    srand(time(NULL));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            arr2d[i][j] = (rand() % 10) + 1;
            printf("%d ",arr2d[i][j]);
        }
        printf("\n");
    }
    // 24
    int a = 3,b = 6;
    int suma = 0;
    for(int i = 0; i < N - 1; i++){
        if(arr2d[i + 1][i] >= a && arr2d[i + 1][i] <= b){
            suma += arr2d[i + 1][i];
        }
    };
    printf("\n\n 24: %d",suma);
    // 25
    int suma2 = 0;
    for(int i = 0; i < N; i++){
        if(sin(arr2d[i][i])>= 0){
            suma2 += arr2d[i][i];
        }
    };

    for(int i = 0; i < N; i++){
        if(sin(arr2d[i][N - i - 1]) >= (1./2.)){
            suma2 += arr2d[i][N - i -1];
        }
    };
    printf("\n\n 25: %d",suma2);
}

int main()
{
    /*
    int arr[10];
    // will print 40 because it holds 10 x Int, which is 4bytes
    printf("size: %d ",sizeof(arr));
    fillArray(&arr, 10);
    */
    program2();
    return 0;
}
