#include <iostream>
#include "func.hpp"

//���⥭�� ��ப�
void read (int mas[N_MAX],int&n)
{
    std::cout<<"������ ������⢮ ����⮢ ��᫥����⥫쭮��:"<<std::endl;
    std::cin>>n;
    std::cout<<"������ ������ ��᫥����⥫쭮��"<<std::endl;
    for (int i=0; i<n; ++i)
        {
            std::cin>>mas[i];
        }
}

// ࠧ��筮��� ��� � �᫥
int var_numbers (int mas[N_MAX], int n)
{   int ans =0;
    for (int i=0; i<n;++i)
    {
        int r=mas[i];
        int digit0 = 0, digit1 = 0, digit2 = 0, digit3 = 0, digit4 = 0,
        digit5 = 0, digit6 = 0, digit7 = 0, digit8 = 0, digit9 = 0;

        while (r> 0)
        {
            switch (r % 10)
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
            r /= 10;
        }

        ans = std::max(digit0, std::max(digit1, std::max(digit2, std::max(digit3, std::max(digit4, std::max(digit5, std::max(digit6, std::max(digit7, std::max(digit8, digit9)))))))));   
    }
    return ans;    
}

//㤠����� ��
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

//���� ������஬� 
bool palindrom (int mas[N_MAX],int n)
{   int r;
    int orig_num;
    int new_num;
    for (int i=0; i<n; ++i)
    {
        r= mas[i];
        orig_num=mas[i];
        new_num=0;
        while (r>0)
        {
            new_num=new_num*10+r%10;
            r/=10;
        }
    }
    return orig_num==new_num;
}

//㤢����� �᫠
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

//�뢮�
void write (int mas[N_MAX],int n)
{
    std::cout<<"��᫥����⥫쭮���:"<<std::endl;
    for (int i=0;i<n;++i)
        std::cout<<mas[i]<<std::endl;
}




