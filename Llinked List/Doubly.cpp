#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *previous;

    Node(int value) : data(value), next(nullptr), previous(nullptr) {}
};

void Traverse(Node *ptr)
{
    while (ptr != nullptr)
    {
        cout << ptr->data << "<->";
        ptr = ptr->next;
    }
    cout<<"NULL";
}

int main()
{
    Node *head = new Node(10);
    Node *Second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);

    head->next = Second;
    Second->next = third;
    third->next = fourth;
    fourth->next = nullptr;

    fourth->previous = third;
    third->previous = Second;
    Second->previous = head;

    Traverse(head);

    return 0;
}