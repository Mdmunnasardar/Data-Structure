#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class Linkedlist{
private:
    Node *head;
    Node *tail;
public:
    Linkedlist(): head(nullptr){}
    void Display(){
        Node *current = head;
        while (current!=nullptr)
        {
            cout<<current->data<<" ";
            current = current->next;
        }
        cout<<endl;
    }
    void insert_at_head(int data){
        Node *newNode = new Node(data);
        if (head==nullptr)
        {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    void insert_at_end(int data){
        Node *newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    void insert_after(int data, int target){
         Node *newNode = new Node(data);
        Node *current = head;
        while (current->data!=target)
        {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }
   

};

int main(){
    Linkedlist list;
    list.insert_at_head(10);
    list.insert_at_end(20);
    list.insert_at_end(30);
    list.insert_at_end(40);
    list.Display();

    list.insert_at_end(50);
    list.Display();

    list.insert_after(35, 30);
    list.Display();

   
    return 0;
}