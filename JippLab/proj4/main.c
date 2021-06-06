#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>




long long int power(long long int x, unsigned long long int y, long long int p){
    long long int res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1) {
            res = (res*x) % p;
        }
        // podzielic przez 2 i zaokraglic w dol
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

bool miillerTest(long long int d, long long int n){

    long long int a = 2 + rand() % (n - 4);
    long long int x = power(a, d, n);

    if (x == 1  || x == n-1) { return true; }

    while (d != n-1) {
        x = (x * x) % n;
        d *= 2;
        if (x == 1){ return false; }
        if (x == n-1){ return true; }
    }

    // jest zlozona
    return false;
}

bool czyPierwsza(long long int n, int k){

    if (n <= 1 || n == 4) { return false; }
    if (n <= 3) { return true; }

    long long int d = n - 1;
    while (d % 2 == 0){
        d /= 2;
    }

    for (int i = 0; i < k; i++) {
        if (!miillerTest(d, n)) {
            return false;
        }
    }
    return true;
}

void program1() {
    int k = 0;
    long long int liczba = 0;
    do {
        printf("Podaj liczbe do sprawdzenia czy jest pierwsza: ");
        scanf("%lli",&liczba);
        printf("%lld",liczba);
        if(liczba < 2) {
            printf("/nLiczba jest za mala! (albo za duza na long long int, max 2^64 <17znakow)");
        }
    } while(liczba < 2);

    do {
        printf("\nJak dokladne powinno byc sprawdzenie? (liczba iteracji): ");
        scanf("%i",&k);
    } while(k < 1);

    if (czyPierwsza(liczba, k)) {
        printf("\nliczba %lld jest prawdopodobnie pierwsza", liczba);
    } else {
        printf("\nliczba %lld prawdopodobnie nie jest pierwsza", liczba);
    }
}




int symbolNaLiczbe(char symbol){
    // '' dla pojedynczego char
    if (symbol == 'I') { return 1; }
    if (symbol == 'V') { return 5; }
    if (symbol == 'X') { return 10; }
    if (symbol == 'L') { return 50; }
    if (symbol == 'C') { return 100; }
    if (symbol == 'D') { return 500; }
    if (symbol == 'M') { return 1000; }
    return -1;
}

int rzymskaNaArabska(char rzymska[]){
    int wynik = 0;

    for (int i = 0; i < strlen(rzymska); i++) {
        int symbol1 = symbolNaLiczbe(rzymska[i]);
        if (i + 1 < strlen(rzymska)) {
            int symbol2 = symbolNaLiczbe(rzymska[i + 1]);
            if (symbol1 >= symbol2){
                wynik += symbol1;
            } else {
                wynik += symbol2 - symbol1;
                i++;
            }
        } else {
            wynik += symbol1;
        }
    }
    return wynik;
}

const int MAX_LICZB = 100;
const int MAX_DLUGOSC = 100;
struct liczba{
    char rzymska[100];
    int arabska;
};
struct liczba liczby[100];

void program2(){
    const char stop[] = "-1";

    printf("Wpisz liczby rzymskie do dodania, oddzielone spacja(np. I III): \n");
    printf("(Wpisz %s aby zakonczyc, max %d liczb, max %d znakow)\n", stop, MAX_LICZB, MAX_DLUGOSC);

    int i = 0;
    char dodawaneLiczby[MAX_DLUGOSC];

    while (liczby != "-1" && i < 5) {
        gets(dodawaneLiczby);
        memcpy(liczby[i].rzymska, dodawaneLiczby,strlen(dodawaneLiczby));
        if (liczby != stop && strlen(dodawaneLiczby) < MAX_DLUGOSC) {
            i++;
        } else {
            break;
        }
    }

    for(int n = 0; n < i; n++){
        char * token = strtok(liczby[n].rzymska, " ");

        int wynik = 0;
        while( token != NULL ) {
            wynik += rzymskaNaArabska(token);
            token = strtok(NULL, " ");
        }
        printf( "\n%d", wynik );
    }
}


struct ciag {
    int zakodowany[25];
    int klucz;
    int iloscRozwiazan;
    int iloscLiczb;
};

struct ciag ciagi[25];
const int ILOSC_PIERWSZYCH = 5;
const int pierwsze[] = {127, 131, 137, 139, 149};

int sprawdzCiag(int numerCiagu){
    int rozwiazania = 0, zgodnosc = 0, rozwiazanie = 0;
    //printf("\n%d %d",ciagi[numerCiagu].iloscRozwiazan, ciagi[numerCiagu].iloscLiczb);
    for(int i = 0; i < ILOSC_PIERWSZYCH; i++){
        zgodnosc = 0;
        for(int j = 0; j < ciagi[numerCiagu].iloscLiczb; j++){

            if(ciagi[numerCiagu].zakodowany[j]%pierwsze[i] > 64 && ciagi[numerCiagu].zakodowany[j]%pierwsze[i] < 91){
                zgodnosc++;
            }
        }
        if(zgodnosc == ciagi[numerCiagu].iloscLiczb){
            rozwiazania++;
            rozwiazanie = pierwsze[i];
        }
    }
    if(rozwiazania == 1){
        return rozwiazanie;
    } else {
        return 0;
    }
}

void wypiszLiteryCiagu(int numerCiagu, int klucz){
    int iloscLiter = ciagi[numerCiagu].iloscLiczb;
    char slowo[iloscLiter];
    // nie wiem dlaczego, ale niektore kompilatory blednie wypisywaly slowo dodajac na koncu jakies znaki, na repl.it dziala dobrze; codeblocks prawie
    for(int i = 0; i < iloscLiter; i++) {

        slowo[i] = ciagi[numerCiagu].zakodowany[i]%klucz;
    }
    printf("\n%d %s",klucz,slowo);
}

void program3(){
    int max_ciagow;
    int max_liter = -1;
    do {
        printf("Podaj ilosc ciagow: ");
        scanf("%i", &max_ciagow);
    } while(max_ciagow < -1 || max_ciagow > 25);

    // int ciagi[max_ciagow][25];

    for(int i = 0; i < max_ciagow; i++) {
        max_liter = -1;
        printf("\n(Ciag %d)\n",i);
        while(max_liter < 1 || max_liter > 25) {
            printf("\nPodaj ilosc liter: ");
            scanf("%i *[^\n]", &max_liter);
        }

        int cyfry[max_liter];
        // moznaby wziac cala linie i oddzielic spacjami a potem sprawdzic (jak przy dodawaniu rzymskich)
        // i porownac z zadeklarawana liczba znakow, ale to wiecej pracy a efekt ten sam (chyba ¿e to by³o czêœci¹ zadania)

        ciagi[i].iloscLiczb = max_liter;
        for(int j = 0; j < max_liter; j++) {
            scanf("%i", &cyfry[j]);
            ciagi[i].zakodowany[j] = cyfry[j];
        }
    }
    int klucz;

    for(int i = 0; i < max_ciagow; i++){
        klucz = sprawdzCiag(i);
        if(klucz != 0){
            wypiszLiteryCiagu(i,klucz);
        } else {
            printf("\nNIECZYTELNE");
        }
    }
}

int main()
{
    // program1();
    // program2();
    // program2();
    return 0;
}
