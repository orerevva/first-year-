#include <iostream>

class Ellips 
{
private:
    double m_a; //поле
    double m_b;

public:
    Ellips(double a, double b): m_a(a), m_b(b) {} //конструктор

    double area() // метод
    {
        return 3.1415926535 * m_a * m_b;
    }

    double perimeter ()   
    {
        return 4 * ((pow((3.1415926535 * m_a * m_b + (m_a - m_b)), 2))/(m_a + m_b));
    }
};


int main() 
{
    double a,b;
    std::cin>> a;
    std::cin>> b;
    Ellips ellips (a, b);

    std::cout<<ellips.area()<<std::endl;
    std::cout<<ellips.perimeter()<<std::endl;
    
    return 0;
}