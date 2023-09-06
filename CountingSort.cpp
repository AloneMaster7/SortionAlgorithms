#include <iostream>
using namespace std;

inline int max(int* a,int size){
	int m = a[0];
	for(int i=1;i<size;i++,m<a[i]?(m=a[i]):(m));
	return m;
}

void counting_sort(int* a,int size){
	const int m = max(a,size)+1;
	int* p = new int[m];
	for(int i=0;i<m;i++){
		p[i] = 0;
	}
	for(int i=0;i<size;i++){
		p[a[i]]++;
	}
	int i=0;
	int index=0;
	while(true){
		if(i >= m)
			break;
		if(!p[i]){
			i++;
			continue;
		}
		a[index++] = i;
		p[i]--;
	}
	delete[] p;
}

int main(){
	const int size=15;
	int arr[size]={1,2,6,4,2,5,7,13,21,4,6,2,5,7,3};
	counting_sort(arr,size);
	for(int i=0;i<size;i++)
		cout<<arr[i]<<' ';
	return 0;
}
