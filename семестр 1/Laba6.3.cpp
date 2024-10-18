#include <iostream>
int main()
{
    const int N_MAX=100;
    const int M_MAX=100;
    int matrix[N_MAX][M_MAX];
    int n,m;
    std::cout<<"введите размер матрицы:"<<std::endl;
    std::cin>>n>>m;
    std::cout<<"введите элемнты матрицы:"<<std::endl;
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            std::cin>>matrix[i][j];

// поис строки с минимальным количеством простых чисел
    int minEven=m+1;
    int row = -1;
    for (int i=0;i<n;++i)
    {
        int countEven = 0;
        for (int j=0; j<m;++j)
        {
            if (matrix[i][j]%2==0){countEven++;}
        }
        if (countEven < minEven) 
        {
            minEven=countEven; 
            row =i;
        }
    }

// замена строки на квадраты
    if (row!=-1)
    {
        for (int j=0; j<m; ++j)
        {
            matrix[row][j]*=matrix[row][j];
        }
    }
    std::cout<<"Матрица:"<<std::endl;
    for (int i=0;i<n;++i)
    {
        for (int j=0; j<m;++j)
            std::cout<<matrix[i][j]<<" ";
        std::cout<<std::endl;
    }

    return 0;
}
