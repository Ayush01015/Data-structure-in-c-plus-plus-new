//implementation with circular linked list
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int item;
        node *next;
};
class QLL{
    private:
        node *start;
        int front,rear;
    public:
        QLL();
        void insert(int);
        void view();
        void deleteNode();
        bool isEmpty();
        void viewRF();
        ~QLL();
        int count();

};
int QLL::count(){
    int c = 0;
    if(start==NULL)
        return 0;
    else if(front==rear)
        return 1;
    else{
        node *t = start;
        do{
            t=t->next;
            c++;
        }while(t!=start);
        return c;
    }
}

QLL::~QLL(){
    while(start)
        deleteNode();
}
bool QLL::isEmpty(){
    return start==NULL;
}
void QLL::viewRF(){
    cout<<"Rear: "<<rear<<endl;
    cout<<"Front: "<<front<<endl;
    // if(start!=NULL)
    // cout<<"Start->item: "<<start->item<<endl;
}
void QLL::view(){
    if(start==NULL)
        cout<<"Queue is Empty\n";
    else{
        cout<<"Queue --> ";
        node *t = start;
        do{
            cout<<t->item<<" ";
            t=t->next;
        }while(t!=start);
    }
    cout<<endl;
}
QLL::QLL(){
    start = NULL;
    front=rear=-1;
}
void QLL::insert(int data){
    node *n = new node;
    node *t = start;
    n->item = data;
    if(front==-1&&start==NULL){
        front=rear=0;
        n->next = n;
        start=n;
    }else if(front==rear){
        rear++;
        n->next = t;
        t->next = n;
    }
    else{
        rear++;
        while(t->next!=start){
            t=t->next;
        }
        n->next = start;
        t->next = n;
    }
    
}
void QLL::deleteNode(){
    node *r = start;
    if(start==NULL)
        cout<<"Queue is Empty\n";
    else if(front==rear){
        front = rear = -1;
        delete r;
        start = NULL;
    }
    else{
        node *t = start;
        front = front + 1;
        while(t->next!=start)
            t=t->next;
        start = r->next;
        t->next = start;
        delete r;
    }
}

int main()
{
    QLL l;
    while(1){
        l.viewRF();
        l.view();
        int choice;
        cout<<"Choose your Option...\n1.Insert\n2.Delete\n3.viewRF\n4.isEmpty\n5.Count\n6.Exit\n->";
        cin>>choice;
        switch (choice)
        {
        case 1:
            int data;
            cout<<"Enter Value you wish to enter\n";
            cin>>data;
            l.insert(data);
            break;
        case 2:
            l.deleteNode();
            break;
        case 3:
            l.viewRF();
            break;
        case 4:
            if(l.isEmpty())
                cout<<"Queue is Empty\n";
            else
                cout<<"Queue is not Empty\n";
            break;
        case 5:
            cout<<"Count: "<<l.count();
            break;
        case 6:
            cout<<"Exited...\n";
            break;
        default:
            cout<<"Invalid Choice\n";
            break;
        }
        if(choice==6)
            break;
    }
    
    return 0;
}