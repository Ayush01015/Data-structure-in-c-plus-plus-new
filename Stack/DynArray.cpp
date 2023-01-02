#include<bits/stdc++.h>
using namespace std;

class DynArray{
    private:
        int Capacity;
        int lastIndex;
        int *ptr;
    public:
        DynArray();
        DynArray(int);
        ~DynArray();
        void append(int);
        void view();
        void insert(int,int);
        void removeItem(int);
        void doubleArray();
        void halfArray();
        int getElement(int index){
            if(index<0 || index>this->lastIndex+1)
                cout<<"Invalid Index-\n";
            else{
                return this->ptr[index];
            }
        }
        int count(){
            return this->lastIndex+1;
        }
};

DynArray::DynArray(){}
DynArray::DynArray(int cap){
    Capacity=cap;
    lastIndex=-1;
    ptr = new int[Capacity];
}
DynArray::~DynArray(){
    delete []ptr;
    delete this;
}
void DynArray::doubleArray(){
    Capacity = Capacity * 2;
    int *temp = new int[Capacity];
    for(int i=0;i<=lastIndex;i++)
        temp[i]=ptr[i];
    delete ptr;
    ptr = temp;
}
void DynArray::halfArray(){
    Capacity = Capacity / 2;
    int *temp = new int[Capacity];
    for(int i=0;i<=lastIndex;i++)
        temp[i]=ptr[i];
    delete ptr;
    ptr = temp;
    
}
void DynArray::append(int data){
    if(lastIndex==Capacity-1){
        doubleArray();
        lastIndex++;
        ptr[lastIndex]=data;
    }
    else{
        lastIndex++;
        ptr[lastIndex]=data;
    }
}

void DynArray::view(){
    cout<<"Capacity: "<<Capacity<<endl;
    cout<<"lastIndex: "<<lastIndex<<endl;
    for(int i=0;i<=lastIndex;i++)
        cout<<ptr[i]<<" ";
    cout<<endl;
}

void DynArray::insert(int index,int data){
    if(lastIndex==Capacity-1){
        doubleArray();
        ptr[index]=data;
        lastIndex++;
    }
    else if(index<0||index>lastIndex+1){
        cout<<"Invalid Index\n";
    }else{
        for(int i=lastIndex;index<=i;i--)
            ptr[i+1]=ptr[i];
        ptr[index]=data;
        lastIndex++;
    }
}

void DynArray::removeItem(int index){
    if(lastIndex==-1)
        cout<<"Array is Empty\n";
    else if(Capacity/2==lastIndex+1){
        halfArray();
        cout<<"half\n";
    }
    else if(index<0||index>lastIndex+1){
        cout<<"Invalid Index\n";
    }else{
        for(int i=index;i<lastIndex;i++)
            ptr[i]=ptr[i+1];
        lastIndex--;    
    }
}


