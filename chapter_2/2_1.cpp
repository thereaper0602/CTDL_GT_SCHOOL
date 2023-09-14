#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
#define M 100
int a[M];
int n;
void input(int a[], int n);
void output(int a[], int n);
void insertion_sort(int a[], int n);
void selection_sort(int a[], int n);
void interchange_sort(int a[], int n);
void bubble_sort(int a[], int n);
int sequential_search(int a[], int n,int x);
int binary_search(int a[], int n, int x);
void menu()
{
	cout << "1 . Create and show the list : " << endl;
	cout << "2 . Sorting by using insertion sort : " << endl;
	cout << "3 . Sorting by using selection sort : " << endl;
	cout << "4 . Sorting by using interchange sort : " << endl;
	cout << "5 . Sorting by using bubble sort : " << endl;
	cout << "6 . Searching by using sequential search : " << endl;
	cout << "7 . Searching by using binary_search : " << endl;
}
int main()
{
	system("cls");
	cout << "Hello" << endl;
	return 0;
}

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

void insertion_sort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int x = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > x)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}

void selection_sort(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i+1; j < n; j++)
		{
			if (a[min] > a[j])
			{
				min = j;
			}
		}
		swap(a[i], a[min]);
	}
}

void interchange_sort(int a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (a[i] < a[j]) swap(a[i], a[j]);
		}
	}
}

void bubble_sort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j >= i; j--)
		{
			if (a[j-1] > a[j]) swap(a[j-1], a[j]);
		}
	}
}

int sequential_search(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			return i; break;
		}
	}
	return -1;
}

int binary_search(int a[], int n,int x)
{
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (a[mid] == x) return mid;
		else if (a[mid] > x) mid = left + 1;
		else mid = right - 1;
	}
	return -1;
}