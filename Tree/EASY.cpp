#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

Node *insert(Node *root, int value)
{
    if (root == NULL)
    {
        return new Node(value);
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }
    return root;
}

bool Search(Node *root, int value)
{
    if (root == NULL)
        return false;
    if (root->data == value)
        return true;
    return (value < root->data) ? Search(root->left, value) : Search(root->right, value);
}

Node *findMin(Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node *deleteNode(Node *root, int value)
{
    if (root == NULL)
        return root;

    // Traverse the tree to find the node to delete
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        // Node to be deleted found

        // Case 1: No child or one child
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Case 2: Two children
        Node *temp = findMin(root->right);                 // Find the smallest value in the right subtree
        root->data = temp->data;                           // Replace the data with the successor's data
        root->right = deleteNode(root->right, temp->data); // Delete the successor
    }
    return root;
}

void inorderTraversal(Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main()
{
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder traversal before deletion: ";
    inorderTraversal(root);
    cout << endl;

    root = deleteNode(root, 50);

    cout << "Inorder traversal after deletion: ";
    inorderTraversal(root);
    cout << endl;

    int target;
    cin>>target;

    if(Search(root,target)){
        cout<<"FOUND"<<endl;
    }else{
        cout<<"Not found";
    }
    inorderTraversal(root);
    return 0;
}
