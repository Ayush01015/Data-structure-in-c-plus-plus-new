#include "DynArray.cpp"
#include<bits/stdc++.h>
using namespace std;

class Stack:private DynArray{
    public:
        Stack():DynArray(){}
        Stack(int cap):DynArray(cap){}
        void peek();
        void push(int);
        void pop();
        int top();
};

void Stack :: push(int data){
    append(data);
}
void Stack :: peek(){
    cout<<getElement(count()-1)<<endl;
}
int Stack :: top(){
    return count()-1;
}
void Stack :: pop(){
    removeItem(top());
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

    return 0;
}