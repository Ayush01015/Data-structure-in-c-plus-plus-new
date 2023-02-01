#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        node *left;
        int item;
        node* right;
};
class BST{
    private:
        node *root;
    protected:
        void insert(int,node*);
        void preorderTraverse(node*);
        void inorderTraverse(node*);
        void postorderTraverse(node*);
        node* Search(node*,int);
    public:
        BST();
        bool isEmpty();
        void insert(int);
        void inorder();
        void preorder();
        void postorder();
        node* Search(int);
};
BST::BST(){
    root = NULL;
}
bool BST::isEmpty(){
    return root==NULL;
}
void BST::insert(int data,node *r){
    node *n = new node;
    n->left = NULL;
    n->item = data;
    n->right = NULL;
    if(isEmpty()){
        root=n;
    }
    else if(data<r->item){
        if(r->left!=NULL) 
            insert(data,r->left);
        else
            r->left = n;
    }
    else if(data>r->item){
        if(r->right!=NULL) 
            insert(data,r->right);
        else
            r->right = n;
    }
}
void BST::insert(int data){
    insert(data,root);
}
void BST::preorderTraverse(node *r){
    if(r){
        cout<<r->item<<" ";
        preorderTraverse(r->left);
        preorderTraverse(r->right);
    }
}
void BST::preorder(){
    preorderTraverse(root);
}
void BST::inorderTraverse(node *r){
    if(r){
        inorderTraverse(r->left);
        cout<<r->item<<" ";
        inorderTraverse(r->right);
    }
}
void BST::inorder(){
    inorderTraverse(root);
}
void BST::postorderTraverse(node *r){
    if(r){
        postorderTraverse(r->left);
        postorderTraverse(r->right);
        cout<<r->item<<" ";
    }
}
void BST::postorder(){
    postorderTraverse(root);
}
node* BST::Search(node *r,int data){
    if(isEmpty())
        cout<<"BST is Empty\n";
    else if(r->item==data)
        return r;
    else if(data<r->item){
        if(r->left!=NULL)
            Search(r->left,data);  
    }
    else if(data>r->item){
        if(r->right!=NULL)
            Search(r->right,data); 
    }
    else{
        return NULL;
    }
}
node* BST::Search(int data){
    return Search(root,data);
}

int main()
{
    BST t;
    return 0;
}