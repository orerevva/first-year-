#include <iostream>

bool luckyticket (int ticket)
{
    int first = ticket/1000; // 111 
    int second = ticket%1000; // 111
    int sum_first= ((first/100)+ ((first/10)%10)+ (first%10));
    int sum_second= ((second/100)+ ((second/10)%10)+ (second%10));
    return sum_first== sum_second;
}

int main() {
    int count=0;
    for (int ticket=0; ticket<1000000;++ticket)
    {
        if (luckyticket(ticket))
            ++count;
    }
    std::cout<<count<<std::endl;
    return 0;
 }