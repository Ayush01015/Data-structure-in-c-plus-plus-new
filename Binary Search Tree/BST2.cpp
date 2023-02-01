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

int main()
{
    BST t;
    return 0;
}