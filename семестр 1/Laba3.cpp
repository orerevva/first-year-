#include <iostream>
int main()
{
    unsigned int a, i;
    std::cout <<"Write 2 numbers"<<std::endl;
    std::cin >> a>>i;
    a&=~(1<<i);
    std::cout<<a<<std::endl;

return 0;

}