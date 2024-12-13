#include <iostream>
using namespace std;
class Queue {
private:
    int *arr;
    int capacity;
    int front;
    int rare;
public:
    Queue(int size) {
        arr = new int[size];
        capacity = size;
        front = 0;
        rare = -1;
    }
    void enqueue(int data) {
        arr[++rare] = data;
    }
    void dequeue() {
        front++;
    }
    void Traverse() {
        for (int i = front; i <= rare; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    Queue q(28);
    q.enqueue(11);
    q.enqueue(12);
    q.enqueue(13);
    q.enqueue(14);
    q.Traverse();
    q.dequeue();
    q.Traverse();
    return 0;
}