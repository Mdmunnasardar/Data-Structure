#include<iostream>
 using namespace std;

 class Node
    {
        public:
        int data;
        Node *left;
        Node *right;


        Node (int value):data(value),left(nullptr),right(nullptr){}
    };

    class BST
    {
        private:
        Node *root;

        Node *Insertion(Node *node,int value){
        if(node==nullptr){
            return new Node(value);
        }
        if(value<node->data){
            node->left=Insertion(node->left,value);
        }
        if(value>node->data){
            node->right=Insertion(node->right,value);
        }
        return node;
        }
        Node *FindMin(Node *node){
            while(node->left!=nullptr){
                node=node->left;
            }
            return node;
        }
        Node *deleteNode(Node *node,int value){
            if(node==nullptr){
                return nullptr;
            }
            if(value<node->data){
                node->left=deleteNode(node->left,value);
            }
            else if(value>node->data){
                node->right=deleteNode(node->right,value);
            }else{

                if(node->left==nullptr){
                    Node *temp=node->right;
                    delete node;
                    return temp;
                }
                if (node->right==nullptr){
                    Node *temp=node->left;
                    delete node;
                    return temp;
                }
                Node *temp=FindMin(node->right);
                node->data=temp->data;
                node->right=deleteNode(node->right,temp->data);
            }
            return node;
        }


        void Inot(Node *node){
        if(node!=nullptr){
            Inot(node->left);
            cout<<node->data<<" ";
            Inot(node->right); 
        }
        }

        bool searching(Node *node,int value){
        if(node==nullptr){
            return false;
        }
        if(value==node->data){
            return true;
        }
        if(value<node->data){
            return searching(node->left,value);
        }
        else{
            return searching(node->right,value);
        }
        
        }
        public:
        BST():root(nullptr){}

        void insert(int value){
            root=Insertion(root,value);
        }
        void inorder(){
            Inot(root);
        }
        bool search(int value){
            return searching(root,value);
        }
        void delet(int value){
            root=deleteNode(root,value);
        }



    };

    int main(){
        BST bst;
        bst.insert(100);
        bst.insert(90);
        bst.insert(80);
        bst.insert(70);
        bst.insert(60);
        bst.insert(50);

        bst.inorder();
      
        int target;
          cout <<"Enter searching number";
        cin>>target;

        if(bst.search(target)){
            cout<<"FOUND!";
        }else{
            cout<<"NOT FOUND!";
        }
        bst.inorder();
        bst.delet(70);

        bst.inorder();
return 0;
    }