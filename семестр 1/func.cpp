#include<iostream>
#include"func.hpp"

void read(int matrix[N_MAX][N_MAX], int& n)
{   
    std::cout<<"Введите размер матрицы"<<std::endl;
    std::cin>>n;
    std::cout<<"Введите элементы матрицы"<<std::endl;
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            std::cin>> matrix[i][j];
}


int min_max_number(int matrix[N_MAX][N_MAX], int& n)
{   int min=100000000;
    for (int i=0; i<n; ++i)
        for (int j=0; j<n;++j)
        {
            if (matrix[i][j]<min)
                min=matrix[i][j];
        }
    int max=100000000;
    for (int i=0; i<n; ++i)
        for (int j=0; j<n;++j)
        {
            if (matrix[i][j]>max)
                max=matrix[i][j];
        }
    return min+max;
}


int row_digit_8(int matrix[N_MAX][N_MAX], int& n)
{   int row=-1;
    for (int i=0; i<n; ++i)
        {   
            for (int j=0; j<n;++j)
            {   
                while (matrix[i][j]>0)
                {   
                    if ((matrix[i][j]%10)==8){row=i;}
                    matrix[i][j]/=10;
                }      
            }
        }
    return row;
}

void sort(int matrix[N_MAX][N_MAX],int& n, int row)
{
    for (int i=0; i<n-1;++i)
    {
        for (int j=i+1;j<n;++j)
        {
            if  (matrix[row][i]>matrix[row][j])
                std::swap(matrix[i], matrix[j]);
        }
    }
}


void whrite (int matrix[N_MAX][N_MAX], int n)
{   std::cout<<"Maтрица"<<std::endl;
    for (int i=0;i<n;++i)
    {
        for (int j=0; j<n;++j)
            std::cout<<matrix[i][j]<<" ";
        std::cout<<std::endl;
    }
}