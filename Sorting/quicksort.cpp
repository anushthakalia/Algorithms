#include<iostream>
using namespace std;

int partition(int arr[],int p,int r){
	int x=arr[r];
	int i=p-1;
	for(int j=p;j<r;j++){
		if(arr[j]<=x){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[r]);
	return i+1;
}

void swap(int i,int j){
	int temp=i;
	i=j;
	j=temp;
}

void quicksort(int arr[],int p,int r){
	if(p<r){
		int q=partition(arr,p,r);
		quicksort(arr,p,q-1);
		quicksort(arr,q+1,r);
	}
   	
}

int main(){
	int arr[6]={3,1,3,2,8,9};
	quicksort(arr,0,5);
	
	for(int i=0;i<6;i++){
		cout<<arr[i]<<endl;
	}
	
	return 0;
}
