#include<iostream>
#include<vector>
#include<random>
#include<time.h>
using namespace std;

struct Node{
	int val;
	Node* next;
};

typedef Node* nd;

void init(nd &root){
	root = NULL;
}

void insert(nd &a,int x){
	nd newNode = new Node;
	newNode->val = x;
	newNode->next = NULL;
	if(!a) a = newNode;
	else{
		nd p = a;
		while(p->next){
			p = p->next;
		}
		p->next = newNode;
	}
}

void printList(nd a){
	if(!a) return;
	nd p = a;
	while(p){
		cout << p->val << " ";
		p = p->next;
	}
	cout << "\n";
}

void addVec(vector<int> &v,nd a){
	nd p = a;
	while(p){
		v.push_back(p->val);
		p = p->next;
	}
}

void quickSort(vector<int> &a,int l,int r){
	int i = l;
	int j = r;
	int x = a[(l+r) / 2];
	while(i < j){
		while(x > a[i]) i++;
		while(x < a[j]) j--;
		if(i<=j){
			swap(a[i],a[j]);
			i++;j--;
		}
	}
	if(i < r) quickSort(a,i,r);
	if(l < j) quickSort(a,l,j);
}

void sort(nd &a){
	vector<int> v;
	addVec(v,a);
	quickSort(v,0,v.size() - 1);
	while(a){
		nd q = a;
		a = a->next;
		delete q;
	}
	for(auto x : v){
		insert(a,x);
	}
}

int main(){
	srand(time(NULL));
	nd root = new Node();
	init(root);
	int n = 15;
	for(int i = 0;i < n;i++){
		int x = rand() % 100 + 10;
		insert(root,x);
	}
	printList(root);
	sort(root);
	printList(root);
	return 0;
}