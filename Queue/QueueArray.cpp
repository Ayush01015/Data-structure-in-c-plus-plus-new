#include<bits/stdc++.h>
using namespace std;
class Queue{
    private:
        int capacity;
        int front, rear;
        int *ptr;
    public:
        Queue(int);
        void enQueue(int);
        void deQueue();
        bool isEmpty();
        bool isFull();
        int count();
        void view();
};
void Queue::view(){
    for(int i=0;i<capacity;i++)
        cout<<ptr[i]<<" ";
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
    if(isFull())
        cout<<"Queue is Full\n";
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
int main()
{
    Queue q(5);
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.view();
    return 0;
}