#include<iostream>
 using namespace std;

 class Node 
    {
        public:
        int data;
        Node *left;
        Node *right;

        Node(int value):data(value),left(nullptr),right(nullptr){}
    };

    class BST
    {
        private:
        Node *root;

        Node *insertion (Node *node,int value){
            if(node==nullptr){
                return new Node(value);
            }
            if(value<node->data){
                node->left=insertion(node->left,value);
            }
            else if(value>node->data){
                node->right=insertion(node->right,value);
            }
            return node;
        }
        Node *finMin(Node *node){
            while(node->left!=nullptr){
                node=node->left;
            }
            return node;
        }
        Node *deletion(Node *node,int value){
            if(node==nullptr){
               return nullptr;
            }
            if(value<node->data){
                node->left=deletion(node->left,value);
            }
            else if(value>node->data){
                node->right=deletion(node->right,value);
            }
            else{
                if(node->left==nullptr){
                    Node* temp=node->right;
                    delete node;
                    return temp;
                }
                if(node->right==nullptr){
                    Node* temp=node->left;
                    delete node;
                    return temp;
                }
            Node* temp=finMin(node->right);
            node->data=temp->data;
            node->right=deletion(node->right,temp->data);    
            }
            return node;
        }

        void Traversal(Node *node){
            if(node!=nullptr){
                Traversal(node->left);
                cout<<node->data<<" ";
                Traversal(node->right);
            }
        }

        bool searching(Node *node,int value){
            if(node==nullptr){
                return false;
            }
            if(node->data==value){
                return true;
            }
            if(value<node->data){
                return searching(node->left,value);
            }else{
                return searching(node->right,value);
            }
        }
        public:
        BST():root(nullptr){}

        void insert(int value){
            root=insertion(root,value);
        }
        void delet(int value){
            root=deletion(root,value);
        }
        void inorder(){
            Traversal(root);
            cout<<endl;
        }
        bool search(int value){
            return searching(root,value);
        }
    };

    int main (){
        BST bst;

        bst.insert(100);
        bst.insert(90);
        bst.insert(80);
        bst.insert(70);
        bst.insert(60);
        bst.insert(50);

        bst.inorder();
        int target;
        cin>>target;

        if(bst.search(target)){
            cout<<"FOUND!"<<endl;

        }else{
            cout<<"NOT FOUND!"<<endl;
        }
        bst.inorder();
        bst.delet(70);

        bst.inorder();

        return 0;
    }