#include <iostream> 

 struct Node
{
    int data;
    Node* prev;
    Node* next;
};

void AddBack (Node* sent, int data)
{
    Node* p = new Node;
    p->data = data;
    p->next = sent;
    p-> prev = sent->prev;
    sent->prev->next = p;
    sent->prev = p;
}

void Print(Node* sent)
{
    Node*p = sent->next;
    while(p!=sent)
    {
        std::cout<<p->data<<std::endl;
        p = p->next;
    }
}

void Clear(Node* sent)
{
    Node*p = sent->next;
    while(p!=sent)
    {
        Node* tmp=p;
        p=p->next;
        delete tmp;
    }
}

void Duplicate(Node* sent)
{
    Node*p = sent->next;
    while(p!=sent)
    {
        if(p->data%12==0)
        {
            Node* q = new Node;
            q->data = p->data;
            q->prev = p;
            q->next = p->next;
            p->next->prev = q;
            p->next =q;
            p=p->next;
        }
        p = p->next;
    }
}

bool isPrime(int n)
{
    if (n <= 1) 
        return false;
    for (int i = 2; i <= std::sqrt(n); i++) 
    {
        if (n % i == 0) 
            return false;
    }
    return true;
}

void Remove(Node* sent)
{
    Node*p = sent->next;
    while(p!=sent)
    {
        if(isPrime(p->data))
        {
            Node* tmp = p;
            p->prev->next = p->next;
            p->next->prev = p->prev;
            p = p->prev;
            delete tmp;
        }
        p = p->next;
    }
}

bool Non_Decreasing(Node* sent) 
{
    Node* current = sent->next;
    int lastDigit = current->data % 10;
    while (current != sent) 
    {
        if (current->data % 10 < lastDigit) 
        {
            return false;
        }
        lastDigit = current->data % 10;
        current = current->next;
    }
    return true;
}

bool Non_Increasing(Node* sent) 
{
    Node* current = sent->next;
    int lastDigit = current->data % 10;

    while (current != sent)
    {
        if (current->data % 10 > lastDigit) 
        {
            return false;
        }
        lastDigit = current->data % 10;
        current = current->next;
    }
    return true;
}

int first_D(int n)
{
    while (n>=10)
    {
        n=n/10;
    }
    return n;
}


void sort(Node* sent)
{
    int c=1;
    while (c!=0)
    {
        c=0;
        Node* p = sent->next;
        while(p->next!=sent)
        {
            if((first_D(p->data ) ) > (first_D (p->next->data)))
            {
                int tmp = p->data;
                p->data = p->next->data;
                p->next->data = tmp;
                c++;
            }
            p=p->next;
        }
    }
}

int main()
{
    Node* sent = new Node;
    sent->next = sent;
    sent->prev = sent;
    int n, a;
    std::cin>>n;
    for (int i=0;i<n;i++)
    {
        std::cin>>a;
        AddBack(sent, a);
    }
    if (Non_Decreasing(sent) || Non_Increasing(sent))
    {
        Remove(sent);
        Duplicate(sent);
    }
    else;
    {
        sort(sent);
    }
    Print(sent);
    Clear(sent);

    delete sent;
}
