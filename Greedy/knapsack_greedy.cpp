#include<iostream>
using namespace std;

struct object{
	int profit;
	int weight;
	float ratio;
};

//this is called array of structures
void merge(struct object arr[],int p,int q,int r){
	int n1=q-p+1;
	int n2=r-q;
	
	struct object L[n1+1];
	struct object R[n2+1];
	
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
		if(L[L_i].ratio>R[R_j].ratio){
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

void merge_sort(struct object arr[],int p,int r){
	if(p<r){
		int q=(p+r)/2;
		merge_sort(arr,p,q);
		merge_sort(arr,q+1,r);
		merge(arr,p,q,r);
	}
}

double knapsack(struct object arr[],int size,int w){
	double p=0;

	merge_sort(arr,0,size-1);
	int i=0;
	while(i<size){
		if(w>0 && arr[i].weight<=w){
		w=w-arr[i].weight;
		p=p+ (double)arr[i].profit;
		cout<<p<<"profit"<<endl;
		}
		else{
		break;}
		i++;
	}
	if(w>0){
	p=p+(double)arr[i].ratio*w;
	}	

	return p;

}

int main(){
	int w=20;
  object arr[]={{25,18,1.4}, {24,15,1.6}, {15,10,1.5}};
  int size = sizeof(arr) / sizeof(arr[0]);
  double p=0;
  p=knapsack(arr,size,w);

  for(int i=0;i<size;i++){
  	cout<<arr[i].profit<<endl;
  	cout<<arr[i].weight<<endl;
  	cout<<arr[i].ratio<<endl;
  }
  cout<<"The maximum profit that can be incurred is:"<<endl;
  cout<<p<<endl;
	return 0;
}