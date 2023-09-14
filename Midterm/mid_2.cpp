#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
#include<limits>
#include<cstring>
using namespace std;
struct chinhanh{
	int ma;
	string diachi;
	int soNhanVien;
	chinhanh* left;
	chinhanh* right;
};
typedef chinhanh* cn;

void init(cn &a){
	a = NULL;
}

cn create(){
	int ma;
	string diachi;
	int soNhanVien;
	cout << "Nhap ma chi nhanh : ";cin >> ma;cin.ignore();
	cout << "Nhap dia chi : ";getline(cin,diachi);
	cout << "Nhap so nhan vien : ";cin >> soNhanVien;

	cn insert = new chinhanh;
	insert->ma = ma;
	insert->diachi = diachi;
	insert->soNhanVien = soNhanVien;
	insert->left = NULL;
	insert->right = NULL;
	return insert;
}

void input(cn &a,int ma,string diachi,int so){
    cn insert = new chinhanh;
    insert->ma = ma;
    insert->diachi = diachi;
    insert->soNhanVien = so;
	if(a==NULL) a = insert;
	else{
		if(a->ma == ma) return;
		else if(a->soNhanVien > insert->soNhanVien){
			input(a->left,ma,diachi,so);
		}
		else {
			input(a->right,ma,diachi,so);
		}
	}
}

void searchStandFor(cn &p,cn &q){
	if(q->left==NULL){
		p->ma = q->ma;
		p->diachi = q->diachi;
		p->soNhanVien = q->soNhanVien;
		p = q;
		q = q->right;
	}
	else searchStandFor(p,q->left);
}

int deleteEle(cn &a,int ma){
	if(a==NULL) return 0;
	if(a->ma == ma){
		cn p = a;
		if(a->left == NULL) a = a->right;
		else if(a->right == NULL) a = a->left;
		else searchStandFor(p,a->right);
		delete p;
		return 1;
	}
	if(a->ma < ma) return deleteEle(a->right,ma);
	if(a->ma > ma) return deleteEle(a->left,ma);
	return 0;
}

struct list{
	int ma;
	string diachi;
	int soNhanVien;
	list* next;
};typedef list* li;

void inlist(li &a){
	a = NULL;
}

void inputToList(li &a,int ma,string diachi,int so){
    li insert = new list;
    insert->ma = ma;
    insert->diachi = diachi;
    insert->soNhanVien = so;
    insert->next = NULL;
	if(a==NULL) a = insert;
	else{
		li p = a;
		while(p->next!=NULL){
			p = p->next;
		}
		p->next = insert;
	}
}

void inputList(li &a,string filename){
	ifstream fi(filename);
	if(fi.is_open()){
		int n;
		fi >> n;
		int i = 0;
		//fi.ignore();
		fi.ignore(numeric_limits<streamsize>::max(),'\n');
		//fi.ignore();
		for(int i = 0;i<n;i++){
            string line;
            getline(fi,line);
            istringstream iss(line);
            int ma;
	        string diachi;
           	int soNhanVien;

            char comma;
            iss >> ma >> comma;
            getline(iss,diachi,',');
            iss >> soNhanVien;
            inputToList(a,ma,diachi,soNhanVien);
        }
		fi.close();
	}
	else cout << "Khong the doc file" << endl; 
}

// void copyList(li &head,li &newLi){
// 	li p = head;
// 	while(p!=NULL){
// 		inputToList(newLi,p);
// 		p = p->next;
// 	}
// }

cn createCn(li p){
	cn insert = new chinhanh;
	insert->ma = p->ma;
	insert->diachi = p->diachi;
	insert->soNhanVien = p->soNhanVien;
	insert->left = NULL;
	insert->right = NULL;
	return insert;
}

void convertLiToTr(li p,cn &a){
	input(a,p->ma,p->diachi,p->soNhanVien);
}

struct stack{
	cn val;
	stack *next;
};typedef stack* st;

void inStack(st &a){ a = NULL;}

void pushStack(st &a,cn x){
	st insert = new stack;
	insert->val = x;
	insert->next = NULL;
	if(a==NULL) a = insert;
	else{
		st p = a;
		while(p->next!=NULL){
			p = p->next;
		}
		p->next = insert;
	}
}

void popStack(st &a){
	st p = a;
	a = a->next;
	delete p;
}

cn topStack(st a){
	return a->val;
}

bool emptyStack(st a){
	if(a==NULL) return true;
	else return false;
}


void RLN(cn a){
	st stk = new stack;
	inStack(stk);
	cn curr = a;
	cn last = NULL;
	while(!emptyStack(stk)||curr){
		if(curr){
			pushStack(stk,curr);
			curr = curr->right;
		}
		else{
			cn top = topStack(stk);
			if(top->left && top->left!=last){
				curr = top->left;
			}
			else{
				last = top;
				cout << top->ma << " " << top->diachi << " " << top->soNhanVien << endl;
				popStack(stk);
			}
		}
	}
}

struct queue{
	cn val;
	queue *next;
};typedef queue* qu;

void inQueue(qu &a){ a = NULL;}

void pushQueue(qu &a,cn x){
	qu insert = new queue;
	insert->val = x;
	insert->next = NULL;
	if(a==NULL) a = insert;
	else{
		qu p = a;
		while(p->next!=NULL){
			p = p->next;
		}
		p->next = insert;
	}
}

void popQueue(qu &a){
	qu p = a;
	a = a->next;
	delete p;
}

cn front(qu a){
	return a->val;
}

bool emptyQueue(qu a){
	if(a==NULL) return true;
	else return false;
}

int countExpress(cn a){
	if(a==NULL) return 0;
	int count = 0;
	if(a->soNhanVien >= 200 && a->soNhanVien <=500){
		count = 1;
	}
	count+=countExpress(a->left);
	count+=countExpress(a->right);
	return count;
}


void menu(){
	cout << "\n";
	cout << "1 . Them phan tu vao cay chi nhanh " << endl;
	cout << "2 . Doc thong tin tu file cho vao dslk va them vao cay" << endl;
	cout << "3 . Xuat RLN" << endl;
	cout << "4 . Ghi thong tin dslk ra file " << endl;
	cout << "5 . Dem so luong chi nhanh co so nhan vien tu 200 den 500 " << endl;
	cout << "6 . Dem muc cao nhat cua cay sao cho co du 2 con" << endl;
	cout << "\n";
}

int main(){
	vector<li> v;
	cn root = new chinhanh;
	root = NULL;
	li head = new list;
	inlist(head);
	inputList(head,"input_2.txt");
    li p = head;
    // while(p!=NULL){
    //     cout << p->ma << " " << p->diachi << " " << p->soNhanVien << endl;
    //     p = p->next;
    // }
	while(p!=NULL){
        convertLiToTr(p,root);
        p = p->next;
    
    }
    cout
	return 0;
}