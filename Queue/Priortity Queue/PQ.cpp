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

};
PQ::PQ(){
    start = NULL;
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
    p.insert(10,100);
    p.insert(1,1111);
    p.insert(1111,2222);
    p.insert(1222,3333);
    p.view();

    return 0;
}