#include<iostream>
// поиск произведения чисел числа
int multi_digit (int number)
{
    int a=1;
    while (number>0)
    {
      a*= (number%10);
      number/=10;
    }
    return a;
}

//поиск первой цифры числа
int first_digit(int number){
    while (number>9)
    {
        number/=10;
    }
    return number;
}

int main() {

const int N_Max=1000;
int mas[N_Max];
int mult[N_Max];
int first[N_Max];
int n;
std::cout<<"введите количество чисел:"<<std::endl;
std::cin>>n;
std::cout<<"введите натуральные числа:"<<std::endl;
for(int i=0; i<n; ++i)
{ 
    std::cin>> mas[i];
    mult[i] = multi_digit (mas[i]);
    first[i] = first_digit (mas[i]);
}


for (int i=0; i<n-1;++i)
    for (int j=i+1; j<n;++j)
    {
        if (mult[i]>mult[j])
        {
            std::swap(mult[i], mult[j]);
            std::swap(first[i], first[j]);
            std::swap(mas[i], mas[j]);
        }
        else if ((mult[i]==mult[j])&& (first[i]>first[j]))
        {
            std::swap(mult[i], mult[j]);
            std::swap(first[i], first[j]);
            std::swap(mas[i], mas[j]);
        }
        else if ((mult[i]==mult[j])&& (first[i]==first[j])&&(mas[i]>mas[j]))
        {
            std::swap(mult[i], mult[j]);
            std::swap(first[i], first[j]);
            std::swap(mas[i], mas[j]);
        }

    }  

for (int i=0;i<n;++i)
{
   std::cout<<mas[i]<<std::endl; 
}
return 0;
}