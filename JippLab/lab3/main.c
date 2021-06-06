#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sumaLiczbNaturalnych(int maximum){
    int suma = 0;

    for(int i = 0; i < maximum; i++){
        suma = suma + i;
    }

    printf("%d",suma);
}

// 13 liczba pierwsza, wiêc wystarcza wielokrotnosci
void program2(){
    for(int i = 0; i < 200; i = i + 13){
        printf("%d \n",i);
    }
}

void program3(int liczba){
    for(int i = 1; i <= liczba; i+=1){
        if (liczba % i == 0){
            printf("%d \n",i);
        }
    }
}

void program4(int liczba){
	if(liczba < 2){
        printf("nope");
        return;
	}


	for(int i = 2; i*i <= liczba; i++){
        if(liczba % i==0){
            printf("%d nie jest pierwsza",liczba);
            return;
        }
	}
	printf("%d jest pierwsza", liczba);
}

program5(){
    int liczba, wynik;

    while(liczba != 0){
        wynik = 1;
        printf("Podaj liczbe: ");
        scanf("%d", &liczba);

        if(liczba > 0){
            for (int i = 1; i <= liczba; i = i + 1){
                wynik = wynik * i;
            }
            printf("Silnia %d wynosi: %d \n\n",liczba, wynik);
        }
    }
}


int program6(int n){

    if (n <= 1) {
        return n;
    }
    return program6(n-1) + program6(n-2);

}

void program7(){
    int liczba1, liczba2;
    int reszta = 1;
    int wynik;

    printf("Podaj liczbe1: ");
    scanf("%d", &liczba1);

    printf("Podaj liczbe2: ");
    scanf("%d", &liczba2);

    if(liczba1 < liczba2){
        int pom = liczba1;
        liczba1 = liczba2;
        liczba2 = pom;
    }

    while(reszta != 0){
        reszta = liczba1 % liczba2;
        liczba1 = liczba2;
        liczba2 = reszta;
    }

    printf("NWD: %d \n",liczba1);
}

void program8(){
    int iloscLiczb = 0;
    float iloczynGeometryczny = 1, sumaArytmetyczna = 0;
    int liczba = -1;

    printf("Program do obliczania sredniej geometrycznej i artytmetycznej, podaje wynik po wpisaniu '0' \n\n");
    while(liczba != 0){

        printf("Podaj liczbe: ");
        scanf("%d", &liczba);
        if(liczba > 0){
            iloczynGeometryczny = iloczynGeometryczny * liczba;
            sumaArytmetyczna = sumaArytmetyczna + liczba;
            iloscLiczb = iloscLiczb + 1;
        }else{
            printf("Liczba nie moze by na minusie \n");
        }

    }

    printf("Srednia arytmetyczna: %f \n", (sumaArytmetyczna/iloscLiczb));
    printf("Srednia geometryczna: %f \n", (pow(iloczynGeometryczny, (1./iloscLiczb))));
}

void program9(int a,int b){
    for(int i = 0; i < a; i = i +1){
        for(int j = 0; j < b; j = j + 1){
            printf("*");
        }
        printf("\n");
    }
}



int main()
{
    //printf("%d",program6(8));
    return 0;
}
