#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

struct List{
	int val;
	List* next = NULL;
};

typedef List* nd;

void init(nd &a){
	a = NULL;
}

nd newVal(int x){
	nd a = new List();
	a->val = x;
	a->next = NULL;
	return a;
}

void insert(nd &a,int x){
	nd insert = newVal(x);
	if(!a){
		a = insert;
	}
	else{
		nd p = a;
		while(p->next){
			p = p->next;
		}
		p->next = insert;
	}
}

void print(nd a){
	if(a){
		nd p = a;
		while(p){
			cout << p->val << " ";
			p = p -> next;
		}
		cout << endl;
	}
}

void addVec(std::vector<int> &v,nd a){
	if(a){
		nd p = a;
		while(p){
			v.push_back(p->val);
			p = p->next;
		}
	}
}

void heapify(vector<int> &v,int i,int n){
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest = i;
	if(l < n and v[l] > v[largest]){
		largest = l;
	}
	if(r < n and v[r] > v[largest]){
		largest = r;
	}
	if(largest != i){
		swap(v[largest],v[i]);
		heapify(v,largest,n);
	}
}

void heapsort(vector<int> &a){
	int n = a.size();
	for(int i = n/2-1;i>=0;i--){
		heapify(a,i,n);
	}
	for(int i = n-1;i>0;i--){
		swap(a[0],a[i]);
		heapify(a,0,i);
	}
}

void sortList(nd &a){
	vector<int> v;
	addVec(v,a);
	heapsort(v);
	while(a){
		nd q = a;
		a = a->next;
		delete q;
	}
	a = NULL;
	for(auto x : v){
		insert(a,x);
	}
}

void readFile(nd &a,string filename){
	ifstream fi(filename);
	if(fi.is_open()){
		while(!fi.eof()){
			int val;
			fi >> val;
			insert(a,val);
			fi.ignore();
		}
	}
	else cout << "Error" << endl;
}

int main(){
	nd a = new List();
	init(a);
	readFile(a,"info.txt");
	print(a);
	sortList(a);
	print(a);
	return 0;
}