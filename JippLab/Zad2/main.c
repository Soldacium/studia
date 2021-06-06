#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

void program1 (int liczba1, int liczba2) {
    int suma = liczba1 + liczba2;
    int roznica = liczba1 + liczba2;
    int iloczyn = liczba1 * liczba2;
    int modulo = liczba1 % liczba2;
    printf("Wyniki obliczen na liczbach %d i %d", liczba1, liczba2);
    printf("\n Suma: %d \n Iloczyn: %d \n Roznica: %d \n Modulo: %d \n ",suma,roznica,iloczyn,modulo);

}

// przy za³o¿eniu ¿e chodzi³o w zadaniu o sczytanie dwóch liczb,
// a nie sczytywanie ich w pêtli do tablicy i na koñcu podanie wyniku
void program2 () {
    float liczba1 = 0, liczba2 = 0;
    printf("\nPodaj pierwsza liczba ");
    scanf("%f", &liczba1);
    printf("\nPodaj druga liczna ");
    scanf("%f", &liczba2);

    printf("\nIloczyn tych liczb wynosi: %f", (liczba1*liczba2));
    printf("\nNatomiast iloraz: %f",(liczba1 / liczba2));

}

void program3 (float bokPodstawy1, float bokPodstawy2, float wysokosc) {

    float objetosc = bokPodstawy1 * bokPodstawy2 * wysokosc;
    float poleCalkowite =
    2 * bokPodstawy1 * bokPodstawy2 +
    2 * bokPodstawy1 * wysokosc +
    2 * bokPodstawy2 * wysokosc;

    printf("\nObjetosc wynosi: %f, a pole calkowite %f ", objetosc, poleCalkowite);
}

void program4 (float x, float u, float o){
    float gestosc = (1/o*sqrt(M_PI * 2))*exp((-pow(x-u,2))/2*pow(o,2));
    printf("Gestosc rozkladu normalnego w punkcie x wynosi: %f", gestosc );
}

void program5 (){
    int maxInt = pow(2,32) - 1; //(1 << 31) - 1
    short maxShortInt = pow(2,16) - 1;

    printf("Max int: %d \n",maxInt);
    printf("Max short int: %d \n",maxShortInt);
    printf("Max float: %e, min float: %e",FLT_MAX, FLT_MIN);

}

void program6 (){
    int liczba;
    printf("Podaj liczbe do sprawdzenia czy jest parzysta czy nie: ");
    scanf("%d", &liczba);

    if(liczba % 2 == 0){
        printf("\n Liczba %d jest parzysta",liczba);
    }else{
        printf("\n Liczba %d jest nieprzysta", liczba);
    }
}

void program7 (){

    float liczba1 = 0, liczba2 = 0;
    int input;

    printf("\nPodaj pierwsza liczba ");
    scanf("%f", &liczba1);
    printf("\nPodaj druga liczna ");
    scanf("%f", &liczba2);

    printf("\nObliczyc suma(1) czy roznice(2)? ");
    while(input != 0 && input != 1){
        scanf("%d", &input);
    }

    if(input = 1){
        printf("Suma podanych liczb(%f i %f) wynosi %f",liczba1, liczba2, liczba1 + liczba2);

    }else{
        printf("Roznica podanych liczb(%f i %f) wynosi %f",liczba1, liczba2, liczba1 - liczba2);
    }
}



void program8 (liczba1, liczba2){
    if(liczba1 >= liczba2){
        printf("Liczba %f stanowi %f liczby %f",liczba1, (liczba1/liczba2)*100, liczba2);

    }else{
        printf("Liczba %f stanowi %f liczby %f",liczba2, (liczba2/liczba1)*100, liczba1);

    }
}

void program9 (){
    float a,h,r;
    int wybor;

    while(wybor != 1 && wybor != 2 && wybor != 3){
        printf("Ktore pole obliczyc: kwadrat(1), trojkat(2) czy kolo(3)? \n");
        scanf("%d",&wybor);
    }


    switch(wybor){
        case 1:
            printf("Wpisz dlugosc boku kwadratu a: ");
            scanf("%f",&a);
            printf("\nPole kwadratu o boku %f wynosi %f",a,a*a);
            break;
        case 2: // bez sprecyzowania ktory wzor trojkata, najbardzije podstawowy

            printf("\nWpisz dlugosc boku a: ");
            scanf("%f",&a);

            printf("\nWpisz dlugosc wysokosci opuszczonej na bok a (zmienna h): ");
            scanf("%f",&h);

            printf("\nPole trojkata o boku %f opuszczonej na niego wysokosci %f wynosi: %f",a,h, a*h/2);
            break;
        case 3:
            printf("Wpisz promien kola r: ");
            scanf("%f",&r);
            printf("\nPole kola o promieniu %f wynosi %f",r, M_PI*r*r);
            break;
        default:
            printf("Cos poszlo nie tak... sproboj jeszcze raz");
    }
}

void program10(){
    float x,y;
    do{
        printf("Podaj x: ");
        scanf("%f",&x);
    }while(x <= 0);


    printf("Podaj y: ");
    scanf("%f",&y);

    float wynikF1, wynikF2, wynikF3;

    wynikF1 = log(x) + 10;
    wynikF2 = pow(1.5,x);
    wynikF3 = exp(x);



    if(
       (y > wynikF1 && y > wynikF2 && y > wynikF3) ||
       (y < wynikF1 && y < wynikF2 && y < wynikF3)
       ){

        printf("punkt (%f,%f) NIE LEZY miedzy funkcjami",x,y);

    }else{

        printf("punkt (%f,%f) LEZY miedzy funkcjami y=log(x) + 10 & y= 1.5^x & y = exp(x)",x,y);
    }
}

void program11(){

    // mozna ulepszyc przez podawanie wszykich zmiennych z klawiatury
    // i pokazania ostatecznego wygladu rownania
    float
    a1 = 1,
    b1 = 4,
    c1 = 8,

    a2 = 1,
    b2 = 4,
    c2 = 9;

    float W = a1*b2 - a2*b1, Wx = c1*b2-c2*b1, Wy = a1*c2-a2*c1;
    printf("%f,%f,%f \n", W, Wy, Wx);
    if(W != 0){
            printf("Rozwiazaniem rownania jest x = %f i y = %f",Wx/W,Wy/W);

    }else if(W = 0 && (Wx != 0 || Wy != 0)){
        printf("Brak rozwiazan!");
    }else{
        printf("Nieskonczonosc rozwiazan!");
    }


}

int main() {

    // program1(10,10);
    //program3(4.5,4.5,6);
    //program7();

    program5();

    return 0;
}
