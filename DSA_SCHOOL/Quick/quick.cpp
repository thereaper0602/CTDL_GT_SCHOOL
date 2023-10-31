#include<iostream>
#include<vector>
#include<random>
#include<time.h>
using namespace std;


void create(vector<int> &v,int n){
	for(int i = 0;i < n;i++){
		int x = rand() % 100 + 10;
		v.push_back(x);
	}
}

void print(vector<int> v){
	for(auto x : v){
		cout << x << " ";
	}
	cout << endl;
}

void quickSort(vector<int> &v,int l,int r){
	int i = l;
	int j = r;
	int x = v[(l+r)/2];
	while(i < j){
		while(x > v[i]) i++;
		while(x < v[j]) j--;
		if(i<=j){
			swap(v[i],v[j]);
			i++;j--;
		}
	}
	if(i < r){
		quickSort(v,i,r);
	}
	if(j > l){
		quickSort(v,l,j);
	}
}
int main(){
	vector<int> v;
	create(v,20);
	print(v);
	quickSort(v,0,v.size() - 1);
	print(v);
	return 0;
}