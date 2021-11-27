#include "Stack.h"
#include <iostream>
using namespace std;

bool Stack::IsEmpty()
{
    return top == NULL;
}

void Stack::MakeEmpty()
{
    Node* temp;
    while (top != NULL) {
        temp = top;
        top = top->next;
        delete temp;
    }
}

void Stack::Push(ItemType item)
{
    top = new Node(item, top);
}

ItemType Stack::Pop()
{
    if (IsEmpty()) {
        cout << "Error";
    }
    Node* temp = top;
    ItemType item = top->data;
    top = top->next;
    delete temp;

    return item;
}



void Node::InsertAfter(Node* newnode) {
    newnode->next = next;
    next = newnode;
}

Node *Node::DeleteAfter() {
    Node* toDelete = next;
    if (toDelete == NULL) {
        return NULL;
    }
    next = toDelete -> next;
    return toDelete;
}