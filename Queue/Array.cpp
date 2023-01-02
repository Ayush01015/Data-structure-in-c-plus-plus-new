#include<bits/stdc++.h>
using namespace std;

class _Vector{
    private:
        int capacity;
        int lastIndex;
        int *ptr;
    public:

        _Vector(){}

        _Vector(int size){
            this->capacity = size;
            this->lastIndex = -1;
            this->ptr = new int[size];
        }

        ~_Vector(){
            delete this->ptr;
            delete this;
        }

        _Vector* createArray(int size){
            this->capacity = size;
            this->lastIndex = -1;
            this->ptr = new int[size];
        }

        void printArray(){
            cout<<"LastIndex: "<<this->lastIndex<<endl;
            for(int i=0;i<=this->lastIndex;i++)
                 cout<<this->ptr[i]<<" ";
            cout<<endl;
        }

        void append(int data){
            if(this->capacity-1 == this->lastIndex)
                cout<<"OverFlow\n";
            else{
                this->lastIndex+=1;
                this->ptr[this->lastIndex]=data;
            }
        }

        void insert(int index,int item){
            if(this->capacity-1 == this->lastIndex)
                cout<<"Array is Full\n";
            else if(index<0 || index>this->lastIndex+1){
                cout<<"Invalid Index-\n";
            }else{
                for(int i=this->lastIndex;index<=i;i--)
                    this->ptr[i+1]=this->ptr[i];
                this->ptr[index]=item;
                this->lastIndex+=1;
            }
        }

        void removeIndex(int index){
            if(this->lastIndex==-1)
                cout<<"Array is Empty\n";
            else if(index<0 || index>this->lastIndex+1){
                cout<<"Invalid Index-\n";
            }else{
                for(int i=index;i<this->lastIndex;i++)
                    this->ptr[i]=this->ptr[i+1];
                this->lastIndex-=1;    
            }
        }

        int getElement(int index){
            if(index<0 || index>this->lastIndex+1)
                cout<<"Invalid Index-\n";
            else{
                return this->ptr[index];
            }
        }

        bool ArrayIsFull(){
            if(this->capacity-1==this->lastIndex)
                return true;
            else
                return false;
        }

        bool ArrayIsEmpty(){
            if(this->lastIndex==-1)
                return true;
            else
                return false;
        }
        
        int count(){
            return this->lastIndex+1;
        }

        int search(int item){
            for(int i=0;i<=this->lastIndex;i++)
                if(this->ptr[i]==item)
                    return i;
                return -1;
        }
};


int main()
{
    _Vector v(10);
    v.insert(0,10);
    v.insert(1,20);
    v.insert(2,30);
    v.insert(3,40);
    v.insert(4,50);
    v.insert(5,60);
    v.insert(6,70);
    v.printArray();

    return 0;
}
