#include "func_d3.hpp"

int main ()
{
    int mas[N_MAX];
    int n;
    read(mas,n);
    if (var_numbers(mas,n)<=1)
        delate_number(mas,n);
    if (palindrom(mas,n))
        double_number(mas,n);
    write(mas,n);
    
    return 0;
}

