#include <stdlib.h>
#include <stdio.h>
#include<math.h>
#define lp 1000;

double c_od, c_do;

extern double f3(double x)
{
    return 3*pow(sin(x),2)+cos(x * 9);
}
double f4(double x)
{
    return sin(2 * x) - 2 * sin(x);
}

double prostokaty(double(*f)(double)) {
    double krok, p, suma = 0;
    krok = (c_do - c_od) / lp;
    for (p = c_od; p < c_do; p += krok) {
        suma += (*f)(p) * krok;
    }
	return suma;
}

double trapezy(double(*f)(double x)) {
    double krok, p, suma = 0;
    krok = (c_do - c_od) / lp;
    
    // a,b so we calculate *f one time per iteration
    double a = (*f)(c_od), b;
    for (p = c_od; p < c_do - krok; p += krok) {
        b = (*f)(p + krok);
        suma += (a + b)*krok/2;
        a = b;
    }
	return suma;
}

double randf(double low, double high) {
    return (rand() / (double)(RAND_MAX)) * fabs(low - high) + low;
}

double mc(double(*f)(double x)) {
    int N = 1000000;
    double przedzialX, suma = 0, MIN = 0, MAX = 0, pole, n = 0, krok, wartoscF = 0;
    przedzialX = c_do - c_od;
    krok = przedzialX / lp;
    double Y = 0, X = 0;
    for (double i = c_od; i < c_do; i += krok) {
        Y = (*f)(i);
        if (Y > MAX) {
            MAX = Y;
        } 
        else if (Y < MIN) {
            MIN = Y;
        }
    }
    for (int i = 0; i < N; i++) {
        
        X = c_od + ((double)rand() / (double)(RAND_MAX + 1)) * przedzialX;
        Y = randf(MIN, MAX);
        wartoscF = (*f)(X);
        if (Y < 0 && Y > wartoscF) {
            n--;
        }
        else if (Y > 0 && Y < wartoscF) {
            n++;
        }
    }
    pole = przedzialX * (fabs(MIN) + MAX);
    suma = pole * n / N;
    return suma;
}