#include <iostream>
#include "func_d3.hpp"

//прочтение строки
void read (int mas[N_MAX],int&n)
{
    std::cout<<"Введите количество элементов последовательности:"<<std::endl;
    std::cin>>n;
    std::cout<<"введите элементы последовательности"<<std::endl;
    for (int i=0; i<n; ++i)
        std::cin>>mas[i];
}

// различность цифр в числе
int var_numbers (int mas[N_MAX], int n)
{   for (int i=0; i<n;++i)
    {
        int digit0 = 0, digit1 = 0, digit2 = 0, digit3 = 0, digit4 = 0,
        digit5 = 0, digit6 = 0, digit7 = 0, digit8 = 0, digit9 = 0;

        while (mas[i] > 0)
        {
            switch (mas[i] % 10)
            {
                case 0: digit0 += 1; break;
                case 1: digit1 += 1; break;
                case 2: digit2 += 1; break;
                case 3: digit3 += 1; break;
                case 4: digit4 += 1; break;
                case 5: digit5 += 1; break;
                case 6: digit6 += 1; break;
                case 7: digit7 += 1; break;
                case 8: digit8 += 1; break;
                case 9: digit9 += 1; break;
            }
            mas[i] /= 10;
        }

        int ans = std::max(digit0, std::max(digit1, std::max(digit2, std::max(digit3, std::max(digit4, std::max(digit5, std::max(digit6, std::max(digit7, std::max(digit8, digit9)))))))));   
        return ans;    
    }
}

//удаление числ
void delate_number(int mas[N_MAX],int n)
{
  int j=0;
  for (int i=0;i<n;++i)
    {
        mas[j]=mas[i];
        j++;
    }
    n=j;
}

//поиск палиндрома 
bool palindrom (int mas[N_MAX],int n)
{
    for (int i=0; i<n; ++i)
    {
        int orig_num=mas[i];
        int new_num=0;
        while (mas[i]>0)
        {
            new_num=new_num*10+mas[i]%10;
            mas[i]/=10;
        }
        return orig_num==new_num;
    }
}

//удвоение числа
void double_number (int mas[N_MAX], int n)
{
    for (int i=0; i<n;++i)
    {
        for (int j=n;j>i;--j)
            mas[j]=mas[j-1];
        ++i;
        ++n;
    }

}

//вывод
void write (int mas[N_MAX],int n)
{
    std::cout<<"последовательность:"<<std::endl;
    for (int i=0;i<n;++i)
        std::cout<<mas[i]<<std::endl;
}




