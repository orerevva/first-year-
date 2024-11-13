#include <iostream>
// поиск произведения цифр числа
int multi(int number)
{
    int a=1;
    while (number>0)
    {
        a*=(number%10);
        number/=10;
    }
    return a;
}

// поиск первой цифры
int firs_nummber (int number)
{
    while(number>9){number/=10;}
    return number;
}

// поиск последней цифры
int last_number (int number)
{
    number=number%10;
    return number;
}

int main ()
{
    
    const int N_MAX=20000;
    int mas[N_MAX];
    int n;
    std::cout<<"введите количество чисел последовательности:"<<std::endl;
    std::cin>>n;

    std::cout<<"введите натуральные числа:"<<std::endl;
    for(int i=0;i<n;++i) {std::cin>>mas[i];}

    //удаление
    int j=0;
    for (int i=0;i<n;++i)
    {
        if (multi(mas[i])==180)
            continue;
        mas[j]=mas[i];
        j++;
    }
    n=j;

    //дублирование
    for(int i=0; i<n; i++)
        if ((firs_nummber(mas[i])==1) && (last_number(mas[i])==1))
        {
            for (int j=n;j>i;--j)
            {
                mas[j]=mas[j-1];
            }
            i++;
            n++;
        }
    std::cout<<"последовательность:"<<std::endl;
    for (int i=0;i<n;++i)
        std::cout<<mas[i]<<std::endl;

    return 0;
}