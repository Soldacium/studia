#pragma once
#include "student.h"

// s - stack, l - list, a - array
int push_sl(studentStos** top, student stu);
int pop_sl(studentStos** top);
void show_sl(studentStos** top);
int size_sl(studentStos* top);

void push_sa(student* stuArr, student stu, int* n);
void pop_sa(student* stuArr, int* n);
void show_sa(student* stuArr, int n);