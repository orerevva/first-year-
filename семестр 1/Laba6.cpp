#include <iostream>
int main()
{   
/*
// 1
    const int N_Max=10000;
    int mas[N_Max];
    int n;

    std::cout<<"Введите количество чисел:"<<std::endl;
    std::cin>>n;

    std::cout<<"Введите натуральные числа:"<<std::endl;
    for (int i=0;i<n;++i) {std::cin>>mas[i];}

    // проверка на простоту
    bool isPrime = true;
    bool hasPrime = false;
    for (int i=0; i<n;++i)
    {
        if (mas[i]<2){continue;}

        for (int d=2; d<=sqrt(mas[i])+1;++d)
        { 
            if ((mas[i]%d==0)&&(mas[i]!=2)) {isPrime =false; break;}
            else if (mas[i]==2) {isPrime=true;} 
        }
        if(isPrime) {hasPrime=true; break;}
    }
    //сортировка
    if (hasPrime)
    {
        for (int i=0; i<n-1;++i)
            for (int j=i+1;j<n;++j)
            {
                if (mas[i]>mas[j])
                {
                int tmp = mas[i];
                mas[i]=mas[j];
                mas[j]=tmp;
                }
            }
        for (int i=0;i<n;i++)
        std::cout<<mas[i]<<std::endl;
    }
   else 
        std::cout<<"Нет простых чисел"<<std::endl;
        

//2

const int N_Max=1000;
int mas[N_Max];
int n;
int mult[N_Max];
int multi=1;
std::cout<<"Введите количество чисел последовательности:"<<std::endl;
std::cin>>n;
for(int i=0; i<n; ++i)
    {
        std::cin>> mas[i];
        while (mas[i]!=0)
        {
            multi=multi*(mas[i]/10);
            mas[i]/=10;
            mult[i]+=multi;
        }
        for (int i=0; i<n-1;++i)
            for (int j=i+1; j<n;++j)
            

    }

*/
const int N_Max=1000;
int mas[N_Max];
int n;
int mult[N_Max];
int multi=1;
std::cout<<"Введите количество чисел последовательности:"<<std::endl;
std::cin>>n;
for(int i=0; i<n; ++i)
    {
        std::cin>> mas[i];
        multi=multi*(mas[i]/10);
            mas[i]/=10;
            mult[i]+=multi;

    }
for(int i=0; i<n; ++i)
std::cout<<mult[i]<<std::endl;
    return 0;
}
