#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};
class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    // for traverse all the node frome head to last...
    void traversal()
    {
        Node *ptr = head;
        cout<<"Linked List: ";
        while (ptr != nullptr)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
    // for add a node at head..
    void InsertAtHead(int data)
    {

        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
};

int main()
{

    LinkedList ob;
    ob.InsertAtHead(40);
    ob.InsertAtHead(30);
    ob.InsertAtHead(20);
    ob.InsertAtHead(10);

    ob.traversal();

    return 0;
}
