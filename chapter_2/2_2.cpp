#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
#define M 100
int a[M];
int n;
void input(int a[],int n);
void output(int a[],int n);
void interchange_sort_increase(int a[],int n);
void interchange_sort_decrease(int a[],int n);
void selection_sort_increase(int a[],int n);
void selection_sort_decrease(int a[],int n);
int main()
{
	return 0;
}
void input(int a[],int n)
{
	for(int i = 0;i<n;i++)
	{
		a[i] = rand() % 10 + 1;
	}
}
void output(int a[],int n)
{
	for(int i = 0;i<n;i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void interchange_sort_increase(int a[],int n)
{
	for(int i = 0;i<n;i++)
	{
		for(int j = i+1;j<n;j++)
		{
			if(a[i]>a[j]) swap(a[i],a[j]);
		}
	}
}
void interchange_sort_decrease(int a[],int n)
{
	for(int i = 0;i<n;i++)
	{
		for(int j = i+1;j<n;j++)
		{
			if(a[i]<a[j]) swap(a[i],a[j]);
		}
	}
}
void selection_sort_increase(int a[],int n)
{
	for(int i = 0;i<n;i++)
	{
		int min = 0;
		for(int i = i+1;i<n;i++)
		{
			if(a[min] > a[j]) min = j;
		}
		swap(a[min],a[i]);
	}
}
void selection_sort_decrease(int a[],int n)
{
	for(int i = 0;i<n;i++)
	{
		int max = 0;
		for(int i = i+1;i<n;i++)
		{
			if(a[max] < a[j]) max = j;
		}
		swap(a[max],a[i]);
	}
}