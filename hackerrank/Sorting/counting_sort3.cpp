#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        string str="";

        cin>>arr[i]>>str;}
    
    int count[100];
    
    for(int i=0;i<100;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){
      count[arr[i]]=count[arr[i]]+1;}
    
    for(int i=0;i<100;i++){
        if(i==0){
         continue;
        }
        count[i]=count[i]+count[i-1];
        }
    
    for(int i=0;i<100;i++){
        cout<<count[i]<<" ";
    }
    return 0;
}