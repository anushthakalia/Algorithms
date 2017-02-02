#include<iostream>
using namespace std;

void insertion_sort(int arr[],int size){
	
	int key=0;
	int i=0;
	for(int j=1;j<size;j++){
		key=arr[j];
		i=j-1;
		while(i>-1 && arr[i]>key){
			arr[i+1]=arr[i];
			i--;
		}
	    arr[i+1]=key;
		
	}
	
}



int main(){
int arr[5]={9,5,6,7,4};
int size = sizeof(arr)/sizeof(arr[0]);
insertion_sort(arr,size);

cout<<"The sorted array is:"<<endl;

	for(int i=0;i<size;i++){
	cout<<arr[i]<<endl;}


	
	return 0;
	
}
