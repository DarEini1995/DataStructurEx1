#pragma once
#include "ItemType.h"
#include <cstddef>

#define MAX 1000

struct Node
{
    ItemType data;
    Node* next;
    public:
        Node(ItemType item, Node* ptr = NULL) {
            data = item;
            next = ptr;
        };
        ~Node() {
            
        };
        void InsertAfter(Node* newnode);
        Node* DeleteAfter();
};

class Stack {
    Node *top;
    //Node* bottom;
public:
    Stack() { 
        top = NULL; 
    } //==> constractor
    bool IsEmpty();
    void MakeEmpty();
    void Push(ItemType x);
    ItemType Pop();
};
