#include<bits/stdc++.h>
using namespace std;
class Deque{
    private:
        int capacity;
        int front,rear;
        int *ptr;
    public:
        Deque(int cap){
            capacity=cap;
            front=rear=-1;
            ptr=new int[capacity];
        }
        ~Deque(){
            delete []ptr;
        }
        void insertAtFront(int);
        void insertAtBack(int);
        void deleteAtFront();
        void deleteAtBack();
        int Front();
        int Rear();
        int FR();
        void view();
        bool isFull();
        bool isEmpty();
};
int Deque::Front(){
    return front;
}
int Deque::Rear(){
    return rear;
}
int Deque::FR(){
    cout<<"Rear: "<<rear<<" Front: "<<front<<endl;
}
void Deque::view(){
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
bool Deque::isFull(){
    return ((rear==capacity-1&&front==0)||(front-rear==1));
}
bool Deque::isEmpty(){
    return front==-1;
}
void Deque::insertAtFront(int data){
    if(isFull())
        cout<<"Dqeue is Full\n";
    else if(front==-1){
        front=rear=capacity-1;
        ptr[front] = data;
    }else if(front==0){
        front=capacity-1;
        ptr[front]=data;
    }else{
        front--;
        ptr[front]=data;
    }
}   
void Deque::insertAtBack(int data){
    if(isFull())
        cout<<"Deque is Full\n";
    else if(front==-1){
        front=rear=0;
        ptr[rear]=data;
    }else if(rear==capacity-1){
        rear=0;
        ptr[rear]=data;
    }else{
        rear++;
        ptr[rear]=data;
    }
}
void Deque::deleteAtBack(){
    if(isEmpty())
        cout<<"Deque is Empty\n";
    else if(front==rear){
        front=rear=-1;
    }else if(rear==0){
        rear=capacity-1;
    }else{
        rear--;
    }
}
void Deque::deleteAtFront(){
    if(isEmpty())
        cout<<"Deque is Empty\n";
    else if(front==rear){
        front=rear=-1;
    }else if(front==capacity-1){
        front=0;
    }else{
        front++;
    }
}
int main()
{
    Deque q(10);
    q.FR();
    q.insertAtBack(10);
    q.FR();
    q.insertAtBack(20);
    q.FR();
    q.insertAtBack(30);
    q.FR();
    q.view();
    return 0;
}