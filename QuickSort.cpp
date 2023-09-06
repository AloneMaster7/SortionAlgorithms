#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void QuickSort(int* arr,int start,int end){
    if(start >= end)
        return;
    int pivot=arr[start];
    int left=start+1,right=end;
    while(true){
        while(left<=right && arr[left]<pivot){
            left++;
        }
        while(left<=right && arr[right]>pivot){
            right--;
        }
        if(left<right)
            swap(arr[left],arr[right]);
        else
            break;
    }
    swap(arr[start],arr[right]);
    QuickSort(arr,start,right-1);
    QuickSort(arr,right+1,end);
}

int main(){
    srand(time(0));
    int size = 10+rand()%21; //size between 10 to 30
    cout<<"size : "<<size<<endl;
    int* arr = new int[size];
    cout<<"Unsorted : "<<endl;
    for(int i=0;i<size;i++){ //generate randomly array
        arr[i] = rand()%41; //number between 0 t0 40
        cout<<arr[i]<<' ';
    }cout<<endl;
    QuickSort(arr,0,size-1);
    cout<<"Sorted : "<<endl;
    for(int i=0;i<size;i++)
        cout<<arr[i]<<' ';
    cout<<endl;
    return 0;
}
