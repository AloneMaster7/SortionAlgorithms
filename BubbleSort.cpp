#include <iostream>
using namespace std;

void BubbleSort(int* array,int siz){
    char swapped;
    do{
        swapped = 'n';

        for(int i=0;i<siz-1;i++){
            if(array[i] > array[i+1]){
                std::swap(array[i],array[i+1]);
                        swapped = 'y';
            }
        }

    }while(swapped == 'y');

    for(int i=0;i<siz;i++){
        cout<<array[i]<<endl;
    }
}

int main(){
    int array[]={15,1,15,16,8,43,75,13,63,34,56,32};
    int siz = sizeof(array) / sizeof(array[0]);
    BubbleSort(array,siz);
    for(int i=0;i<siz;i++)
        cout<<array[i]<<' ';
    cout<<endl;
    return 0;
}
