#include<iostream>

using namespace std;

int LEFT(int i){
	
	return 2*i+1;
}

int RIGHT(int i){
	
	return 2*i +2;
}

void min_heapify(int arr[],int i,int size){
	
	cout<<"Performing Max Heapify"<<endl;
	int l=LEFT(i);
	int r=RIGHT(i);
	int smallest=i;

	if(l<size && arr[l]<arr[smallest] ){
		smallest=l;
	}
	else{
		smallest=i;
	}
	if(r<size && arr[r]<arr[smallest]){
		smallest=r;
	}
	if(smallest!=i){
	   swap(arr[i],arr[smallest]);
	   min_heapify(arr,smallest,size);
	}

}

void swap(int i,int j){
	int temp=0;
	temp=i;
	i=j;
	j=temp;
}

void heapsort(int arr[],int size){
	cout<<"Performing Build min Heap"<<endl;
	for(int i=0;i<size/2;i++){
		min_heapify(arr,(size/2)-i-1,size);
	}
	
	cout<<"Performing Heapsort"<<endl;	
	for(int i=size-1;i>=0;i--){
		
	    cout<<"Swapping "<<i<<"...."<<endl;
		int temp=0;
		temp=arr[0];
		arr[0]=arr[i];
		arr[i]=temp;

		min_heapify(arr,0,i);
	}
	
}


int main(){
	
	int arr[6]={12, 11, 13, 5, 6, 7};// array to be sorted 
	int size = sizeof(arr)/sizeof(arr[0]);
	
	heapsort(arr,size);
	cout<<"The Heapify array is: "<<endl;
	for(int i=0;i<size;i++){
		cout<<arr[size-i-1]<<" ";
	}



	return 0;
}
