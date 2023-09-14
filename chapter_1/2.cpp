#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
struct node
{
	int data;
	node* next;
};
typedef node* nd;
void init(nd &a)
{
	a = NULL;
}
void display(nd a)
{
	nd p = a;
	while (p != NULL)
	{
		cout << p->data << "\t";
		p = p->next;
	}
	cout << endl;
}
nd search(nd a, int x)
{
	nd p = a;
	while (p != NULL)
	{
		if (p->data == x) { return p; }
		p = p->next;
	}
	return NULL;
}
void insert_first(nd& a, int x)
{
	nd insert = new node;
	insert->data = x;
	insert->next = NULL;
	if (a == NULL) { a = insert; }
	else
	{
		insert->next = a;
		a = insert;
	}
}
void insert_end(nd &a,int x)
{
	nd insert = new node;
	insert->data = x;
	insert->next = NULL;
	if (a == NULL) a = insert;
	else
	{
		nd p = a;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = insert;
	}
}
void del_first(nd& a)
{
	nd p = a;
	a = a->next;
	delete p;
}
void del_end(nd& a)
{
	nd p = a;
	nd q = NULL;
	while (p->next != NULL)
	{
		q = p;
		p = p->next;
	}
	if (p->next == NULL)
	{
		q->next = NULL;
	}
	else if(q==NULL)
	{
		a = NULL;
	}
	delete p;
}
void find_and_del(nd& a, int x)
{
	nd curr = new node;
	curr = NULL;
	nd find = a;
	while (find != NULL)
	{
		if (find->data == x)
		{
			find = find->next;
		}
		else
		{
			insert_end(curr, find->data);
			find = find->next;
		}
	}
	a = NULL;
	a = curr;
}
int main()
{
	nd a = new node;
	init(a);
	vector<int> v = { 5,8,7,3,6,9,2,1,5 };
	for (int i = 0; i < v.size(); i++)
	{
		insert_end(a, v[i]);
	}
	cout << "Danh sach phat da nhap : "; cout << endl; display(a);
	int first; cout << "Nhap phan tu vao dau danh sach : "; cin >> first;
	insert_first(a, first);
	display(a);
	int last; cout << "Nhap phan tu vao cuoi danh sach : "; cin >> last;
	insert_end(a, last);
	display(a);
	cout << "Danh sach sau khi xoa phan tu dau: ";
	del_first(a); cout << endl; display(a);
	cout << "Danh sach sau khi xoa phan tu cuoi : ";
	del_end(a);
	cout << endl;
	display(a);
	int pos; cout << "Nhap gia tri can xoa : "; cin >> pos;
	find_and_del(a, pos);
	cout << endl;
	display(a);
	return 0;
}