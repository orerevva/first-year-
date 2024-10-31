#include "func.hpp"
int main ()
{
    int n;
    int m;
    int matrix[N_MAX][N_MAX];
    read(matrix,n);
    if ( min_max_number(matrix,n)==0)
        sort(matrix,n, row_digit_8(matrix,n));
    whrite(matrix,n);
    return 0;
}