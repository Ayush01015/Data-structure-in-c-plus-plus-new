#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    node *left;
    int item;
    node *right;
};
class BST{
    private:
        node *root;
    protected:
        void preOrderRec(node *);
        void InOrderRec(node *);
        void postOrderRec(node *);
        void insertRec(int,node*);
    public:
        BST();
        bool isEmpty();
        void insert(int);
        void preOrder();
        void InOrder();
        void postOrder();
        int Search(int);
};
int BST::Search(int data){
    if(isEmpty())
        cout<<"Tree is Empty\n";
    else{

    }
}
void BST::preOrderRec(node *t){
    if(t){
        cout<<t->item<<" ";
        preOrderRec(t->left);
        preOrderRec(t->right);
    }
}
void BST::preOrder(){
    preOrderRec(root);
}
void BST::InOrderRec(node *t){
    if(t){
        InOrderRec(t->left);
        cout<<t->item<<" ";
        InOrderRec(t->right);
    }
}
void BST::InOrder(){
    InOrderRec(root);
}
void BST::postOrderRec(node *t){
    if(t){
        postOrderRec(t->left);
        postOrderRec(t->right);
        cout<<t->item<<" ";
    }
}
void BST::postOrder(){
    postOrderRec(root);
}
BST::BST(){
  root = NULL;  
}
bool BST::isEmpty(){
    return root==NULL;
}
void BST::insertRec(int data,node *t){
    node *n = new node;
    n->item=data;
    n->left=NULL;
    n->right=NULL;
    if(isEmpty()){
        root=n;
    }else if(data<=t->item){
        if(t->left!=NULL)
            insertRec(data,t->left);
        else
            t->left = n;       
    }else if(data>=t->item){
        if(t->right!=NULL)
            insertRec(data,t->right);
        else
            t->right = n;
    }
}
void BST::insert(int data){
    insertRec(data,root);
}
int main()
{
    BST t;
    t.insert(1);
    t.insert(1);
    t.insert(2);
    t.insert(2);
    t.insert(3);
    t.insert(4);
    t.insert(5);
    t.insert(6);
    t.insert(6);
    t.insert(7);
    t.insert(8);
    t.insert(9);
    t.preOrder();
    return 0;
}