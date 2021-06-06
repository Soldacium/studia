#include <stdio.h>
#include <stdlib.h>


void program(){
    int W, K;

    printf("\nPodaj ilosc wierszu macierzy A: ");
    scanf("%d",&W);

    printf("Podaj ilosc kolumn macierzy A: ");
    scanf("%d",&K);

    int A[K][W], B[W];

    printf("\nTwoja macierz ma wymiary: A(%d x %d) ",W,K);

    printf("\nWypelnij macierz A(%d x %d):",W,K);
    for(int i = 0; i < W; i++){

        for(int j = 0; j < K; j++){
            printf("A%d%d:",i + 1,j + 1);
            scanf("%d",&A[i][j]);
        }
    }

    printf("\nTwoja macierz: ");

    for(int i = 0; i < W; i++){
        printf("\n[");
        for(int j = 0; j < K; j++){
            printf("%d ",A[i][j]);
        }
        printf("]");
    }


    int sumaWiersza = 0;
    printf("\nWektor B:");
    printf("\n[");
    for(int i = 0; i < W; i++){
        sumaWiersza = 0;
        for(int j = 0; j < K; j++){
            sumaWiersza += A[i][j];
        }
        B[i] = sumaWiersza;
        printf("%d ",B[i]);
    }
    printf("]");
}
int main()
{
    program();
    return 0;
}
