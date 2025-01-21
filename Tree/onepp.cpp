#include <iostream>
using namespace std;


    class Node
    {
        public:
        int data;
        Node *left;
        Node *right;
        

        Node (int value):data(value),left(nullptr),right(nullptr){}
    };


    class BinarySearchTree 
    {
        private:
        Node *root;

        Node* Insertion (Node *node,int value){
            if(node==nullptr){
                return new Node (value);

            }
            if(value > node -> data){
                node->left = Insertion(node->left,value);
            }
            else if( value < node-> data){
                node->right = Insertion (node->right,value);
            }
            return node;
        }
        void InOrderTraversal(Node *node){
            if(node!=nullptr){
                InOrderTraversal(node->left);
                cout<<node->data<<" ";
                InOrderTraversal(node->right);
            }
        }

    public:
    BinarySearchTree():root(nullptr){}

    void Insert ( int value){
        root=Insertion(root,value);
    }
    void inorder(){
        InOrderTraversal(root);
    }

    };

int main() {
    BinarySearchTree bst;
    bst.Insert(50); 
    bst.Insert(40); 
    bst.Insert(30); 
    bst.Insert(20); 

    bst.inorder();
    cout <<endl;
    return 0;
}