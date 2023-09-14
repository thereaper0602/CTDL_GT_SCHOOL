#include <iostream>
#include <conio.h>
using namespace std;

#define Max 100
int a[Max];
int sp;

void init(int a[], int& sp);
int Rong(int sp);
int full(int sp);
int add(int a[], int& sp, int x);
int pop(int a[], int& sp, int& x);

int main()
{
	int choose, x;
	init(a, sp);
	do
	{
		system("cls");
		cout << "----------Menu----------\n"
			<< "1.Check stack rong\n"
			<< "2.Check stack day\n"
			<< "3.Them phan tu vao stack\n"
			<< "4.Lay phan tu ra khoi stack\n"
			<< "5.Chuyen he 10 sang he 2\n"
			<< "6.Thoat\n";
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			if (Rong(sp))
			{
				cout << "Stack rong\n";
			}
			else
				cout << "Stack ko rong\n";
			break;
		}
		case 2:
		{
			if (full(sp))
			{
				cout << "Stack day\n";
			}
			else
				cout << "Stack ko day\n";
			break;
		}
		case 3:
		{
			cout << "Nhap so can them\n";
			cin >> x;
			int check = add(a, sp, x);
			if (check)
				cout << "Them thanh cong\n";
			else
				cout << "Them that bai\n";
			break;
		}
		case 4:
		{
			int check = pop(a, sp, x);
			if (check)
				cout << "Da lay duoc " << x << " ra khoi stack\n";
			else
				cout << "Stack rong\n";
			break;
		}
		default:
		{
			cout << "Bye\n";
			break;
		}
		}
		_getch();
	} while (choose <= 4);
	system("pause");
	return 0;
}

void init(int a[], int& sp)
{
	sp = -1;
}

int Rong(int sp) {
	if (sp == -1)
		return 1;
	return 0;
}

int full(int sp) {
	if (sp == Max - 1)
		return 1;
	return 0;
}

int add(int a[], int& sp, int x) {
	if (sp < Max)
	{
		sp++;
		a[sp] = x;
		return 1;
	}
	else
		return 0;
}

int pop(int a[], int& sp, int& x)
{
	if (sp > -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}
