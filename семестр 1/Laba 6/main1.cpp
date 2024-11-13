#include <iostream>
/*
bool myIsPrime(int a){
    if (a<2) return false;
    for(int i =2; i<=sqrt(a); i++)
        if (a%i==0) return false;
    return true;    
}
*/

int main()
{ 
 
    const int N_Max=10000;
    int mas[N_Max];
    int n;

    std::cout<<"Введите количество чисел:"<<std::endl;
    std::cin>>n;

    std::cout<<"Введите натуральные числа:"<<std::endl;
    for (int i=0;i<n;++i) {std::cin>>mas[i];}

    // проверка на простоту
    
    bool hasPrime = false;
    for (int i=0; i<n;++i)
    {
        bool isPrime = true;
        if (mas[i]<2){continue;}
        for (int d=2; d<=sqrt(mas[i]);++d)
        { 
            if (mas[i]%d==0) {isPrime =false; break;}
            
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

    }
    for (int i=0;i<n;i++)
        std::cout<<mas[i]<<std::endl;
        



    return 0;
}
