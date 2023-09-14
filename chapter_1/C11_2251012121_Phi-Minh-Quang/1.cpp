#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;
#define M 100
void input(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10 + 1;
	}
}
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
bool binary_search(int a[], int n,int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x) {return true; break;}
	}
	return false;
}
void add_number_last(int a[], int& n,int x)
{
	n++;
	a[n - 1] = x;
}
void add_number_begin(int a[], int& n, int x)
{
	n = n + 1;
	for (int i = n-1; i >= 1 && i<n ; i--)
	{
		a[i] = a[i - 1];
	}
	a[0] = x;
}
void delete_first(int a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
void delete_end(int a[], int& n)
{
	n--;
}
void add_position(int a[], int& n, int pos, int x)
{
	n++;
	if (pos >= 0 && pos <= n)
	{
		for (int i = n - 1; i > pos; i--)
		{
			a[i] = a[i - 1];
		}
		a[pos] = x;
	}
}
void delete_position(int a[], int& n, int pos)
{
	for (int i = pos + 1; i <= n; i++)
	{
		a[i-1] = a[i];
	}
	n--; 
}
void search_and_delete(int a[], int& n, int x)
{
	if (binary_search(a, n, x) == true)
	{
		int pos;
		for (int i = 0; i < n; i++)
		{
			if (a[i] == x) { pos = i; break; }
		}
		delete_position(a, n, pos);
	}
	else return;
}
void search_and_delete_all(int a[], int& n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			delete_position(a, n, i); i--;
		}
	}
}
int main()
{
	srand(time(NULL));
	int a[M];
	int n = 10;
	input(a, n);
	output(a, n);

	// 1 ,
	int x; cout << "Input the element you want to find : "; cin >> x;
	if (binary_search(a, n, x) == true) cout << "Y" << endl;
	else cout << "N" << endl;

	// 2,
	int add_number_beg; cout << "Input a number you want to add at the beginning position : "; cin >> add_number_beg;
	add_number_begin(a, n, add_number_beg);
	output(a, n);

	// 3, 
	int add_num_end; cout << "Input a number you want to add at the ending position : "; cin >> add_num_end;
	add_number_last(a, n, add_num_end);
	output(a, n);

	// 4,
	int add_num_pos,pos4;
	cout << "Input the position you want to add : "; cin >> pos4;
	cout << "Input the number you want to add at the " << pos4 << " position : "; cin >> add_num_pos;
	add_position(a, n, pos4-1, add_num_pos);
	output(a, n);

	// 5,
	cout << "Delete the first element : ";
	delete_first(a, n);
	output(a, n);
	

	// 6,
	cout << "Delete the last element : ";
	delete_end(a, n);
	output(a, n);
	

	// 7,
	int pos7; cout << "Input the position you want to delete : "; cin >> pos7;
	delete_position(a, n, pos7);
	output(a, n);
	

	// 8,
	int find_and_del; cout << "Input the number you want to delete : "; cin >> find_and_del;
	search_and_delete(a, n, find_and_del);
	output(a, n);
   

	int find_and_del_all; cout << "Input the number you want to find : "; cin >> find_and_del_all;
	search_and_delete_all(a, n, find_and_del_all);
	output(a, n);
	
	return 0;
}