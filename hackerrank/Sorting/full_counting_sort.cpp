#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n=0;
    cin>>n;
    int arr[n];
    string str[n];
    int max=0;
    for(int i=0;i<n;i++){
        cin>>arr[i]>>str[i];
        if(i==0){
            max=arr[i];
        }
        if(arr[i]>max){
            max=arr[i];
        }
    }
    
    int count[max+1];
    
    for(int i=0;i<max+1;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){
      count[arr[i]]=count[arr[i]]+1;}
    int max1=0;
    for(int i=0;i<max+1;i++){
        if(i==0){
            max1=count[i];
         continue;
        }
        count[i]=count[i]+count[i-1];
        if(max1<count[i]){
            max1=count[i];
        }
        }
       string stri[max1];
       int index[max1];
       for(int i=0;i<max1;i++){
         stri[i]="";
         index[i]=0;

         // cout<<str[i]<<" ";
       }
       for(int i=0;i<n;i++){

         stri[count[arr[n-i-1]]-1]=str[n-i-1];
         index[count[arr[n-i-1]]-1]=n-i-1;
         
         count[arr[n-i-1]]--;
        
       }
    for(int i=0;i<max1;i++){
        if(index[i]<n/2){
            cout<<"- ";
        }
        else{
        cout<<stri[i]<<" ";
    }
    }
    return 0;
}