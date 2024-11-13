#include <iostream>
#include <fstream>

int main()
{
    std::ifstream in("input.txt");
    if (!in.is_open())
    {
        std::cout<<"File error"<<std::endl;
        return -1;

    }
    return 0;
}