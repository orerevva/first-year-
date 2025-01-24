#include <iostream>
#include <fstream>
//1

int number(int a) 
{
    if (a == 0)
        return 0;
    return 1 + number(a / 10); 
}

int main()
{
    int n;
    std::cin >> n;
    std::cout<< number(n) << std::endl;
    return 0;
}

/*
//2
void QuickSort(int a, int b, int* arr)
{
    if (a>=b)
        return;
    int m = arr[(a+b)/2];
    int l = a - 1;
    int r = b + 1;
    while(1)
    {
        do l++; while(arr[l] < m);
        do r--; while(arr[r] > m);
        if(l >= r)
            break;
        std::swap(arr[l], arr[r]);
    }
    l=r;
    r++; 
    QuickSort(a, l, arr);
    QuickSort(r, b, arr);
}

int main ()
{
    const int n = 5;
    int arr[n]={2, 3, 1, 6, 4};
    QuickSort(0, n-1, arr);

    for(int i=0; i<n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    return 0;
}
*/
/*
//3
void Search(int i, int j, int step, int n, int m, char field[100][100], int table[100][100])
{
    if (step >= table[i][j])
        return;

    table[i][j]=step;

    if  (field[i][j] == 'E')
        return;

    if(i + 1 < n && field[i+1][j] != '#') 
        Search(i+1,j,step+1,n,m, field, table);
    if(i - 1 >= 0 && field[i-1][j] != '#') 
        Search(i-1,j,step+1,n,m, field, table); 
    if(j + 1 < m && field[i][j+1] != '#') 
        Search(i,j+1,step+1,n,m, field, table);
    if(j - 1 >= 0 && field[i][j-1] != '#') 
        Search(i,j-1,step+1,n,m, field, table);

    if(j + 1 < m && i + 1 < n && field[i+1][j+1] != '#') 
        Search(i+1,j+1,step+1,n,m, field, table);
    if(j - 1 >= 0 && i - 1 >= 0 && field[i-1][j-1] != '#') 
        Search(i-1,j-1,step+1,n,m, field, table);
    if(j - 1 >= 0 && i + 1 < n && field[i+1][j-1] != '#') 
        Search(i+1,j-1,step+1,n,m, field, table);
    if(j + 1 < m && i - 1 >= 0 && field[i-1][j+1] != '#') 
        Search(i-1,j+1,step+1,n,m, field, table);
}

int main ()
{
    char field[100][100];
    int table [100][100];
    std::ifstream in ("input.txt");
    int n,m;
    int is,js;
    int ie, je;
    in>>n>>m;
    for(int i=0; i<n;i++) 
        for(int j=0; j<m; j++)
        {
            table[i][j] = INT_MAX;
            in >> field[i][j];
            if (field[i][j] == 'S')
            {
                is=i;
                js=j;
            }
            else if (field[i][j] == 'E')
            {
                ie=i;
                je=j;
            }
        }
    Search(is, js, 0, n, m, field, table);

    if (table[ie][je] == INT_MAX) 
    {
        std::cout << -1 << std::endl; 
    } 
    else
    {
        std::cout << table[ie][je] << std::endl; 
    }
    return 0;
}
*/