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
        node* Search(node*,int);
        void deleteInBST(int,node*,node*);
    public:
        BST();
        bool isEmpty();
        void insert(int);
        void preOrder();
        void InOrder();
        void postOrder();
        node* Search(int);
        void deleteInBST(int);
};
void BST::deleteInBST(int data,node *parPtr,node *r){
    if(r==NULL){
        cout<<"BST is Empty\n";
    }else if(data<=r->item){
        if(r->left!=NULL)
            deleteInBST(data,r,r->left); //passing parent and it's left child
        if(r->left==NULL && r->right==NULL){  //0
            parPtr->left = NULL;
            delete r;
        }else if(r->left!=NULL && r->right!=NULL){  //2

        }else{ //1
            parPtr->left = r->right;
            delete r;
        }
    }else if(data>=r->item){
        if(r->right!=NULL)
            deleteInBST(data,r,r->right);
        if(r->left==NULL&&r->right==NULL){
            parPtr->right = NULL;
            delete r;
        }
        else if(r->left!=NULL && r->right!=NULL){  //2

        }else{ //1
            parPtr->right = r->left;
            delete r;
        }
    }
}

void BST::deleteInBST(int data){
    deleteInBST(data,NULL,root);
}
node* BST::Search(node *r,int data){
    node *t = root;
    if(isEmpty())
        cout<<"BST is Empty\n";
    else if(r->item==data)
        return r;
    else if(data<r->item){
        if(r->left!=NULL)
            Search(r->left,data);
    }else if(data>r->item){
        if(r->right!=NULL)
            Search(r->right,data);    
    }
}

node* BST::Search(int data){
    Search(root,data);
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
    t.insert(10);
    t.insert(20);
    t.insert(30);
    t.insert(40);
    t.insert(50);
    t.insert(999);
    
    t.preOrder();
    cout<<endl;
    node *t1 = t.Search(999);
    cout<<t1->item<<endl;
    return 0;
}