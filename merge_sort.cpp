#include<iostream>
using namespace std;

void merge(int arr[],int p,int q,int r){
	int n1=q-p+1;
	int n2=r-q;
	
	int L[n1+1];
	int R[n2+1];
	
	for(int i=0;i<n1;i++){
		L[i]=arr[p+i];
	}
	for(int j=0;j<n2;j++){
		R[j]=arr[q+j+1];
	}
	
	int L_i=0;
	int R_j=0;
	int k=p;
	while (L_i<n1 && R_j<n2){
		if(L[L_i]<R[R_j]){
			arr[k]=L[L_i];
			L_i++;
			k++;
		}
		else{
			arr[k]=R[R_j];
			R_j++;
			k++;
		}
	}
	
	while(L_i<n1){
		arr[k]=L[L_i];
		L_i++;
		k++;
	}
	
		while(R_j<n2){
		arr[k]=R[R_j];
		R_j++;
		k++;
	}
}

void merge_sort(int arr[],int p,int r){
	if(p<r){
		int q=(p+r)/2;
		merge_sort(arr,p,q);
		merge_sort(arr,q+1,r);
		merge(arr,p,q,r);
	}
}

int main(){
	int arr[6]={7,4,3,2,3,2};
	merge_sort(arr,0,5);
	
	for(int i=0;i<6;i++){
		cout<<arr[i]<<endl;
	}
	
	return 0;
}
