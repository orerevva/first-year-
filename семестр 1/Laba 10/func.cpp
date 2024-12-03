#include "func.hpp"
#include <iostream>

namespace mt
{
    void Make(Node* &head)
    {
        head=new Node{0, nullptr};
    }

    void PushBack(Node* head, int value)
    {
        Node* p = head;
        while (p-> next != nullptr)
            p=p->next;
        Node* q = new Node;
        q-> data = value;
        q-> next = nullptr;
        p-> next = q;
    }

    void Print(Node* head)
    {
        Node* p = head->next;
        while (p!= nullptr)
        {
            std::cout<<p->data<<" ";
            p=p->next;
        }
    }

    void Remove(Node* head, int index)
    {
        Node* p = head;
        int i = 0;
        while(p->next != nullptr && i!= index)
        {
            i++;
            p=p->next;
        }

        if (p->next== nullptr)
            return;
        Node* tmp = p-> next;
        p->next = p->next->next;
        delete tmp;
    }
    void Clear(Node* head)
    {
        Node* p = head;
        while (p-> next != nullptr)
        {
            Node* tmp = p;
            p= p->next;
            delete tmp;
        }
    }
    bool search_3(Node* head)
    {
        Node* p = head->next;
        while(p!=nullptr)
        {
            int value = p->data;
            while(value>=10)
                value/=10; 
            if (value==3)
                return true;
            p=p->next;
        }
        return false; 
    }

    void sort(Node* head)
    {
        int c=1;
        while (c!=0)
        {
            c=0;
            Node* p = head->next;
            while(p->next!=nullptr)
            {
                if((p->data % 10) < (p->next->data % 10))
                    {
                        int tmp = p->data;
                        p->data = p->next->data;
                        p->next->data = tmp;
                        ++c;
                    }
                p=p->next;
            }
        }
    }

    void even(Node* head)
    {
        Node* p = head->next;
        while (p->next!= nullptr)
        {   
            if ((p->next->data % 2 == 0) && (p->next->data!=2) )
            {
                Node* tmp = p->next;
                p->next = p->next->next;
                delete tmp;
            } 
            else 
            {
                p=p->next;
            }

        }
    }

    bool isPrime (int n) {
        if(n <= 2) 
            return false;
        for (int i = 2; i <= sqrt(n); i++) 
        {
            if (n % i == 0) 
            {
                return false;
            }
        }
        return true;
    }
    void Double (Node* head)
    {
        Node* p = head->next;
        while (p!=nullptr)
        {
            if (isPrime(p->data)) 
            {
                Node* tmp = new Node();
                tmp->data = p->data;
                tmp->next = p->next;
                p->next = tmp;
                p=p->next;
            }
            p=p->next;
        }
    }
}
