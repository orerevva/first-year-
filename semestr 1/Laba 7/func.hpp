#pragma once
#include<iostream>
const int N_MAX=100;
// �⥭�� 
void read(int matrix[N_MAX][N_MAX], int& n);

// ���� �㬬� ��� � ���
int min_number(int matrix[N_MAX][N_MAX], int n);
int max_number(int matrix[N_MAX][N_MAX], int n);
//���� ��ப� � ����⮬ � ��ன 8
bool row_digit_8(int matrix[N_MAX][N_MAX], int n, int i);

// ���஢��
void sort(int matrix[N_MAX][N_MAX],int n, int row);

//�뢢�� 
void whrite (int matrix[N_MAX][N_MAX], int n);