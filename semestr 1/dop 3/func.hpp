#pragma once
#include <iostream>
int const N_MAX=20000;

//прочтение строки
void read (int mas[N_MAX],int&n);

// различность цифр в числе
int var_numbers (int mas[N_MAX], int n);

//удаление числ
void delate_number(int mas[N_MAX],int n);

//поиск палиндрома 
bool palindrom (int mas[N_MAX],int n);

//удвоение числа
void double_number (int mas[N_MAX], int n);

//вывод
void write (int mas[N_MAX],int n);

