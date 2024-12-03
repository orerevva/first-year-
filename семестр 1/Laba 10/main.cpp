#include <iostream>
#include "func.hpp"

int main ()
{
    mt::Node* head;
    mt::Make(head);
    mt::PushBack(head, 27);
    mt::PushBack(head, 12);
    mt::PushBack(head, 2);
    mt::PushBack(head, 22);
    if (!mt::search_3(head))
    {
        mt::sort(head);
        mt::Print(head);
    }
    else
    {
        mt::even(head);
        mt::Double(head);
        mt::Print(head);
    }    
    mt::Clear(head);
    return 0;
}

