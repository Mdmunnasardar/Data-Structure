#include <iostream>
using namespace std;

    class Node
    {
        public:
        int data;
        Node *left;
        Node *right;

        Node(int value):data(value),left(nullptr),right(nullptr){}
    };

    class BinarySearchTree {
        private:
        Node *root;


        Node* Insertion(Node *node,int value){
            if(node==nullptr){
                return new Node(value);

            }
            if (value>node->data){
                
                node->left=Insertion(node->left,value);
            }
            else if (value <node->data){
                node->right=Insertion(node->right,value);

            }
            return node;
        } 
        void InorderTraversal(Node *node){
            if(node!=nullptr){
                InorderTraversal(node->left);
                cout<<node->data<<" ";
                InorderTraversal(node->right);

            }
        }
        public:
        BinarySearchTree (): root(nullptr){}
        

        void insert(int value){
            root= Insertion(root,value);

        }
        void inorder(){
        InorderTraversal(root);
            cout<<endl;
        }
    };





int main() {
    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(40);
    bst.insert(30);
    bst.insert(20);

    bst.inorder();






    return 0;
}