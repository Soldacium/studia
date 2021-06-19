#pragma once
#include "student.h"

studentKolejka** pop_kl(studentKolejka** stuArr);
void push_kl(studentKolejka** stuArr, student stu);
void show_kl(studentKolejka** stuArr);

void push_ka(student* stuArr, student stu, int* rear, int* front);
void pop_ka(student* stuArr, int* rear, int* front);
void show_ka(student* stuArr, int rear, int front);