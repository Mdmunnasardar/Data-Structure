#include <iostream>
using namespace std;
class Stack
{
private:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int value) : data(value), next(nullptr) {}
    };
    Node *top;

public:
    Stack() : top(nullptr) {}
    void push(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }
    void pop()
    {
        top = top->next;
    }
    void Traverse()
    {
        Node *temp = top;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    Stack s;
    s.push(11);
    s.push(21);
    s.push(31);
    s.push(41);
    s.push(51);
    s.Traverse();

    s.pop();
    s.Traverse();
    return 0;
}