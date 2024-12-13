#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};
class Queue {
private:
    Node *front;
    Node *rare;

public:
    Queue() : front(nullptr), rare(nullptr) {}
    void enqueue(int data){
        Node *newNode = new Node(data);
        if (front == nullptr){
            front = rare = newNode;
            return;
        }
        rare->next = newNode;
        rare = newNode;
    }
    void dequeue(){
        front = front->next;
    }
    void Traverse(){
        Node *temp = front;
        while (temp!=nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main(){
    Queue q;
    q.enqueue(11);
    q.enqueue(12);
    q.enqueue(13);
    q.enqueue(14);
    q.Traverse();

    q.dequeue();
    q.Traverse();
    return 0;
}