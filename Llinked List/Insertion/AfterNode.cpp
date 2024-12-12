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

    void Traversal()
    {
        Node *ptr = head;
       
        while (ptr != nullptr)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout<<endl;
    }
    void InsertAtHead(int data)
    {

        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void AfterANode(int target, int data)
    {
        Node *current = head;
        Node *newNode = new Node(data);
        newNode->next = current->next;
        current->next = newNode;
    }
    
};
int main()
{
    LinkedList ob;
    ob.InsertAtHead(40);
    ob.InsertAtHead(30);
    ob.InsertAtHead(20);
    ob.InsertAtHead(10);
    cout<<"Linked List: ";
    ob.Traversal();
    ob.AfterANode(30, 50);
    cout<<"After a node Insert: ";
    ob.Traversal();

    return 0;
}