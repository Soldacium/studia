#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void program1(){
    int tab1[10] = {1,2,3,4,5,6,7,8,9,10};
    int tab2[10];

    for(int i = 0; i < 10; i++){
        tab2[i] = tab1[i];

        printf("%d ", tab2[i]);
    }
}

void program2(){
    int tab[10];

    for(int i = 0; i < 10; i++){
        printf("Podaj liczbe %d :", i);
        scanf("%d", &tab[i]);
        printf("%d :", tab[i]);
    }


}

void program4(){
    char liczba[15];
    printf("Podaj liczbe: ");
    gets(liczba);

    printf("%c",liczba[6]);
    int dlugosc = strlen(liczba);

    for(int i = 0; i < dlugosc; i++){
        if(liczba[i] != liczba[dlugosc - i - 1]){
            printf("nie palindrom");
            return;
        }
    }

    printf("palindrom");
    return;
}



void program5(){

    int tab[10], zm;

    for(int i = 0; i < 10; i++){
        tab[i] = rand()%100;
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0;j < 10 - i; j++){
            if(tab[j] > tab[j + 1]){
                zm = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = zm;
            }
        }
    }
    for(int i = 0; i < 10; i++){
        printf("%d \n",tab[i]);
    }
}


void program6(){
    int tab[10], zm;

    for(int i = 0; i < 10; i++){
        tab[i] = rand()%100;
    }

    int i, key, j;

    for (i = 1; i < 10; i++) {
        key = tab[i];
        j = i - 1;

        while (j >= 0 && tab[j] > key) {
            tab[j + 1] = tab[j];
            j = j - 1;
        }
        tab[j + 1] = key;
    }

    for(int i = 0; i < 10; i++){
        printf("%d \n",tab[i]);
    }
}

void program7() {
    int i, j, min;
    int tab[10], zm;

    for(int i = 0; i < 10; i++){
        tab[i] = rand()%100;
    }

    for (i = 0; i < 10; i++) {
        min = i;
        for (j = i+1; j < 10; j++) {
           if (tab[j] < tab[min]) {
                min = j;
           }

        }
        zm = tab[min];
        tab[min] = tab[i];
        tab[i] = zm;
    }

    for(int i = 0; i < 10; i++){
        printf("%d \n",tab[i]);
    }
}

void program8(){
    int dlugosc;

    printf("Podaj dlugosc tekstu:\n");
    scanf("%d",&dlugosc);

    char tab[dlugosc];

    printf("Podaj tekst (maksymalna dlugosc tekstu: %d ):\n", dlugosc);
    scanf("%s", &tab);


    printf("\nWspak:\n");

    for(int i = dlugosc;i>0;i--){
        printf("%c",tab[i - 1]);
    }


}

void program9(){
    int dlugosc, przesuniecie, wybor;

    printf("Podaj dlugosc tekstu:\n");
    scanf("%d",&dlugosc);

    char tab[dlugosc];

    printf("Podaj tekst (maksymalna dlugosc tekstu: %d ):\n", dlugosc);
    scanf("%s", &tab);

    printf("\n\nSzyfrowac(1) czy rozszyfrowac(2)?:");
    scanf("%d",&wybor);

    printf("Jakie przesuniecie?:");
    scanf("%d",&przesuniecie);

    if(wybor == 1){
        szyfruj(tab,przesuniecie);
    }else if(wybor == 2){
        rozszyfruj(tab,przesuniecie);
    }

}

void szyfruj(char tab[], int przesuniecie){

    int dlugosc = strlen(tab);

   	for(int i=0;i<dlugosc;i++){
        tab[i] = ((tab[i] - 97 + przesuniecie) % 27) + 97;
   	}


    printf("\n\n\nPo zaszyfrowaniu:\n");

    for(int i = 0;i<dlugosc;i++){
        printf("%c",tab[i]);
    }
}

void rozszyfruj(char tab[], int przesuniecie){

    int dlugosc = strlen(tab);

   	for(int i=0;i<dlugosc;i++){
        tab[i] = ((tab[i] - 97 - przesuniecie) % 27) + 97;
   	}


    printf("\n\n\nPo rozszyfrowaniu:\n");

    for(int i = 0;i<dlugosc;i++){
        printf("%c",tab[i]);
    }
}

int main()
{

    program8();
    return 0;
}
