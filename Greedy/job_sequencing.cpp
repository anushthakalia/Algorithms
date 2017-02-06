#include<iostream>
using namespace std;

struct job{
int id;
int dl;
int pr;	

};

void merge(struct job arr[],int p,int q,int r){
	int n1=q-p+1;
	int n2=r-q;
	
	struct job L[n1+1];
	struct job R[n2+1];
	
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
		if(L[L_i].pr>R[R_j].pr){
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

void merge_sort(struct job arr[],int p,int r){
	if(p<r){
		int q=(p+r)/2;
		merge_sort(arr,p,q);
		merge_sort(arr,q+1,r);
		merge(arr,p,q,r);
	}
}


int sequencing(struct job arr[],int size){
	int max=arr[0].dl;
	for(int i=0;i<size;i++){// O(n)  (can make it O(logn) using extract max of heap sort)
		if(arr[i].dl>max){
			max=arr[i].dl;
		}
	}
    int n=0; //array size 
	if(max<=size){
       n=max;
	}
	else{
		n=size;
	}
    int seq[n];
    for(int j=0;j<n;j++){
    	seq[j]=0;
    }
	merge_sort(arr,0,size-1);// O(nlogn)

  //   for(int i=0;i<size;i++){
  // 	cout<<arr[i].pr<<endl;
  // }
     int total_profit=0;
	for(int i=0;i<size;i++){
		int delay=arr[i].dl;
	    for(int j=0;j<delay;j++){
                if(seq[delay-j-1]==0){
                	seq[delay-j-1]=arr[i].id;
                	total_profit=total_profit+arr[i].pr;
                	// cout<<arr[i].id<<"<-- the id"<<endl;
                	// cout<<arr[i].pr<<"<-- the profit"<<endl;
                	break;
                }

	    }

	}
    cout<<"The sequence of jobs is:"<<endl;
	for(int i=0;i<n;i++){

		cout<<"J"<<seq[i]<<" ";
	}
    cout<<endl;

return total_profit;


}


int main(){

	int deadline[6]={5,3,3,2,4,2};
	int profit[6]={200,180,190,300,120,100};
    int size=sizeof(deadline)/sizeof(deadline[0]);
    job arr[size];
    for(int i=0;i<size;i++){
    arr[i].id=i+1;
    arr[i].dl=deadline[i];
    arr[i].pr=profit[i];
	}
    int p=0;
    p=sequencing(arr,size);
    cout<<"the total profit is "<<p;
 

	return 0;
}