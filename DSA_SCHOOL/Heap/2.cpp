#include<iostream>
#include<fstream>
#include<string>
#include<random>
#include<sstream>
#include<time.h>
using namespace std;
int MAX = 100;


void create(int a[],int n);
void print(int a[],int n);
void heapify(int a[],int i,int n);
void heapsort(int a[],int n);
int readFromFile(int a[],string filename);


int main(){
	int a[MAX];
	int n = readFromFile(a,"info.txt");
	print(a,n);
	heapsort(a,n);
	print(a,n);
	cout << n << endl;
	return 0;
}

void create(int a[],int n){
	for(int i = 0;i<n;i++){
		a[i] = rand() % 100 + 10;
	}
}

void print(int a[],int n){
	for(int i = 0;i<n;i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

void heapify(int a[],int i,int n){
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest = i;
	if(l < n and a[l] > a[largest]){
		largest = l;
	}
	if(r < n and a[r] > a[largest]){
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

int readFromFile(int a[],string filename){
	ifstream fi(filename);
	int i = 0;
	if(fi.is_open()){
		while(!fi.eof()){
			int val;
			fi >> val;
			a[i++] = val;
			fi.ignore();
		}
	}
	else cout << "Unreadable" << endl;
	return i;
}