#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define M 100
int a[M];
int sp;// stack's top
void init()
{
	sp = -1;
}
int push(int a[], int x)
{
	if (sp < M - 1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}
int pop(int a[], int& x)
{
	if (sp != -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}
int full(int a[], int sp)
{
	if (sp == M - 1)
	{
		return 1;
	}
	return 0;
}
bool empty(int a[], int sp)
{
	if (sp == -1)
	{
		return true;
	}
	return false;
}
int top(int a[])
{
	return a[sp];
}
long int dec_to_bin(int a[], int dec)
{
	long int result = 0;
	while (dec != 0)
	{
		push(a, dec % 2);
		dec = dec / 2;
	}
	while (!empty(a, sp))
	{
		result = result * 10 + top(a);
		pop(a, a[sp]);
	}
	return result;
}
int main()
{
	init();
	int dec1; cout << "Input a dec num to transform a bin num : "; cin >> dec1;
	cout << "dec to bin : " << dec_to_bin(a, dec1) << endl;
	int dec2; cout << "Input a dec num to transform a oct num : "; cin >> dec2;
	cout << "dec to oct : " << dec_to_oct(a, dec2) << endl;
	int dec3; cout << "Input a dec num to transform a hex num : "; cin >> dec3;
	cout << "dec to hex : " << dec_to_hex(a, dec3) << endl;
	return 0;
}s