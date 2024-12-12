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

void Traverse(Node *head)
{
    Node *ptr = head;
    cout << "Linked list: ";
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != head);
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
    fourth->next = head;

    fourth->previous = third;
    third->previous = Second;
    Second->previous = head;
    head->previous=fourth;

    Traverse(head);

    return 0;
}