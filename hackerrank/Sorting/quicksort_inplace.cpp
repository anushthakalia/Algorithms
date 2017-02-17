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

void quicksort(int arr[],int p,int r,int n){
	if(p<r){
		int q=partition(arr,p,r);
        for(int i=0;i<=n;i++){
		cout<<arr[i]<<" ";

	     }
	     cout<<endl;
		quicksort(arr,p,q-1,n);
		quicksort(arr,q+1,r,n);
		
	}
   	
}

int main(){
	int n=0;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	quicksort(arr,0,n-1,n-1);
	// for(int i=0;i<n;i++){
	// 	cout<<arr[i]<<endl;
	// }
	
	return 0;
}
