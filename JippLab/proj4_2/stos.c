#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "student.h"

#define MAX_STOS 100

// lista

int push_sl(studentStos** top, student stu) {
    if (size_sl(*top) == MAX_STOS) {
        printf("\nSTACK OVERFLOW!! Nie mozna dodac elementu do stosu.");
        return 1;
    }

    if (*top == NULL) {
        *top = (studentStos*)malloc(sizeof(studentStos));
        (*top)->student = stu;
        (*top)->next = NULL;
    }
    else {
        studentStos* newElement;
        newElement = (studentStos*)malloc(sizeof(studentStos));
        newElement->student = stu;
        newElement->next = *top;
        *top = newElement;
    }

}

int pop_sl(studentStos** top) {

    if (*top == NULL) {
        printf("\nSTACK UNDERFLOW!! Nie ma czego zdjac ze stosu.");
    }
    else {
        studentStos* tmp = NULL;
        tmp = (*top)->next;
        free(*top);
        *top = tmp;
    }

}

void show_sl(studentStos** top) {

    printf("\n");
    if (top == NULL) printf("List is empty");
    else {
        studentStos* current = (*top);
        while (current != NULL) {
            printf("%i", current->student.rok);
            printf("\n");
            current = current->next;
        }
    }
}

int size_sl(studentStos* top) {

    int counter = 0;
    studentStos* current = top;

    while (current != NULL)
    {
        counter++;
        current = current->next;
    }

    return counter;
}

// tablica
void push_sa(student* stuArr, student stu, int* n) {
    printf("%i", *n);
    if (*n < MAX_STOS) {
        stuArr[*n] = stu;
        *n += 1;
    }
    else {
        printf("stack full");
    }   
    

    
}

void pop_sa(student* stuArr, int* n) {
    if (*n < 1) {
        printf("nothing to pop()");
    }
    else {
        *n -= 1;
        // stuArr[*n - 1] = NULL;
    }
}

void show_sa(student* stuArr, int n) {
    for (int i = 0; i < n; i++) {
        printf("Student nr.%i - %s %s %i\n", i, stuArr[i].imie, stuArr[i].nazwisko, stuArr[i].rok);
    }
}