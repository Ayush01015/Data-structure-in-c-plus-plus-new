#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int item;
        node *next;
};
class CLL{
    private:
        node *start;
    public:
        CLL();
        ~CLL();
        void view();
        node* searchNode(int);
        void insertAtFirst(int);
        void insertAtLast(int);
        void insertNode(node*,int);
        void deleteFirstNode();
        void deleteLastNode();
        void deleteNode(node*);
};
CLL::CLL(){
    start=NULL;
}
CLL::~CLL(){
    while(start)
        deleteFirstNode();
}
void CLL::view(){
    node *t = start;
    do{
        cout<<t->item<<" ";
        t = t->next;
    }while(t != start);
    cout<<endl;
}
void CLL::insertAtFirst(int data){
    node *n = new node; 
    if(start!=NULL){
        node *t = start;
        while(t->next!=start)
            t = t->next;
        t->next = n;
        n->next = start;
    }else{
        n->next = n;
    }
        n->item = data;
        start = n;     
}
void CLL::insertAtLast(int data){
    node *n = new node;
    if(start == NULL){
        start = n;
        n->next = n;
    }else{
        node *t = start;
        while(t->next!=start)
            t = t->next;
        t->next = n;
        n->next = start;
    }
        n->item = data;
}
void CLL::insertNode(node *r,int data){
    node *n = new node;
    n->item = data;
    n->next = r->next;
    r->next = n;
}
node* CLL::searchNode(int data){
    node *t = start;
    do{
        if(t->item == data)
            return t;
        t = t->next;
    }while(t!=start);
    cout<<"Node not Found\n";
    return NULL;
}
void CLL::deleteFirstNode(){
    if(start == NULL)
        cout<<"List is Empty\n";
    else{
        node *t = start;
        node *r = start;
        while(t->next != start)
            t = t->next;
        t->next = start->next;
        start = start->next;
        delete r;
    }
}
void CLL::deleteLastNode(){
    if(start == NULL)
        cout<<"List is Empty\n";
    else{
        node *t1 = NULL, *t = start;
        while(t->next != start){
            t1=t;
            t = t->next;
        }
        if(t1!=NULL)
            t1->next = start;
        else    
            start = NULL;
        delete t;        
    }
}
void CLL::deleteNode(node *r){
    node *t = start;
    if(r==start){
        while(t->next!=start)   
            t = t->next;
        start = r->next;
        t->next = start;
    }else{
        while(t->next != r){
            t = t->next;
        }
        t->next = r->next;
    }
    delete r;
}
int main()
{
    CLL l;
    l.insertAtLast(10);
    l.insertAtLast(20);
    l.insertAtLast(30);
    l.insertAtLast(40);
    l.insertAtLast(50);
    l.insertAtFirst(999);
    node *t = l.searchNode(999);
    l.insertNode(t,555);
    l.view();
    node *r = l.searchNode(999);
    l.deleteNode(r);
    l.view();
    return 0;
}