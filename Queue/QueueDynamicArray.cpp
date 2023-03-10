#include<bits/stdc++.h>
using namespace std;
class Queue{
    private:
        int capacity;
        int front, rear;
        int *ptr;
    public:
        Queue();
        Queue(int);
        void enQueue(int);
        void deQueue();
        bool isEmpty();
        bool isFull();
        void view();
        void peek();
        ~Queue();
        int count();
        void doubleQueue();
        void halfQueue();
};
void Queue::doubleQueue(){
    capacity*=2;
    // int *temp = new int[capacity];
    // for(int i=front;i<=rear;i++)
    //     temp[i]=ptr[i];
    // if(rear<front)
    //     for(int i=0;i<=rear;i++)
    //         temp[i]=ptr[i];
}
void Queue::halfQueue(){
    capacity/=2;
    int *temp = new int[capacity];
    if(front<rear){
        for(int i=front;i<=rear;i++)
            temp[i]=ptr[i];
    }
    else if(front>rear){
        for(int i=0;i<=rear;i++)
            temp[i]=ptr[i];
        for(int j=front;j<=capacity-1;j++)
            temp[j]=ptr[j];
    }else if(front==rear){
        temp[front]=ptr[front];
    }
    else if(capacity-1==rear&&front==0){
        for(int i=0;i<capacity;i++)
            temp[i]=ptr[i];
    }
}   
int Queue::count(){
    int count = 0;
    if(front==-1)
        cout<<"Queue is Empty\n";
    else if(front<rear){
        for(int i=front;i<=rear;i++)
            count++;
    }
    else if(front>rear){
        for(int i=0;i<=rear;i++)
            count++;
        for(int j=front;j<=capacity-1;j++)
            count++;
    }else if(front==rear){
        count++;
    }
    else if(capacity-1==rear&&front==0){
        for(int i=0;i<capacity;i++)
            count++;
    }
    return count;
}
Queue::~Queue(){
    delete []ptr;
}
Queue::Queue(){
    capacity = 1;
    front = -1;
    rear  = -1;
    ptr = new int[capacity];
}
void Queue::peek(){
    cout<<"Front: "<<front<<endl;
    cout<<"Rear: "<<rear<<endl;
}
void Queue::view(){
    cout<<"Queue---> ";
    if(front==-1)
        cout<<"Queue is Empty\n";
    else if(front<rear){
        for(int i=front;i<=rear;i++)
            cout<<ptr[i]<<" ";
    }
    else if(front>rear){
        for(int i=0;i<=rear;i++)
            cout<<ptr[i]<<" ";
        for(int j=front;j<=capacity-1;j++)
            cout<<ptr[j]<<" ";
    }else if(front==rear){
        cout<<ptr[front];
    }
    else if(capacity-1==rear&&front==0){
        for(int i=0;i<capacity;i++)
            cout<<ptr[i]<<" ";
    }
    cout<<endl;
}
Queue::Queue(int cap){
    capacity = cap;
    front = -1;
    rear  = -1;
    ptr = new int[capacity];
}
bool Queue::isFull(){
    if(((capacity == rear+1)&&front==0)||(front>rear&&front-rear==1))
        return true;
    else 
        return false;
}
bool Queue::isEmpty(){
    if(front==-1&&rear==-1)
        return true; 
    else
        return false;
}
void Queue::enQueue(int data){
    if(isFull()){
        doubleQueue();
        //
    }
    else if(rear==-1&&front==-1){
        rear=0;
        front=0;
        ptr[rear] = data; 
    }else if(capacity==rear+1&&front>0){
        rear=0;
        ptr[rear] = data;
    }else{
        rear++;
        ptr[rear]=data;
    }
}
void Queue::deQueue(){
    if(isEmpty())
        cout<<"Queue is Empty\n";
    else if(front==rear){
        front=-1;
        rear=-1;
    }else if(capacity-1==front){
        front=0;
    }
    else{
        front++;
    }
}
int main()
{
    Queue q(5);
    // q.enQueue(10);
    // q.enQueue(20);
    // q.enQueue(30);
    // q.enQueue(40);
    // q.enQueue(50);
    // q.enQueue(60);
    // q.enQueue(70);
    // q.enQueue(80);
    // q.enQueue(90);
    // q.enQueue(100);
    // q.enQueue(101);
    // q.peek();
    // q.view();

    while(1){
        q.view();
        int choice;
        cout<<"Choose your Option...\n1.Insert\n2.Delete\n3.isFull\n4.isEmpty\n5.Exit\n";
        cin>>choice;
        switch (choice)
        {
        case 1:
            int data;
            cout<<"Enter Value you wish to enter\n";
            cin>>data;
            q.enQueue(data);
            break;
        case 2:
            q.deQueue();
            break;
        case 3:
            if(q.isFull())
                cout<<"Queue is Full"<<endl;
            else
                cout<<"Queue is not Full\n";
            break;
        case 4:
            if(q.isEmpty())
                cout<<"Queue is Empty\n";
            else
                cout<<"Queue is not Empty\n";
            break;
        case 5:
            cout<<"Exited...\n";
            break;
        default:
            cout<<"Invalid Choice\n";
            break;
        }
        if(choice==5)
            break;
    }

    return 0;   
}