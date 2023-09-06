#include <iostream>
using namespace std;

constexpr int maximum_size = 30;
enum heapType{MINHEAP=0,MAXHEAP};

class Heap{
    heapType type;
    int arr[maximum_size];
    int size;
public:
    Heap(heapType t,int root) : type(t){
        for(int i=0;i<maximum_size;i++)
            arr[i] = -1;
        arr[0] = root;
        this->size = 1;//because we pass root to constructor
    }
    int maximumSize(){
        return maximum_size;
    }
    void add(int item){
        if(this->size == maximum_size)
            return;
        if(this->type == MINHEAP){
            for(int i=0;i<=maximum_size;i++){
                if(item < arr[i]){
                    int temp;
                    temp = item;
                    item = arr[i];
                    arr[i] = temp;
                    continue;
                }
                if(arr[i]==-1){
                    arr[i] = item;
                    this->size++;
                    return;
                }
            }
        }
        if(this->type == MAXHEAP){
            for(int i=0;i<=maximum_size;i++){
                if(item > arr[i]){
                    int temp;
                    temp = item;
                    item = arr[i];
                    arr[i] = temp;
                    continue;
                }
                if(arr[i]==-1){
                    arr[i] = item;
                    this->size++;
                    return;
                }
            }
        }
    }

    int parent(int i){
        return (i-1)/2;
    }

    int del(){
        if(this->size == -1)
            return -1;
        int ret=-1;
        if(this->type == MAXHEAP){
            ret = this->arr[0];
            this->arr[0] = this->arr[this->size--];
            this->arr[this->size+1]=-1;
            this->GoDown(0);
            return ret;
        }
        if(this->type == MINHEAP){
            ret = this->arr[0];
            this->arr[0] = this->arr[--this->size];
            this->arr[this->size]=-1;
            this->GoDown(0);
            return ret;
        }
        return ret;
    }

    void swap(int& a,int& b){
        int temp = a;
        a = b;
        b = temp;
    }

    void GoDown(int k){
        int ch = 0;
        while(ch <= this->size){
            ch=2*k+1;//left child . right child is ch+1
            if(ch >= this->size)
                return;
            if((!(ch+1>=this->size)&&this->arr[ch]<this->arr[ch+1]&&this->type==MAXHEAP)
                    ||
               (!(ch+1>=this->size)&&this->arr[ch]>this->arr[ch+1]&&this->type==MINHEAP))
                ch++;
            if((this->type==MAXHEAP && this->arr[k] > this->arr[ch])||
               (this->type==MINHEAP && this->arr[k] < this->arr[ch]))
                return;
            this->swap(this->arr[k],this->arr[ch]);
            k = ch;
        }
    }
};

enum Method {Ascending,Descending};

void HeapSort(int* arr,int size,Method m=Ascending){
    if(!arr || size<0)
        return;
    Heap* h;
    if(m == Ascending)
        h = new Heap(MINHEAP,arr[0]);
    else
        h = new Heap(MAXHEAP,arr[0]);
    for(int i=1;i<size;i++)
        h->add(arr[i]);
    for(int i=0;i<size;i++)
        arr[i] = h->del();
}

int main(){
    int arr[10] = {7,5,23,1,4,6,3,0,5,9}; //for example
    HeapSort(arr,10);
    for(int i=0;i<10;i++)
        cout<<arr[i]<<' ';
    cout<<endl;
    return 1;
}
