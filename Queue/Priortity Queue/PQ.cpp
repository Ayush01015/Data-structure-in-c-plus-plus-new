#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int item;
        int priority;
        node *next;
        node(){
            item = -1; //all empty
            priority = -1; 
            next = NULL;
        }
};
class PQ{
    private:
        node *start;
    public:
        PQ();
        void insert(int,int);
        void view();
        void deleteHighestPriority();
        int getHighestPriorityElement();
        bool isEmpty();
        ~PQ();

};
bool PQ::isEmpty(){
    if(start==NULL)
        return true;
    return false;
}
PQ::~PQ(){
    node *t = start;
    while(start){   //not tested...
    start = t->next;
    delete t;
    }
}
PQ::PQ(){
    start = NULL;
}
int PQ::getHighestPriorityElement(){
    node *t = start;
    while(t)
        t=t->next;
    return t->item;  
}
void PQ::deleteHighestPriority(){
    if(start==NULL)
        cout<<"Queue is Empty\n";
    else{
        node *t = start;
        node *t1 = NULL;
        while(t->next!=NULL){
            t1=t;
            t=t->next;
        }
        if(t1!=NULL)
            t1->next = NULL;
        else
            start = NULL;
        delete t;
    }   
}
void PQ::view(){
    node *t = start;
    if(start==NULL)
        cout<<"Queue is Empty\n";
    else{
        while(t!=NULL){
            cout<<t->item<<" ";
            t=t->next; 
        }
    }
    cout<<endl;
}
void PQ::insert(int p,int data){  //priority and data 
    node *n = new node;
    n->item = data;
    n->priority = p;
    if(start==NULL){
        n->next = NULL;
        start = n;
    }else{
        node *t = start;
        if(start->priority>p){ 
            n->next = t;
            start = n;
        }else{
            node *t1 = NULL;
            while(t!=NULL){ 
                if(p>=t->priority){
                    t1=t;
                    t=t->next;   
                }
                else
                    break;
            }
            n->next = t1->next;
            t1->next = n;
        }
    }
}
int main()
{
    PQ p;
    p.insert(50,500);
    p.insert(60,800);
    p.insert(55,555);
    p.insert(55,666);
    p.insert(55,777);
    p.view();

    return 0;
}