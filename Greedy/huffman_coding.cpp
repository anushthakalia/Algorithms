#include<iostream>
using namespace std;

struct node{
char name;
int freq;
node*left=NULL;
node*right=NULL;
};

int LEFT(int i){
	
	return 2*i+1;
}

int RIGHT(int i){
	
	return 2*i +2;
}

int PARENT(int i){
	if(i%2==0){
     return (i/2)-1;
	}
	else{
	return (i/2);
	}
}

void min_heapify(struct node*arr[],int i,int size){
	
	cout<<"Performing min Heapify"<<endl;
	int l=LEFT(i);
	int r=RIGHT(i);
	int smallest=i;

	if(l<size && arr[l]->freq<arr[smallest]->freq ){
		smallest=l;
	}
	else{
		smallest=i;
	}
	if(r<size && arr[r]->freq<arr[smallest]->freq){
		smallest=r;
	}
	if(smallest!=i){
	   swap(arr[i],arr[smallest]);
	   min_heapify(arr,smallest,size);
	}

}



node* extract_min(struct node* arr[],int size){
     node* min;
    if(size<1){
    	cout<<"Heap underflow";
    }
    else{
    min=arr[0];
    arr[0]=arr[size-1];
    size=size-1;
    
    min_heapify(arr,0,size);
    }

    return min;
}

void min_insert(struct node* arr[],struct node* key,int size){

	size++;
	arr[size-1]=key;
	int i=size-1;
	while(i>0 && arr[PARENT(i)]->freq>arr[i]->freq){
		
		node* temp=NULL;
		temp=arr[i];
		arr[i]=arr[PARENT(i)];
		arr[PARENT(i)]=temp;
		i=PARENT(i);
	}
	cout<<"min-insert successful";
}

int huffman(struct node* arr[],int size){

// create a heap of structures

cout<<"Performing Build min Heap"<<endl;
for(int i=0;i<size/2;i++){
	min_heapify(arr,(size/2)-i-1,size);
}
cout<<"The heap after min Heapify is: "<<endl;
	for(int i=0;i<size;i++){
		cout<<arr[i]->freq<<" ";
	}
int counter=size;
for(int j=0;j<counter-1;j++){
 //creating a new node for insertion
	node* z=new node;
	z->left=extract_min(arr,size);
	
    size--;

    z->right=extract_min(arr,size);
    size--;
    z->freq=z->left->freq+z->right->freq;
// the new node is inserted
    min_insert(arr,z,size);
    size++;
   
}
//returning the last node
return arr[0]->freq;
}




int main(){

char namea[6]={'a','b','c','d','e','f'};
int freqa[6]={40,30,20,5,3,2};
int size=sizeof(freqa) / sizeof(freqa[0]);
 
 node* arr[size];
 for(int i=0;i<size;i++){
 	arr[i]=new node;
	arr[i]->name=namea[i];
	arr[i]->freq=freqa[i];	
	arr[i]->left=NULL;
	arr[i]->right=NULL;

	//cout<<arr[i]->name;
	}
	
int i=huffman(arr,size);
cout<<"the min extraxted is "<<i;
return 0;

}