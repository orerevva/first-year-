#include <iostream>

/*
1. переманная - это часть памяти, которая может принимать некоторые значения, а также имеет тип, название и данные
2. - целочисленные: 
                  1. short 
                  2. using short 
                  3. int 
                  4. unsigned int 
                  5. long 
                  6. unsigned long 
                  7. long long 
                  8. unsigned long long 
    - вещественные: 1. float 
                    2. double 
                    3. long double 
    - символьные: 1. char 
                  2. unsigned char 
    - логические: 1. bool 

3. - целочисленные: 
                  1. short (2 байта) 
                  2. using short (2 байта)
                  3. int (2 или 4 байта)
                  4. unsigned int (2 или 4 байта)
                  5. long (4 или 8 байт)
                  6. unsigned long (4 байта)
                  7. long long (8 байт)
                  8. unsigned long long (8 байт)
    - вещественные: 1. float (4 байта)
                    2. double (8 байт)
                    3. long double (8 байт)
    - символьные: 1. char (1 байт) 
                  2. unsigned char (1 байт) 
    - логические: 1. bool (1 байт)
     
4. - целочисленные: 
                  1. short [-32 768-32 767]
                  2. using short [0-65535]
                  3. int [-32 768-32 767 или -2 147 483 648 - 2 147 483 647]
                  4. unsigned int [0-65 535 или 0-4 294 967 295]
                  5. long [-2 147 483 648 - 2 147 483 647]
                  6. unsigned long [0-4 294 967 295]
                  7. long long [-9 223 372 036 854 775 808 - 9 233 372 036 854 775 807]
                  8. unsigned long long [0 - 18 446 744 073 709 551 615]
    - вещественные: 1. float [1.2е-38 - 3.4е+38]
                    2. double [2.2е-308 - 1.7е+308]
                    3. long double [1.7е-4932 - 1.7е+4932]
    - символьные: 1. char [-128-127]
                  2. unsigned char [0-255]
    - логические: 1. bool [0,1]
                
*/
/*
5.


int main()
{
    std::cout<<"short, 1, [-32 768-32 767]"<<'\n';
    std::cout<<"using short, 2, [0-65535]"<<'\n';
    std::cout<<"int, 2;4, [-32 768-32 767 или -2 147 483 648 - 2 147 483 647]"<<'\n';
    std::cout<<"unsigned int, 2;4, [0-65 535 или 0-4 294 967 295]"<<'\n';
    std::cout<<"long, 4;8, [-2 147 483 648 - 2 147 483 647]"<<'\n';
    std::cout<<"unsigned long, 4, [0-4 294 967 295]"<<'\n';
    std::cout<<"long long, 8, [-9 223 372 036 854 775 808 - 9 233 372 036 854 775 807]"<<'\n';
    std::cout<<"unsigned long long, 8, [0 - 18 446 744 073 709 551 615]"<<'\n';
    std::cout<<"float, 4, [1.2е-38 - 3.4е+38]"<<'\n';
    std::cout<<"double, 8, [2.2е-308 - 1.7е+308]"<<'\n';
    std::cout<<"long double, 8, [1.7е-4932 - 1.7е+4932]"<<'\n';
    std::cout<<"char, 1, [-128-127]"<<'\n';
    std::cout<<"unsigned char, 1,[0-255]"<<'\n';
    std::cout<<"bool, 1, [0,1]"<<'\n';
               

    return 0;
}
*/
/*
6
*/
int main()
{
short qs=1, ws=5;
std::cout<<(qs+ws)<<"\n";

unsigned  short qus=1, wus=5;
std::cout<<(qus+wus)<<"\n";

int qi=1, wi=5;
std::cout<<(qi+wi)<<"\n";

unsigned int  qui=1, wui=5;
std::cout<<(qui+wui)<<"\n";

long ql=1, wl=5;
std::cout<<(ql+wl)<<"\n";

unsigned long qul=1, wul=5;
std::cout<<(qul+wul)<<"\n";

long long qll=1, wll=5;
std::cout<<(qll+wll)<<"\n";

unsigned long long qull=1, wull=5;
std::cout<<(qull+wull)<<"\n";

float qf=1.0f, wf=5.0f;
std::cout<<(qf+wf)<<"\n";

double qd=1.0, wd=5.0;
std::cout<<(qd+wd)<<"\n";

long double  qld=1.0, wld=5.0;
std::cout<<(qld+wld)<<"\n";

char qc=1, wc=5; 
std::cout<<(qc+wc)<<'\n';

unsigned char quc=1, wuc=5;
std::cout<<(quc+wuc)<<"\n";


 return 0;
}