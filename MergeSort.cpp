#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int* joinSorted(int* a,int sa,int* b,int sb){
    int arr[sa+sb];
    int index_a=0,index_b=0,i=0;
    while(1){
        if(index_a==sa && index_b==sb)
            break;
        if(index_a==sa){
            arr[i++]=b[index_b++];
        }
        else if(index_b==sb){
            arr[i++]=a[index_a++];
        }
        else{
            if(a[index_a]>b[index_b]){
                arr[i++]=b[index_b++];
            }
            else
                arr[i++]=a[index_a++];
        }
    }
    for(int i=0;i<sa+sb;i++)
        a[i]=arr[i];
    return a;
}

int* MergeSort(int* arr,int size){
    if(size <= 1)
        return arr;
    int lsize = size/2;
    int* LeftPart = MergeSort(arr,lsize);
    int* RightSize = MergeSort(arr+lsize,size-lsize);
    return joinSorted(LeftPart,lsize,RightSize,size-lsize);
}

int main(){
    srand(time(0));
    int n = 10+rand()%31; //size between 10 to 30
    int* arr = new int[n];
    cout<<"array before merge sort : "<<endl;
    for(int i=0;i<n;i++){
        arr[i] = rand()%41;//a number between 0 to 40
        cout<<arr[i]<<' ';
    }cout<<endl;
    MergeSort(arr,n);
    cout<<"array after merge sort : "<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<' ';
    cout<<endl;
    return 0;
}
