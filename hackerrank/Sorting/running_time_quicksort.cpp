#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int partition(int arr[],int p,int r,int &count){

	int x=arr[r];
	int i=p-1;
	for(int j=p;j<r;j++){
		if(arr[j]<=x){
			i++;
			swap(arr[i],arr[j]);
			count++;
		}
	}
	swap(arr[i+1],arr[r]);
	count++;
	return i+1;
}

void swap(int i,int j){
	int temp=i;
	i=j;
	j=temp;
}

int  quicksort(int arr[],int p,int r,int n,int &count){
	if(p<r){
		int q=partition(arr,p,r,count);
        
		count=quicksort(arr,p,q-1,n,count);
		count=quicksort(arr,q+1,r,n,count);
		
	}
   	return count;
}

int main(){
	int n=0;
	cin>>n;
	int arr[n];
    int arr1[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
    for(int i=0;i<n;i++){
		arr1[i]=arr[i];
	}
    //QUICKSORT//
    //----------------------------------------------
	int count=0;
	count=quicksort(arr,0,n-1,n-1,count);
	
    
    // INSERTION SORT//
    //-----------------------------------------------
    int count1=0;
    
    for(int i=1;i<n;i++){
        int e=arr1[i];
        for(int j=i-1;j>=0;j--){
            if(arr1[j]>=e){
                arr1[j+1]=arr1[j];
                count1++;
            }
            else{
                arr1[j+1]=e;
                
                break;
            }
            if(arr1[j]>=e && j==0){
                arr1[j]=e;
                
                
            }
        }
    }
    cout<<count1-count<<endl;
	return 0;
}