#include <iostream>
using namespace std;

// Node class to represent each node in the Binary Search Tree (BST)
class Node {
public:
    int data;      // Data stored in the node
    Node* left;    // Pointer to the left child
    Node* right;   // Pointer to the right child

    // Constructor to initialize a new node with a given value
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// BinarySearchTree class to manage the BST operations
class BinarySearchTree {
private:
    Node* root;  // Root node of the BST

    // Recursive function to insert a value into the BST
    Node* insertNode(Node* node, int value) {
        // If the node is null, create a new node with the given value
        if (node == nullptr) {
            return new Node(value);
        }

        // If the value is smaller, insert it in the left subtree
        if (value < node->data) {
            node->left = insertNode(node->left, value);
        } 
        // If the value is greater, insert it in the right subtree
        else if (value > node->data) {
            node->right = insertNode(node->right, value);
        }

        return node;  // Return the updated node
    }

    // Helper function to find the node with the minimum value in the subtree
    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Recursive function to delete a node with a given value from the BST
    Node* deleteNode(Node* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }

        // If the value to be deleted is smaller, search in the left subtree
        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } 
        // If the value is greater, search in the right subtree
        else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } 
        // If the node with the given value is found
        else {
            // Case 1: Node has no children (leaf node)
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }

            // Case 2: Node has only a right child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }

            // Case 3: Node has only a left child
            if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Case 4: Node has two children
            // Find the in-order successor (smallest value in the right subtree)
            Node* temp = findMin(node->right);
            node->data = temp->data; // Replace current node's value with successor
            node->right = deleteNode(node->right, temp->data); // Delete the successor
        }

        return node;  // Return the updated node
    }

    // Recursive function to perform in-order traversal of the BST
    void inOrderTraversal(Node* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << node->data << " ";  // Print the current node's value
            inOrderTraversal(node->right);
        }
    }

    // Recursive function to search for a value in the BST
    bool searchNode(Node* node, int value) {
        if (node == nullptr) {
            return false;  // Value not found
        }

        if (value == node->data) {
            return true;  // Value found
        }

        // Recursively search in the left or right subtree
        if (value < node->data) {
            return searchNode(node->left, value);
        } 
        else {
            return searchNode(node->right, value);
        }
    }

public:
    // Constructor initializes the BST with an empty root
    BinarySearchTree() : root(nullptr) {}

    // Public function to insert a value into the BST
    void insert(int value) {
        root = insertNode(root, value);
    }

    // Public function to delete a value from the BST
    void deleteValue(int value) {
        root = deleteNode(root, value);
    }

    // Public function to print the BST in in-order traversal
    void inOrder() {
        inOrderTraversal(root);
        cout << endl;
    }

    // Public function to search for a value in the BST
    bool search(int value) {
        return searchNode(root, value);
    }
};

// Main function to demonstrate the BST operations
int main() {
    BinarySearchTree bst;

    // Insert nodes into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Print the BST in in-order traversal before deletion
    cout << "In-order Traversal before deletion: ";
    bst.inOrder();

    // Delete some nodes from the BST
    bst.deleteValue(20);
    bst.deleteValue(30);
    bst.deleteValue(50);

    // Print the BST in in-order traversal after deletion
    cout << "In-order Traversal after deletions: ";
    bst.inOrder();

    // Search for a value interactively
    int target;
    cout << "Enter a number to search: ";
    cin >> target;

    // Display search result
    if (bst.search(target)) {
        cout << target << " is found in the BST." << endl;
    } else {
        cout << target << " is not found in the BST." << endl;
    }

    return 0;
}
