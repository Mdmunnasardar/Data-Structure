#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

void transvaal(Node *ptr)
{
    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
void deleteHead(Node *&ptr){
    ptr = ptr->next;
    ptr->prev = nullptr;
}
void deleteTail(Node *ptr){
    ptr->next = nullptr;
}
void deleteNode(Node *ptr){
    ptr->next = ptr->next->next;
}

int main()
{
    Node *head = new Node(20);
    Node *second = new Node(30);
    Node *third = new Node(40);

    head->next = second;
    second->next = third;

    // deleteHead(head);
    // deleteTail(second);
    deleteNode(head);
    transvaal(head);
    return 0;
}