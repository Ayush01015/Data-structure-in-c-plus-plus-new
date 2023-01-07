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
        void insertAtLast(int);
        node* searchNode(int);
        void deleteLastNode();
        void deleteFirstNode();
        node* lastNode();

};
node* SLL::lastNode(){
    node *t = start;
    while(t->next!=NULL)
        t=t->next;
    return t;
}
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
class Stack:private SLL{        //class stack
    public:
        Stack():SLL(){
        }
        void pop();
        void push(int);
        void  peek();

};
void Stack :: push(int data){
    insertAtLast(data);
}
void Stack :: pop(){
    deleteLastNode();
}
void Stack :: peek(){
    node *t = lastNode();
    if(t==NULL)
        cout<<"Stack is Empty\n";
    else
        cout<<t->item<<endl;        
}
int main()
{
    Stack s1;
    s1.push(10);
    s1.push(330);
    s1.peek();    
    return 0;
}
