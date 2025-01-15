#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;

    Node(int value) : data(value), right(nullptr), left(nullptr) {}
};

class BinarySearchTree
{
private:
    Node *root;

    Node* InsertNode(Node *node, int value) {
        if (node == nullptr) {
            return new Node(value); 
        }
        if (value < node->data) {
            node->left = InsertNode(node->left, value); 
        } else if (value > node->data) {
            node->right = InsertNode(node->right, value); 
        }
        return node; 
    }

    void inOrderTraversal(Node *node) {
        if (node != nullptr) {
            inOrderTraversal(node->left); 
            cout << node->data << " ";    
            inOrderTraversal(node->right); 
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = InsertNode(root, value); 
    }

    void inOrder() {
        inOrderTraversal(root); 
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(40);
    bst.insert(30);
    bst.insert(60);
    bst.insert(20);
    bst.insert(10);
    bst.inOrder(); 
    cout << endl;
    return 0;
}
