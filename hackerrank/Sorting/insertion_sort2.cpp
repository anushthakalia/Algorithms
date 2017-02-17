#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int count=0;
    
    for(int i=1;i<n;i++){
        int e=arr[i];
        for(int j=i-1;j>=0;j--){
            if(arr[j]>=e){
                arr[j+1]=arr[j];
            }
            else{
                arr[j+1]=e;
                break;
            }
            if(arr[j]>=e && j==0){
                arr[j]=e;
                
            }
        }
        for(int k=0;k<n;k++){
            cout<<arr[k]<<" ";
        }
        cout<<endl;
    }
   
    return 0;
}