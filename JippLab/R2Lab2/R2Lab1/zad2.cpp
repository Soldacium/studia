// R2Lab1.cpp : Ten plik zawiera funkcj� �main�. W nim rozpoczyna si� i ko�czy wykonywanie programu.
//

#include <iostream> 
using namespace std; 
  
// Function template to swap 
// two numbers 
template <class T> 
int swap_num(T& x, T& y) 
{ 
    T t; 
    t = x; 
    x = y; 
    y = t; 
    return 0; 
} 
  
// Driver code 
int task2() 
{ 
    int a, b; 
    a = 10, b = 20; 
 
    swap_num(a, b); 
    cout << a << " " << b << endl; 
    return 0; 
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotycz�ce rozpoczynania pracy:
//   1. U�yj okna Eksploratora rozwi�za�, aby doda� pliki i zarz�dza� nimi
//   2. U�yj okna programu Team Explorer, aby nawi�za� po��czenie z kontrol� �r�d�a
//   3. U�yj okna Dane wyj�ciowe, aby sprawdzi� dane wyj�ciowe kompilacji i inne komunikaty
//   4. U�yj okna Lista b��d�w, aby zobaczy� b��dy
//   5. Wybierz pozycj� Projekt > Dodaj nowy element, aby utworzy� nowe pliki kodu, lub wybierz pozycj� Projekt > Dodaj istniej�cy element, aby doda� istniej�ce pliku kodu do projektu
//   6. Aby w przysz�o�ci ponownie otworzy� ten projekt, przejd� do pozycji Plik > Otw�rz > Projekt i wybierz plik sln