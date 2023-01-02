#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        node *prev;
        int item;
        node *next;
};
class DLL{
    private:
        node *start;
    public:
        DLL();
        ~DLL();
        void view();
        void insertAtFirst(int);
        void insertAtlast(int);
        void insertNode(node*,int);
        node* searchNode(int);
        void deleteFirstNode();
        void deleteLastNode();
        void deleteNode(node*);

};
DLL::DLL(){
    start = NULL;
}
DLL::~DLL(){
    while(start)
        deleteFirstNode();
}
void DLL::view(){
    if(start == NULL)
        cout<<"List is Empty\n";
    else{
        node *t = start;
        while(t!=NULL){
            cout<<t->item<<" ";
            t = t->next;
        }
    }    
    cout<<endl;
}
void DLL::insertAtFirst(int data){ 
    node *n = new node;
    n->item = data;
    n->prev = NULL;
    n->next = start;
    if(start!=NULL)
        start->prev = n;
    start = n;
}
void DLL::insertAtlast(int data){
    node *n = new node;
    if(start == NULL){
        start = n;
        n->prev = NULL;
    }
    else{
        node *t = start;
        while(t->next!=NULL)
            t = t->next;
        n->prev = t;
        t->next = n;
    }
        n->item = data;
        n->next = NULL;
}
void DLL::insertNode(node *d,int data){
    node *n = new node;
    n->item = data;
    n->prev = d;
    n->next = d->next;
    d->next->prev = n;
    d->next = n;
}
node* DLL::searchNode(int data){
    node *t = start;
    while(t!=NULL)
    {
        if(t->item==data)
            return t;
        t = t->next;
    }
        cout<<"Node not Found\n";
        return NULL;
}
void DLL::deleteFirstNode(){
    if(start == NULL)
        cout<<"List is Empty\n";
    else{
        node *t = start;
        t->next->prev = NULL;
        start = t->next;
        delete t;
    }
}
void DLL::deleteLastNode(){
    if(start == NULL)
        cout<<"List is Empty\n";
    else if(start->next == NULL){
        delete start;
        start = NULL;
    }
    else{
        node *t = start;
        while(t->next!=NULL)
            t = t->next;
            t->prev->next = NULL;
            delete t;
    }
}
void DLL::deleteNode(node* d){
    if(start==NULL)
        cout<<"List is Empty\n";
    else if(start == d){
        start = d->next;
        d->next->prev = NULL;
        delete d;
    }else if(d->next == NULL){
        d->prev->next = NULL;
        delete d;
    }
    else{
        d->next->prev = d->prev;
        d->prev->next = d->next;
        delete d;
    }
}
int main()
{
    DLL l;
    l.insertAtlast(10);
    l.insertAtlast(20);
    l.insertAtlast(30);
    l.insertAtlast(40);
    l.insertAtlast(50);
    l.insertAtlast(60);
    node *t = l.searchNode(30);
    l.insertNode(t,999);
    l.view();
    l.deleteFirstNode();
    l.view();   
    l.deleteLastNode();
    l.view();
    node *d = l.searchNode(50);
    l.deleteNode(d);
    l.view();
    
    return 0;
}