#include<bits/stdc++.h>
using namespace std;
class _Vector{
    private:
        int capacity;
        int lastIndex;
        int *ptr;
    public:
        void insert(int,int);
        bool isEmpty();
        _Vector(int);
        void append(int);
        void edit(int,int);
        void deleteElement(int);
        bool isFull();
        int elementAtindex(int);
        int count();
        int search(int);
        ~_Vector();
        void view();
        void doubleArray();
        void halfArray();

};
void _Vector::doubleArray(){
    capacity = capacity * 2;
    int *temp = new int[capacity];
    for(int i=0;i<=lastIndex;i++)
        temp[i] = ptr[i];
    delete []ptr;
    ptr = temp;    
}
void _Vector::halfArray(){
    capacity = capacity / 2;
    int *temp = new int[capacity];
    for(int i=0;i<=lastIndex;i++)
        temp[i] = ptr[i];
    delete []ptr;
    ptr = temp;    
}
bool _Vector::isEmpty(){
    if(lastIndex == -1)
        return true;
    return false;
}
void _Vector::view(){
    if(isEmpty())
        cout<<"_Vector is Empty";
    else{
        for(int i=0;i<=lastIndex;i++)
            cout<<ptr[i]<<" ";
    }
    cout<<endl;
}
_Vector::_Vector(int cap){
    capacity = cap;
    lastIndex = -1;
    ptr = new int[capacity];
}
void _Vector::append(int data){
    if(capacity == lastIndex+1){
        this->doubleArray();
        lastIndex++;
        ptr[lastIndex] = data;
    }
    else{
        lastIndex++;
        ptr[lastIndex] = data;
    }   
}
bool _Vector::isFull(){
    if(capacity == lastIndex+1)
        return true;
    return false;
}
void _Vector::insert(int index,int data){
    if(isFull()){
        doubleArray();
        ptr[index] = data;
        lastIndex++;
    }
    else if(index<0 || index>lastIndex+1)
        cout<<"Invalid Index\n";
    else{
        for(int i=lastIndex;index<=i;i--)
            ptr[i+1]=ptr[i];
        ptr[index] = data;
        lastIndex++;
    }
}
void _Vector::deleteElement(int index){
    if(isEmpty())
        cout<<"_Vector is Empty\n";
    else if(index<0 || index>lastIndex+1)
        cout<<"Invalid Index\n";
    else{
        for(int i=index;i<=lastIndex;i++)
            ptr[i]=ptr[i+1];
        lastIndex--;
    }
}
void _Vector::edit(int index,int data){
    if(isEmpty())
        cout<<"_Vector is Empty\n";
    else if(index<0 || index>lastIndex+1)
        cout<<"Invalid Index\n";
    else
        ptr[index] = data;
}
int _Vector::elementAtindex(int index){
    if(isEmpty())
        cout<<"_Vector is Empty\n";
    else if(index<0 || index>lastIndex+1)
        cout<<"Invalid Index\n";
    else
        return ptr[index];
}
int _Vector::count(){
    return lastIndex+1;
}
int _Vector::search(int data){
    for(int i=0;i<=lastIndex;i++)
        if(ptr[i]==data)
            return i;
        return -1;

}
_Vector::~_Vector(){
    delete []ptr;
}
