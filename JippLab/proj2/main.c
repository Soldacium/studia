#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getSumaCyfr(int x){
   int suma = 0;
   while (x != 0){
       suma = suma + x % 10;
       x = x/10;
   }
   return suma;
}


void program(int n){
    int koniec;
    // mozna jeszcze sprawic zeby max liczb bylo rowniez sczytywane z klawiatury
    /*
    int n;
    printf("Ile liczb maksymalnie?: ");
    scanf("%d",&n);
    */
    printf("Jaka liczba konczy program wczesniej?: ");
    scanf("%d",&koniec);

    printf("Podaj liczby (max %d)\n", n);
    int i = 0, liczba, tab[n];
    while(i < n && liczba != koniec){
        printf("%d:", i);
        scanf("%d", &liczba);
        if(liczba > 9 && liczba < 1000){
            tab[i] = liczba;
            i += 1;
        }
    }

    int sumaCyfr = 0, sumaLiczb = 0, ostatniTab = i;
    for(i = 0; i < ostatniTab; i++){
        sumaCyfr = getSumaCyfr(tab[i]);
        if(sumaCyfr % 2 == 1){
            sumaLiczb += tab[i];
        }
    }

    printf("\nSuma liczb podanych przez uzytkownika, ktorych suma cyfr jest nieparzysta wynosi: ");
    printf("%d", sumaLiczb);
}

int main()
{
    program(100);
    return 0;
}
