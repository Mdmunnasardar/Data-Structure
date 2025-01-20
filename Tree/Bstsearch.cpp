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

    class BinarySearchtree{
        private:
        Node *root;

        Node *insertNode(Node *node,int value)
        {
            if(node==nullptr)
            {
                return new Node(value);
            }
            if(value<node->data)
            {
                node->left=insertNode(node->left,value);
            }
            else if(value>node->data)
            {
                node->right=insertNode(node->right,value);
            }
            return node;
        }
        void inordertraversal(Node *node){
            if(node!=nullptr){
                inordertraversal(node->left);
                cout<<node->data<<" ";
                inordertraversal(node->right);
            }
        }
        bool searchNode(Node *node,int value)
        {
            if(node==nullptr)
            {
                return false;
            }
            if(node->data==value)
            {
                return true;
            }
            if(value<node->data)
            {
                return searchNode(node->left,value);
            }
            else
            {
                return searchNode(node->right,value);
            }
        }
        public:
        BinarySearchtree():root(nullptr){}

        void insert(int value){
            root=insertNode(root,value);
        }
        void inorder(){
            inordertraversal(root);
        }
        bool search(int value){
            return searchNode(root,value);
        }

    };
int main() {
        BinarySearchtree bst;

        bst.insert(100);                                
        bst.insert(70);                                
        bst.insert(10);                                
        bst.insert(60);                                
        bst.insert(50);                                
        bst.insert(40);    
        bst.inorder();
        int target ;
        cin>>target;
        if(bst.search(target))
        {
            cout<<target;
        }   
        else{
            cout<<"not found";
        }                        
















    cout <<endl;
    return 0;
}