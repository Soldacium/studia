#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "student.h"

#define MAX

// kolejka lista
studentKolejka** pop_kl(studentKolejka** stuArr) {
    studentKolejka** w = stuArr;// zapamietujemy to co usuwamy
    *stuArr = (*stuArr)->next; // przeskakujemy usuwany element
    free(w); // zwalniamy pamiec przeskoczonego elementu
    return stuArr; // tak spreparowana liste wzracamy
}

void push_kl(studentKolejka** stuArr, student stu) {

    if (*stuArr == NULL) {
        *stuArr = (studentKolejka*)malloc(sizeof(studentKolejka));
        (*stuArr)->student = stu;
        (*stuArr)->next = NULL;
        return;
    }

    while ((*stuArr)->next != NULL)
    {
        *stuArr = (*stuArr)->next;
    }

    studentKolejka* nowy = (studentKolejka*)malloc(sizeof(studentKolejka));
    nowy->student = stu;
    nowy->next = NULL;
    (*stuArr)->next = nowy;
}

void show_kl(studentKolejka** stuArr) {
    
    if (stuArr == NULL) printf("List is empty");
    else {
        studentKolejka* current = stuArr;
        do {
            printf("%s", current->student.imie);
            printf("\n");
            current = current->next;
        } while (current != NULL);

    }
}

// kolejka tablica
void push_ka(student* stuArr, student stu, int* rear, int* front) {
    if (*rear == MAX - 1)
        printf("Queue Overflow \n");
    else {
        if (*front == -1)
            /*If queue is initially empty */
            *front = 0;
        *rear += 1;
        stuArr[*rear] = stu;
    }
} 

void pop_ka(student* stuArr, int* rear, int* front) {
    if (*front == -1 || *front > *rear){
        printf("Underflow \n");
        return;
    }else{
        //printf("Usuniêto : %d\n", stuArr[*front].imie);
        *front += 1;
    }
} 

void show_ka(student* stuArr, int rear, int front) {
    int i;
    if (front == -1) {
        printf("Kolejka pusta \n");
    } else {
        printf("Kolejka : \n");
        student stu;
        for (i = front; i <= rear; i++) {
            //printf("%d", i);
            stu = stuArr[i];
            printf("%d. %s ", i,stu.imie);
        }    
        printf("\n");
    }
} 