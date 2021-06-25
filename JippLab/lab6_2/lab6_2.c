#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 7
typedef struct MY_VECTOR
{
    int dim; //rozmiar wektora
    char str[64]; //nazwa wektora
    double* buff; //tablica dla przechowywania wektora o rozmiarze dim
} MY_VECTOR;

void initVector(MY_VECTOR *vector) {
    printf("inicjalizacja %s\n", vector->str);
    int size = vector->dim;
    double newTab[size];
    memset(newTab, 0, size * sizeof(double));
    //vector->buff = newTab;//(double*)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        printf("podaj wartosc nr. %d: ", i);
        //scanf("%lf", vector->buff[i]);
    }
}

void freeSpace(MY_VECTOR* vector) {

}

void calculateScalar(MY_VECTOR vector1, MY_VECTOR vector2, int dim) {
    int wynik = 0;
    for (int i = 0; i < dim; i++) {

    }
}

void testZad7() {
    MY_VECTOR vector1, vector2;
    int vectorSize = -1;
    
    while (vectorSize < 0) {
        printf("Podaj wielkosc wektorow: \n ");
        scanf("%d", &vectorSize);
    }

    vector1.dim = vectorSize;
    vector2.dim = vectorSize;

    printf("Podaj nazwy wektorow\n ");
    printf("wektor1:\n ");
    scanf("%s", &vector1.str);
    printf("wektor1:\n ");
    scanf("%s", &vector2.str);
    printf("\n\n");

    initVector(&vector1);



}

int main(){
    printf("Lab 6\n");
    testZad7();

    return 1;
}