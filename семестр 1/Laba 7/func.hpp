#pragma once
#include<iostream>
const int N_MAX=100;
// чтение 
void read(int matrix[N_MAX][N_MAX], int& n);

// поиск суммы мин и мах
int min_number(int matrix[N_MAX][N_MAX], int n);
int max_number(int matrix[N_MAX][N_MAX], int n);
//поиск стороки с элементом с цифрой 8
bool row_digit_8(int matrix[N_MAX][N_MAX], int n, int i);

// сортировка
void sort(int matrix[N_MAX][N_MAX],int n, int row);

//выввод 
void whrite (int matrix[N_MAX][N_MAX], int n);