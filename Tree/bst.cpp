#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
private:
    Node *root;

    
    Node *insertNode(Node *node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value); // Create a new node if position is empty
        }

        if (value < node->data)
        {
            node->left = insertNode(node->left, value); // Insert into the left subtree
        }
        else if (value > node->data)
        {
            node->right = insertNode(node->right, value); // Insert into the right subtree
        }

        return node; 
    }

    
    void inOrderTraversal(Node *node)
    {
        if (node != nullptr)
        {
            inOrderTraversal(node->left);      
            cout << node->data << " ";          
            inOrderTraversal(node->right);     
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

   
    void insert(int value)
    {
        root = insertNode(root, value);
    }

    void inOrder()
    {
        inOrderTraversal(root);
        cout << endl;
    }
};

int main()
{
    BinarySearchTree bst;

    
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    
    cout << "In-order Traversal: ";
    bst.inOrder();

    return 0;
}

    