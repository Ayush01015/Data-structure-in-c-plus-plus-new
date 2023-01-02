#include "Array2.cpp"
#include<bits/stdc++.h>
using namespace std;
class Stack:private _Vector{
    public:
        Stack(int cap):_Vector(cap){
        }
        void push(int data){
            if(!isFull())
                append(data);
            // cout<<endl<<count()-1;
        }
        void peek(){
            if(isEmpty())
                cout<<"Stack is Empty\n";
            else
                cout<<elementAtindex(count()-1)<<endl;
        }
        void pop(){
            deleteElement((count()-1));
        }
        ~Stack(){}
        bool stackOverflow(){
            return isFull();
        }
        bool stackUnderflow(){
            return isEmpty();
        }
        // Stack reverseStack(){
        //     Stack t(count());
        //     while(count()-1!=-1){
        //         t.push(count()-1);
        //         pop();
        //     }
        //     delete []this;
        //     return t;
        // }

};
int main()
{
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.peek();
    Stack v = s.reverseStack();
    v.peek();

    return 0;
}