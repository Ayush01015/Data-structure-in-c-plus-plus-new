#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int item;
        node *next;
        node(){
            item = -1;
            next = NULL;
        }
        node(int data){
            item = data;
            next = NULL;
        }
};
class SLL{
    private:
        node *start;
    public:
        SLL();
        ~SLL();
        void insertAtFirst(int);
        void insertAtLast(int);
        void insertNode(node*,int);
        node* search(int);
        void view();
        void deleteFirstNode();
        void deleteLastNode();
        void deleteNode(node*);
};
SLL::SLL(){
    start = NULL; 
}
SLL::~SLL(){
    while(start)
        deleteFirstNode();
}
node* SLL::search(int data){
    node *t = start;
    while(t->next!=NULL){
        if(t->item == data)
            return t;
        t = t->next;
    }
    return NULL;
}
void SLL::insertAtFirst(int data){
    node *n = new node;
    n->item = data;
    n->next = start;
    start = n;
}
void SLL::insertAtLast(int data){
    node *n = new node;
    n->item = data;
    if(start==NULL){
        // cout<<"\nList was Empty inserting as first node\n";
        // cout<<"inserting...\n";
        start = n;
    }else{
        node *t = start;
        while(t->next!=NULL)
            t = t->next;
        t->next = n;
    }
    n->next = NULL;
}
void SLL::insertNode(node *r,int data){
    node *n = new node;
    n->item = data;
    n->next = r->next;
    r->next = n;
}
void SLL::deleteLastNode(){
    if(start == NULL)
        cout<<"List is Empty\n";
    else{
        node *t , *t1;
        t = start;
        t1 = NULL;
        while(t->next!=NULL){
            t1 = t;
            t = t->next;
        }
        if(t1!=NULL)
            t1->next = NULL;
        else
            start = NULL;
        delete t;
    }
}
void SLL::deleteFirstNode(){
    if(start == NULL)
        cout<<"List is Empty\n";
    else{
        node *t = start;
        start  = t->next;
        delete t;
    }
}
void SLL::deleteNode(node *r){
    if(start==NULL)
        cout<<"List is Empty\n";
    else{
        node *t = start;
        while(t->next!=r)
            t=t->next;
        t->next = r->next;
        delete r;
    }
}
void SLL::view(){
    node *t = start;
    while(t!=NULL){
        cout<<t->item<<" ";
        t = t->next;
    }
    cout<<endl;
}
int main()
{
    SLL l;
    l.insertAtFirst(20);
    l.insertAtFirst(10);
    l.insertAtLast(30);
    l.insertAtLast(40);
    l.insertAtLast(50);
    node *q = l.search(30);
    l.insertNode(q,999);
    l.view();
    l.deleteFirstNode();
    l.view();
    l.deleteLastNode();
    l.view();
    l.deleteNode(q);
    l.view();
    return 0;
}
