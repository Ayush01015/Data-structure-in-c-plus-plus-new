#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int item;
        node *next;
};
class SLL{
    private:
        node *start;
    public:
        SLL();
        ~SLL();
        void view();
        void insertAtFirst(int);
        void insertAtLast(int);
        void insertAfter(node*,int);
        node* searchNode(int);
        void deleteLastNode();
        void deleteFirstNode();
        void deleteNode(node*);
        void f1(){
            node *t = start;
            cout<<"\n"<<t->next->next->item<<endl;
        }
};
SLL::SLL(){
    start = NULL;
}
SLL::~SLL(){
    while(start)
        deleteFirstNode();
}
void SLL::view(){
    if(start==NULL)
        cout<<"List is Empty\n";
    else{
        node *t = start;
        while(t!=NULL){
            cout<<t->item<<" ";
            t=t->next;
        }
        cout<<endl;
    }
}
void SLL:: insertAtFirst(int data){
    node *n = new node;
    n->item = data;
    n->next = start;
    start = n;
}
void SLL::insertAtLast(int data){
    node *n = new node;
    n->item = data;
    if(start==NULL){
        start = n;
    }
    else{
        node *t = start;
        while(t->next!=NULL)
            t = t->next;
        t->next = n;
    }
        n->next = NULL;
}
void SLL::insertAfter(node *r,int data){
    node *n = new node;
    n->item = data;
    n->next = r->next;
    r->next = n;

}
node* SLL::searchNode(int data){
    node *t = start;
    while(t){
        if(t->item == data)
            return t;
        t = t->next;
    }
    cout<<"Node Not Found\n";
    return NULL;
}
void SLL::deleteLastNode(){
    node *t,*t1;
    if(start == NULL)
        cout<<"List is EMPTY\n";
    else{
        t = start;
        while(t->next!=NULL)
        {
            t1 = t;
            t = t->next;
        }
            t1->next = NULL;
            delete t;
    }

}
void SLL::deleteFirstNode(){
    if(start == NULL)
        cout<<"List is EMPTY\n";
    else{
        node *t = start;
        start = t->next;
        delete t;
    }
}
void SLL::deleteNode(node *r){
    if(start == NULL)
        cout<<"List is EMPTY\n";
    else{
        node *t = start;
        while(t->next!=r)
            t = t->next;
        t->next = r->next;
        delete r;
    }   
}

int main()
{
    SLL l;
    l.insertAtFirst(10);
    l.insertAtLast(99);
    l.insertAtLast(929);
    l.insertAtLast(919);
    // node *n = l.searchNode(929);
    // l.insertAfter(n,555);
    // l.view(); 
    // l.deleteLastNode();
    // l.view();
    // node *r = l.searchNode(929);
    // l.deleteNode(r);
    l.view();
    return 0;
}
