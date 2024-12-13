#include <iostream>
using namespace std;
class Stack
{
private:
    int *arr;
    int capacity;
    int top;

public:
    Stack(int size)
    {
        arr = new int[size];
        capacity = size;
        top = -1;
    }
    void push(int data)
    {
        arr[++top] = data;
    }
    void pop()
    {
        --top;
    }
    void Traverse()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Stack s(10);
    s.push(11);
    s.push(21);
    s.push(31);
    s.push(41);
    s.push(51);
    s.push(61);
    s.Traverse();

    s.pop();
    s.Traverse();
    return 0;
}