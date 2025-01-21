#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insertNode(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertNode(node->left, value);
        } else if (value > node->data) {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    // Helper function to find the minimum value in a subtree
    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left; // Keep moving to the leftmost node
        }
        return node;
    }

    // Helper function to delete a node
    Node* deleteNode(Node* node, int value) {
        if (node == nullptr) {
            return nullptr; // Node not found, return null
        }

        // Traverse the tree to find the node to delete
        if (value < node->data) {
            node->left = deleteNode(node->left, value); // Go to the left subtree
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value); // Go to the right subtree
        } else {
            // Node found
            // Case 1: Node with no children (leaf node)
            if (node->left == nullptr && node->right == nullptr) {
                delete node; // Delete the node
                return nullptr; // Return null to the parent
            }

            // Case 2: Node with one child
            if (node->left == nullptr) {
                Node* temp = node->right; // Replace node with its right child
                delete node; // Delete the current node
                return temp; // Return the right child to the parent
            }
            if (node->right == nullptr) {
                Node* temp = node->left; // Replace node with its left child
                delete node; // Delete the current node
                return temp; // Return the left child to the parent
            }

            // Case 3: Node with two children
            Node* temp = findMin(node->right); // Find the in-order successor (smallest in the right subtree)
            node->data = temp->data; // Replace the current node's data with the successor's data
            node->right = deleteNode(node->right, temp->data); // Recursively delete the successor
        }

        return node; // Return the updated node to the parent
    }

    // In-order traversal (for testing)
    void inOrderTraversal(Node* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    // Insert a value into the BST
    void insert(int value) {
        root = insertNode(root, value);
    }

    // Wrapper function for deleteNode
    void deleteValue(int value) {
        root = deleteNode(root, value);
    }

    // Wrapper function for inOrderTraversal
    void inOrder() {
        inOrderTraversal(root);
        cout << endl;
    }
};

// Main function
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

    // Print the BST in in-order traversal
    cout << "In-order Traversal before deletion: ";
    bst.inOrder();

    // Delete a node with no children
    bst.deleteValue(20);
    cout << "After deleting 20: ";
    bst.inOrder();

    // Delete a node with one child
    bst.deleteValue(30);
    cout << "After deleting 30: ";
    bst.inOrder();

    // Delete a node with two children
    bst.deleteValue(50);
    cout << "After deleting 50: ";
    bst.inOrder();

    return 0;
}
