#include <iostream>
#include<cmath>
int main ()
{
    float q1, p1, q2, p2,a;
    int c=0;
    std::cout<<"Enter numbers"<<std::endl;
    std::cin>> q1>> p1>> q2>> p2>>a;
    if ((q1/p1)>(q2/p2))
    {
        while (a>q1)
        {
            c+=p1;
            a-=q1;
        }
        if(p1>(ceil(a/q2)*p2))
            c+=ceil(a/q2)*p2;
        else
            c+=p1;
    }
    else
    {
        while (a>q2)
        {
            c+=p2;
            a-=q2;
        }
        if (p2 > (ceil(a/q1)*p1))
        {
            c += ceil(a/q1)*p1;
        }
        else
            c+=p2;
    }
    std::cout<<"coust:"<<" "<<c<<std::endl;
    return 0;
}
