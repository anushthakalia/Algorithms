#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int partition(int arr[],int p,int r){

    int pivot=arr[p];
    int left[r+1-p];
    int l=0;
    int ri=0;
    int right[r+1-p];
    for(int i=p+1;i<=r;i++){
        
        if(pivot>arr[i]){
            left[l]=arr[i];
            l++;
        }
        else if(pivot<arr[i]){
            right[ri]=arr[i];
            ri++;
        }
    }
    
    int k=0;
    int a[r+1-p];
    while(k<l){
        a[k]=left[k];
        k++;
    }
    a[k]=pivot;
    int final=k;
    k++;//here k=l+1
    k=0;
    while(k<ri){
        a[k+l+1]=right[k];
        k++;
    }
    
    k=0;
    for(int i=p;i<=r;i++){
        arr[i]=a[k];
        k++;
        // cout<<arr[i]<<" ";
    }

    

   
    return final+p;

}

void quicksort(int arr[],int p,int r){
    
    if(p<r){
        int q=partition(arr,p,r);
        // cout<<q<<"<-- inside quicksort"<<endl;
        
        quicksort(arr,p,q-1);
        if(p<q-1){
            for(int i=p;i<=q-1;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        quicksort(arr,q+1,r);
         if(q+1<r){
            for(int i=q+1;i<=r;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        
    }
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    // int p=0;
    // int r=n-1;
    // for(int i=0;i<3;i++){
    //  int part=partition(arr,p,r);
    //  cout<<part<<" "<<i+1;
    //  p=part+1;
    // }
    //  cout<<part;
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}