#pragma once
const int N_MAX=100;
// чтение 
void read(int matrix[N_MAX][N_MAX], int& n);

// поиск суммы мин и мах
int min_max_number(int matrix[N_MAX][N_MAX], int& n);

//поиск стороки с элементом с цифрой 8
int row_digit_8(int matrix[N_MAX][N_MAX], int& n);

// сортировка
void sort(int matrix[N_MAX][N_MAX],int& n, int row);

//выввод 
void whrite (int matrix[N_MAX][N_MAX], int n);