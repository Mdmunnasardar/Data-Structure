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
            return new Node(value);
        }

        if (value < node->data)
        {
            node->left = insertNode(node->left, value); 
        }
        else if (value > node->data)
        {
            node->right = insertNode(node->right, value);
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

    bool searchNode(Node *node, int value)
    {
        if (node == nullptr)
        {
            return false; 
        }

        if (node->data == value)
        {
            return true;
        }

        if (value < node->data)
        {
            return searchNode(node->left, value); 
        }
        else
        {
            return searchNode(node->right, value);
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

   
    bool search(int value)
    {
        return searchNode(root, value);
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

    
    int target;
    cout << "Enter a number to search: ";
    cin >> target;

    if (bst.search(target))
    {
        cout << target << " is found in the BST." << endl;
    }
    else
    {
        cout << target << " is not found in the BST." << endl;
    }

    return 0;
}
