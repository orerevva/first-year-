#include <iostream>
// ���� �ந�������� ��� �᫠
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

// ���� ��ࢮ� ����
int firs_nummber (int number)
{
    while(number>9){number/=10;}
    return number;
}

// ���� ��᫥���� ����
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
    std::cout<<"������ ������⢮ �ᥫ ��᫥����⥫쭮��:"<<std::endl;
    std::cin>>n;

    std::cout<<"������ ����ࠫ�� �᫠:"<<std::endl;
    for(int i=0;i<n;++i) {std::cin>>mas[i];}

    //㤠�����
    int j=0;
    for (int i=0;i<n;++i)
    {
        if (multi(mas[i])==180)
            continue;
        mas[j]=mas[i];
        j++;
    }
    n=j;

    //�㡫�஢����
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
    std::cout<<"��᫥����⥫쭮���:"<<std::endl;
    for (int i=0;i<n;++i)
        std::cout<<mas[i]<<std::endl;

    return 0;
}