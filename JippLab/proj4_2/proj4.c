// proj4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include "stos.h"
#include <string.h>
#include "student.h"
#include "kolejka.h"

#define MAX_SIZE 100

student getStudentFromUser() {
    student newStudent;
    newStudent.imie = (char*)malloc(30 * sizeof(char));
    newStudent.nazwisko = (char*)malloc(30 * sizeof(char));
    printf("\ndodawanie studenta;\n");
    printf("imie: ");
    scanf("%s", newStudent.imie);
    printf("nazwisko: ");
    scanf("%s", newStudent.nazwisko);
    printf("rokurodzenia: ");
    scanf("%i", &newStudent.rok);

    return newStudent;
}

void testStosArray() {
    student stuArr[100];
    student newStudent;
    int currentElements = 0;

    printf("\nWybrales testowanie stosu na bazie tablicy, wpisz: \n1 - by dodac\n2 - by usunac gorny element \n3 - wyswietl stan tablicy \n0 - wyjdz\n");
    enum choices {add = 1, del = 2, show = 3, quit = 0};
    int choice = -1;

    while (choice != 0) {
        printf("\nJaki wybor? \n");
        scanf("%i", &choice);
        switch (choice) {
            case add:
                push_sa(&stuArr, getStudentFromUser(), &currentElements);
                printf("\n\ndodawanie pomyslne, aktualna liczba studentow: %i", currentElements);
                break;
            case del:
                pop_sa(&stuArr, &currentElements);
                break;
            case show:
                show_sa(&stuArr, currentElements);
                break;
            case quit:
                break;
            default:
                break;
        }
    }
}

void testStosList() {
    studentStos* stuArr;
    stuArr = NULL;

    printf("Wybrales testowanie stosu na bazie listy, wpisz: \n1 - by dodac\n2 - by usunac najwczesniejszy element \n3 - wyswietl stan tablicy \n0 - wyjdz\n");
    enum choices { add = 1, del = 2, show = 3, quit = 0 };
    int choice = -1;

    while (choice != 0) {
        printf("\nJaki wybor? \n");
        scanf("%i", &choice);
        switch (choice) {
            case add:
                push_sl(&stuArr, getStudentFromUser());
                break;
            case del:
                pop_sl(&stuArr);
                break;
            case show:
                show_sl(&stuArr);
                break;
            case quit:
                break;
            default:
                break;
        }
    }
}

void testKolejkaArray() {
    student stuArr[100];
    student newStudent;
    int front = 0, rear = 0;

    printf("Wybrales testowanie kolejki na bazie tablicy, wpisz: \n1 - by dodac\n2 - by usunac najwczesniejszy element \n3 - wyswietl stan tablicy \n0 - wyjdz\n");
    enum choices { add = 1, del = 2, show = 3, quit = 0 };
    int choice = -1;

    while (choice != 0) {
        printf("\nJaki wybor? \n");
        scanf("%i", &choice);
        switch (choice) {
            case add:
                push_ka(&stuArr, getStudentFromUser(), &front, &rear);
                break;
            case del:
                pop_ka(&stuArr, &front, &rear);
                break;
            case show:
                show_ka(&stuArr, front, rear);
                break;
            case quit:
                break;
            default:
                break;
        }
    }
}

void testKolejkaList() {
    studentKolejka* stuArr;
    stuArr = NULL;

    printf("Wybrales testowanie kolejki na bazie listy, wpisz: \n1 - by dodac\n2 - by usunac gorny element \n3 - wyswietl stan tablicy \n 0 - wyjdz");
    enum choices { add = 1, del = 2, show = 3, quit = 0 };
    int choice = -1;

    while (choice != 0) {
        printf("\nJaki wybor? \n");
        scanf("%i", &choice);
        switch (choice) {
            case add:
                push_kl(&stuArr, getStudentFromUser());
                break;
            case del:
                pop_sl(&stuArr);
                break;
            case show:
                show_sl(&stuArr);
                break;
            case quit:
                break;
            default:
                break;
        }
    }
}

void testAll() {
    enum choices { stosArr = 1, stosList = 2, kolejkaArr = 3, kolejkaList = 4, quit = 0 };
    // enum choices choice;
    int choice = -1;
    printf("Witaj w projekt4! Ktory program chcesz sprawdzic?\n");
    printf("1 - stos (tablica) \n2 - stos (lista) \n3 - kolejka (tablica) \n4 - kolejka (lista) \n0 - wyjdz\n");
    while (choice < 1 || choice > 4) {
        scanf("%i", &choice);
        if (choice == quit) {
            break;
        }
    }

    switch (choice) {
    case stosArr:
        testStosArray();
        break;
    case stosList:
        testStosList();
        break;
    case kolejkaArr:
        testKolejkaArray();
        break;
    case kolejkaList:
        testKolejkaList();
        break;
    default:
        break;
    }
}

int main()
{  
    //getStudentFromUser();
    //testInput();
    //printf("%s", newStudent.imie);
    // test(newStudent);
    //push_sa(&stuArr, newStudent, &x);
    //testStosArray();
    testAll();
}


