#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void odwracanie(){
    int macierz[3][3] = {{2,4,3},{5,2,3},{1,2,3}};

    int detA = 0, liczba = 1;
    for(int i = 0; i < 3; i++){
        liczba = 1;
        for(int j = 0; j < 3; j++){
            liczba *= macierz[(j + i)%3][j];
        }
        detA += liczba;
    }

    for(int i = 0; i < 3; i++){
        liczba = 1;
        for(int j = 0; j < 3; j++){
            liczba *= macierz[(6 - j + i)%3][j];
        }
        detA -= liczba;
    }

    if(detA == 0){
        return;
    }

    int macierzDopelniona[3][3];

    for(int i = 0; i < 3; i++){
        liczba = 1;
        for(int j = 0; j < 3; j++){
            macierzDopelniona[i][j];
        }
    }

    printf("%d",detA);
}

void mnozenieMacierzy(){

    int W, K;

    printf("\nPodaj ilosc wierszu macierzy A: ");
    scanf("%d",&W);

    printf("Podaj ilosc kolumn macierzy A: ");
    scanf("%d",&K);

    int A[K][W], B[W][K], wielkoscC, X;
    if(K < W){
        wielkoscC = K;
        X = W;
    }else{
        wielkoscC = W;
        X = K;
    }
    int C[wielkoscC][wielkoscC];
    printf("\nTwoje macierze maja wymiary: A(%d x %d) B(%d x %d) ",W,K,K,W);

    printf("\nWypelnij macierz A(%d x %d):",W,K);
    for(int i = 0; i < W; i++){

        for(int j = 0; j < K; j++){
            printf("A%d%d:",i + 1,j + 1);
            scanf("%d",&A[i][j]);
        }
    }

    printf("\nWypelnij macierz B(%d x %d):",K,W);
    for(int i = 0; i < K; i++){

        for(int j = 0; j < W; j++){
            printf("B%d%d:",i + 1,j + 1);
            scanf("%d",&B[i][j]);
        }
    }

    int suma = 0;
    printf("Pomnozona macierz:");
    for(int i = 0; i < wielkoscC; i++){
        printf("\n[");
        for(int j = 0; j < wielkoscC; j++){
            suma = 0;
            for(int k = 0; k < X; k++){
                suma += A[i][k] * B[k][j];
            }
            C[i][j] = suma;
            printf("%d ", suma);
        }
        printf("]");
    }




}

void sito(int n){

    if(n < 2){
        return;
    }
    int tab[n];
    memset(tab, 0, sizeof tab);

    for (int i = 2; i < n; i++) {
        for (int j = i * i; j < n; j+=i) {
            tab[j - 1] = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        if (tab[i - 1] == 0)
            printf("%d ",i);
    }
}
int main()
{
    // odwracanie();
    // sito(36);
    mnozenieMacierzy();
    return 0;
}
