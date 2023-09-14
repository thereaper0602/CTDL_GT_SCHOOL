#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;
#define M 100

struct node {
	int val;
	node* next;
};
typedef node* nd;
void init(nd& a)
{
	a = NULL;
}
void process(nd a)
{
	nd p = a;
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}
void insert_lst(nd& a, int x)
{
	nd insert = new node;
	insert->val = x;
	insert->next = NULL;
	if (a == NULL)
	{
		a = insert;
	}
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
bool search(nd a, int x)
{
	nd p = a;
	while (p != NULL && p->val != x)
	{
		p = p->next;
	}
	if (p != NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void delete_between(nd& a,nd x)
{
	if(a==NULL) return;
	else
	{
	nd p = a;
	nd q = NULL;
	while (p != NULL && p != x)
	{
		q = p;
		p = p->next;
	}
	if (q == NULL)
	{
		a = NULL;
	}
	else if (p == NULL)
	{
		q->next = NULL;
	}
	else
	{
		q->next = p->next;
	}
	delete p;
}
}
void delete_beg(nd& a)
{
	if (a != NULL)
	{
		nd p = a;
		a = a->next;
		delete p;
	}
	else return;
}

void search_and_del(nd& a, int x)
{
	nd p = a;
	while(p->next!=NULL)
	{
		if(p->val==x)
		{
			delete_beg(a);
			p = a;
		}
		else
	{
		nd after = p->next;
		nd forward = p;
		while(after!=NULL)
		{
			if(after->val==x)
			{
				nd temp = after;
				after = forward;
				delete_between(p,temp);
			}
			else
			{
				forward = after;
				after = after->next;
			}
		}
	}
		p = p->next;
	}
}



int main()
{
	nd a = new node;
	init(a);
	vector<int> v = {1,2,3,1,4,5,1};
	for(int i = 0;i<v.size();i++)
	{
		insert_lst(a,v[i]);
	}
	process(a);
	int x;cout << "x : ";cin >> x;
	search_and_del(a,x);
	process(a);
	return 0;
}