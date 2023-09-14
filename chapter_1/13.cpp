#include<iostream>
#include<vector>
using namespace std;
struct node
{
	int data;
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
	if (p != NULL)
	{
		do
		{
			cout << p->data << " ";
			p = p->next;
		} while (p != a);
	}
	cout << endl;
}
void insert_beg(nd& a, int x)
{
	nd insert = new node;
	insert->data = x;
	insert->next = a;
	nd p = a;
	if (p != NULL)
	{
		while (p->next != a)
		{
			p = p->next;
		}
		p->next = insert;
	}
	else
	{
		insert->next = insert;
	}
	a = insert;
}
void delete_beg(nd& a)
{
	nd p = a;
	nd q = a;
	while (q->next != a)
	{
		q = q->next;
	}
	if (p != q)
	{
		a = a->next;
		q->next = a;
	}
	else
	{
		a = NULL;
	}
	delete p;
}
void insert_last(nd& a, int x)
{
	nd insert = new node;
	insert->data = x;
	insert->next = NULL;
    if(a==NULL)
    {
        a = insert;
        a->next = a;
    }
    else{
	nd p = a;
	if (p != NULL)
	{
		while (p->next != a)
		{
			p = p->next;
		}
		p->next = insert;
		insert->next = a;
	}
    }
}
void delete_last(nd& a)
{
	nd p = a;
	nd q = a;
	if (a != NULL)
	{
		while (p->next != a)
		{
			q = p;
			p = p->next;
		}
		q->next = a;
	}
	else
	{
		a = NULL;
	}
	delete p;
}
bool search(nd a,int x)
{
	nd p = a;
    do
    {
        if(p->data==x) return true;
        p = p->next;
    } while (p!=a);
    return false;
}

void delete_val(nd &a,int x)
{
    if(a==NULL) return;
    nd p = a;
    nd q = NULL;
    do{
        if(p->data==x)
        {
            if(p==a)
            {
                nd lastNode = a;
                while(lastNode->next!=a)
                {
                    lastNode = lastNode->next;
                }
                if(lastNode==a)
                {
                    delete a;
                }
                else
                {
                    lastNode->next = a->next;
                    a = a->next;
                }
            }
            else{
                q->next = p->next;
                delete p;
            }
        }
        q = p;
        p = p->next;
    }
    while(p!=a);
}
int main()
{
    system("cls");
	nd a = new node;
	init(a);
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    for(auto x : v)
    {
        insert_last(a,x);
    }
    process(a);
    delete_beg(a);
    process(a);
    delete_last(a);
    process(a);
    int x;cout << "X : ";cin >> x;
    if(search(a,x)==true)
    {
        delete_val(a,x);
    } 
    else cout << "Error " << endl;
    process(a);
	return 0;
}