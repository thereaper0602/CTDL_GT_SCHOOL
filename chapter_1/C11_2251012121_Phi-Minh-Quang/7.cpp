#include <iostream>
#include <conio.h>
using namespace std;

struct Node
{
	int info;
	Node* link;
};

void init();
void process_list();
void insert_first(int x);
void insert_last(int x);
int delete_first();
int delete_last();

Node* first;

int main()
{
	int chon, x, in = 0;
	do
	{
		system("cls");
		cout << "Menu\n"
			<< "1.Khoi tao danh sach\n"
			<< "2.Chen dau\n"
			<< "3.Chen cuoi\n"
			<< "4.Xoa dau\n"
			<< "5.Xoa cuoi\n"
			<< "6.Xuat \n"
			<< "7.Thoat\n";
		cin >> chon;
		switch (chon)
		{
		case 1:
		{
			init();
			in = 1;
			cout << "Successful\n";
			break;
		}
		case 2:
		{
			if (in)
			{
				int x;
				cout << "Nhap ki tu can chen \n";
				cin >> x;
				insert_first(x);
				cout << "Successful\n";
				break;
			}
			else
				cout << "Vui long khoi tao danh sach truoc\n";
			break;
		}
		case 3:
		{
			if (in)
			{
				int x;
				cout << "Nhap ki tu can chen \n";
				cin >> x;
				insert_last(x);
				cout << "Successful\n";
				break;
			}
			else
				cout << "Vui long khoi tao danh sach truoc\n";
			break;
		}
		case 4:
		{
			if (in)
			{
				if (delete_first())
				{
					cout << "Sucessful\n";
				}
				else cout << "Failed\n";
				break;
			}
			else
				cout << "Vui long khoi tao danh sach truoc\n";
			break;
		}
		case 5:
		{
			if (in)
			{
				if (delete_last())
				{
					cout << "Sucessful\n";
				}
				else cout << "Failed\n";
				break;
			}
			else
				cout << "Vui long khoi tao danh sach truoc\n";
			break;
		}
		case 6:
		{
			if (in)
			{
				process_list();
			}
			else
				cout << "Vui long khoi tao danh sach truoc\n";
			break;
		}
		default:
		{
			cout << "Ban chon thoat \n";
			break;
		}
		}
		_getch();
	} while (chon >= 1 && chon <= 6);
	system("pause");
	return 0;
}

void init()
{
	first = NULL;
}

void process_list()
{
	Node* p = first;
	if (p != NULL)
	{
		do
		{
			cout << p->info << " ";
			p = p->link;
		} while (p != first);
	}
	cout << endl;
}

void insert_first(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = first;
	Node* q = first;
	if (q != NULL)
	{
		while (q->link != first)
		{
			q = q->link;
		}
		q->link = p;
	}
	else
		p->link = p;
	first = p;
}

int delete_first()
{
	if (first == NULL)
		return 0;
	Node* p = first;
	Node* q = first;
	while (q->link != first)
	{
		q = q->link;
	}
	if (p != q)
	{
		first = first->link;
		q->link = first;
	}
	else
		first = NULL;
	delete p;
	return 1;
}

void insert_last(int x)
{
	Node* p = new Node;
	p->info = x;
	Node* k = first;
	if (k != NULL)
	{
		while (k->link != first)
		{
			k = k->link;
		}
		k->link = p;
		p->link = first;
	}
	else
	{
		p->link = p;
		first = p;
	}
}

int delete_last()
{
	if (first == NULL)
		return 0;
	Node* p = first;
	Node* q = new Node;
	while (p->link != first)
	{
		q = p;
		p = p->link;
	}
	if (p != first)
	{
		q->link = first;
	}
	else
		first = NULL;
	delete p;
	return 1;
	return 0;
}