#include<iostream>
#include<random>
#include<time.h>
using namespace std;
#define MAX 101

void create(int a[],int n);
void print(int a[],int n);
void quickSort(int a[],int l,int r);

int main(){
	srand(time(NULL));
	int a[MAX];
	create(a,30);
	print(a,30);
	quickSort(a,0,29);
	print(a,30);
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

void quickSort(int a[],int l,int r){
	int i = l;
	int j = r;
	int x = a[(l+r)/2];
	while(i < j){
		while(x > a[i]) i++;
		while(x < a[j]) j--;
		if(i <= j){
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	if(i < r) quickSort(a,i,r);
	if(j > l) quickSort(a,l,j);
}