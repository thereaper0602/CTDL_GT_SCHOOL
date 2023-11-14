#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define MAX 20

struct node{
	int val;
	node* next;
};
typedef node* nd;

void init(nd first[],int n);
void insert(nd &first,int x);
void input(nd first[],int n);
void output(nd first);
void _mainProgram(nd f[],int n);

int main(){
	int n;
	nd f[MAX];
	cout << "Nhap so dinh cho n : ";cin >> n;
	init(f,n);
	_mainProgram(f,n);
	return 0;
}


void init(nd first[],int n){
	for(int i = 0;i<n;i++){
		first[i] = NULL;
	}
}

void insert(nd &first,int x){
	nd ins = new node;
	ins->val = x;
	ins->next = NULL;
	if(!first){
		first = ins;
	}
	else{
		nd p = first;
		while(p->next){
			p = p->next;
		}
		p->next = ins;
	}
}

void input(nd first[],int n){
	int d,x,m;
	for(int i = 0;i<n;i++){
		cout << "Nhap dinh thu " << i + 1 << " : ";
		cin >> d;
		insert(first,d);
		cout << "Nhap so dinh ke cua " << d << " : ";
		cin >> m;
		for(int j = 0;j<m;j++){
			cin >> x;
			insert(first[i],x);
		}
	}
}

void output(nd first){
	if(first){
		nd p = first;
		while(p){
			cout << p->val << " ";
			p = p->next;
		}
	}
	cout << "\n";
}

void _mainProgram(nd f[],int n){
	input(f,n);
	for(int i = 0;i<n;i++){
		output(f[i]);
	}
}

