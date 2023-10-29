#include<iostream>
#include<random>
#include<time.h>
using namespace std;

void heapify(int a[],int i,int n){
	int l = 2*i+1;
	int r = 2*i+2;
	int largest = i;
	if(l < n && a[l] > a[largest]){
		largest = l;
	}
	if(r < n && a[r] > a[largest]){
		largest = r;
	}
	if(largest != i){
		swap(a[largest],a[i]);
		heapify(a,largest,n);
	}
}

void heapsort(int a[],int n){
	for(int i = n/2-1;i>=0;i--){
		heapify(a,i,n);
	}
	for(int i = n-1;i>0;i--){
		swap(a[0],a[i]);
		heapify(a,0,i);
	}
}

void print(int a[],int n){
	for(int i = 0;i<n;i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

void create(int a[],int n){
	for(int i = 0;i<n;i++){
		a[i] = rand() % 100 + 10;
	}
}

int main(){
	srand(time(NULL));
	int n = 15;
	int a[n];
	create(a,n);
	print(a,n);
	heapsort(a,n);
	print(a,n);
	return 0;	
}