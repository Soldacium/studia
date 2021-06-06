#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define n 100

//7

double szereg(double x){
    double suma = 1.0, w = 1.0;
    double licznik = 1., mianownik = 3.;
    for(int i=1; i<=n; i++){
        w = pow(-1,i)*(licznik/mianownik)*pow(x,i);
        licznik = licznik * (i * 3 + 1);
        mianownik = mianownik * (i * 3 + 3);
        suma += w;
    }
    return suma;
}

double funkcja(double x){
    return pow((1 + x),-(1./3.));
}


int main(){
     int lp;
     double a = -10, b = 10, szsin, krok, x;

     while(a <= -1 && b >= 1){
        printf("podaj konce przedzialow i liczbe podprzedzialow\n");
        scanf("%lf %lf %d",&a,&b,&lp);
     }

     krok=(b-a)/lp;

     printf("krok=%6.2lf\n\n\n",krok);
     printf(" ----------------------------\n\n");
     printf(" x szereg(x) pow((1 + x),-(1./3.))\n ----------------------------\n");

     for (x=a;x<=b;x+=krok){
        printf("%10.2lf %7.4lf %7.4lf\n",x,szereg(x),funkcja(x));
     }

     printf(" ----------------------------\n\n");
}
