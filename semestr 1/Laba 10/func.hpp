#pragma once

namespace mt
{
    struct Node
    {
        int data;
        Node* next; 
    };
    void Make(Node* &head);
    void PushBack(Node* head, int value);
    void Print(Node* head);
    void Remove(Node* head, int index);
    void Clear(Node* head);
    bool search_3(Node* head);
    void sort(Node* head);
    void even(Node* head);
    void Double (Node* head);
}