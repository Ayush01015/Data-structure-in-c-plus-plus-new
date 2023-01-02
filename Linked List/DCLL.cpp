#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        node *prev;
        int item;
        node *next;
};
class DCLL{
    private:
        node *start;
    public:
        DCLL();
        ~DCLL();
        void view();
        void insertAtFirst(int);
        void insertAtLast(int);
        void insertNode(node*,int);
        node* searchNode(int);
        void deleteFirstNode();
        void deleteLastNode();
        void deleteNode(node*);
};
DCLL::DCLL(){
    start = NULL;
}
DCLL::~DCLL(){
    while(start)
        deleteLastNode();
}
void DCLL::view(){
    node *t = start;
    do{
        cout<<t->item<<" ";
        t = t->next;
    }while(t != start);
    cout<<endl;
}
void DCLL::insertAtFirst(int data){
    node *n = new node;
    if(start == NULL){
        n->prev = n;
        n->next = n;
    }else{
        n->next = start;
        n->prev = start->prev;
        start->prev->next = n;
    }
        n->item = data;
        start = n;
}
void DCLL::insertAtLast(int data){
    node *n = new node;
    if(start == NULL){
        start = n;
        n->next = n;
        n->prev = n;
    }else{
        n->next = start;
        n->prev = start->prev;
        start->prev->next = n;
        start->prev = n;
    }
        n->item = data;
}
node* DCLL::searchNode(int data){
    node *t = start;
    do{
        if(t->item == data)
            return t;
        t = t->next;
    }while(t!=start);
        cout<<"Node not found\n";
    return NULL;
}
void DCLL::insertNode(node *r,int data){
    node *n = new node;
    r->next->prev = n;
    n->item = data;
    n->next = r->next;
    n->prev = r;
    r->next = n;

}
void DCLL::deleteFirstNode(){
    node *d = start;
    if(start == NULL)
        cout<<"List is Empty\n";
    else{
        start->next->prev = start->prev;
        start->prev->next = start->next;
        start = start->next;
        delete d;
    }

}
void DCLL::deleteLastNode(){
    node *d = start->prev;
    if(start == NULL)
        cout<<"List is Empty\n";
    else{
        start->prev = start->prev->prev;
        start->prev->prev->next = start;
        delete d;
    }
}
void DCLL::deleteNode(node *d){
    if(start == NULL)
        cout<<"List is Empty\n";
    else{
        d->prev->next = d->next;
        d->next->prev = d->prev;
        start = d->next;
        delete d;
    }

}
int main()
{
    DCLL l;
    l.insertAtLast(10);
    l.insertAtLast(20);
    l.insertAtLast(30);
    l.insertAtLast(40);
    l.insertAtLast(50);
    l.view();
    return 0;
}