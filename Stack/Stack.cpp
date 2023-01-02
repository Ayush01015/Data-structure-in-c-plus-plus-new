#include<bits/stdc++.h>
using namespace std;
class Stack{
    private:
        int capacity;
        int top;
        int *stack;
    public:
        Stack(int);
        ~Stack();
        void peek();
        void push(int);
        void pop();
        void isStackOverflow();
        void isStackUnderflow();
        void reverseStack();
        int minimumInStack();
};
Stack::Stack(int cap){
    capacity = cap;
    top = -1;
    stack = new int[cap];
}
Stack::~Stack(){
    delete []stack;
    delete this;
}
void Stack :: push(int data){
    if(top == capacity - 1)
        cout<<"Stack OverFlow\n";
    else{
        top+=1;
        stack[top] = data;
    }
}
void Stack :: peek(){
    cout<<stack[top]<<endl;
}
void Stack :: pop(){
    if(top == -1)
        cout<<"Stack is Empty\n";
    else
        top-=1;
}
void Stack::isStackOverflow(){
    if(top == capacity -1)
        cout<<"StackOverflow\n";
    else
        cout<<"Stack has Space\n";
}
void Stack::isStackUnderflow(){
    if(top == -1)
        cout<<"Underflow\n";
    else
        cout<<"Not UnderFlow\n";
}
void Stack::reverseStack(){
    int t;
    for(int i=0;i<=top/2;i++){
        t = stack[i];
        stack[i] = stack[top-i];
        stack[top-i] = t;
    }
}
int Stack::minimumInStack(){
    int min = stack[0];
    for(int i=0;i<=top;i++)
        if(min>stack[i])
            min = stack[i];
    return min;
}
int main()
{
    Stack s1(10);
    s1.push(100);
    s1.push(110);
    s1.push(120);
    s1.push(130);
    s1.push(140);
    s1.peek();
    s1.reverseStack();
    s1.peek();
    s1.reverseStack();
    s1.peek();
    cout<<"Minimum: "<<s1.minimumInStack()<<endl;
    return 0;
}
