#include<iostream>
// поиск произведения чисел числа
int multi_digit (int number)
{
    int a=1;
    while (number>0)
    {
      int r=1;
      a= (number%10)*a;
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
int n;
std::cout<<"введите количество чисел:"<<std::endl;
std::cin>>n;
std::cout<<"введите натуральные числа:"<<std::endl;
for(int i=0; i<n; ++i){ std::cin>> mas[i];}
for (int i=0; i<n-1;++i)
    for (int j=i+1; j<n;++j)
    {
        int a = multi_digit (mas[i]);
        int b = multi_digit (mas[j]);
        if (a>b)
        {
            int temp = mas[i];
            mas[i]=mas[j];
            mas[j]=temp;
        }
        else if ((a==b)&& (first_digit(mas[i])>first_digit(mas[j])))
        {
            int temp = mas[i];
            mas[i]=mas[j];
            mas[j]=temp;
        }
        else if ((a==b)&& (first_digit(mas[i])==first_digit(mas[j]))&&(mas[i]>mas[j]))
        {
            int temp = mas[i];
            mas[i]=mas[j];
            mas[j]=temp;
        }

    }  

for (int i=0;i<n;++i)
{
   std::cout<<mas[i]<<std::endl; 
}
return 0;
}