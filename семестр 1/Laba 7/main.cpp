#include "func.hpp"
int main ()
{
    int n;
    int matrix[N_MAX][N_MAX];
    read(matrix,n);
    if ( min_number(matrix,n)+max_number(matrix,n)==0)
        for (int i=0;i<n;++i)
        {
            if (row_digit_8(matrix,n,i))
                sort(matrix,n, i);
        }
    whrite(matrix,n);
    return 0;
}