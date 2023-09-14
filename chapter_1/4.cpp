#include<iostream>
#include<map>
using namespace std;
struct stack {
	int data;
	stack* next;
};
typedef stack* st;
int top(st a)
{
	st p = a;
	return p->data;
}
void init(st &a)
{
	a = NULL;
}
bool empty(st& a)
{
	if (a == NULL) return true;
	else return false;
}
int size(st& a)
{
	st p = a;
	int cnt = 0;
	while (p != NULL)
	{
		cnt++;
	}
	return cnt;
}
void push(st& a,int x)
{
	st insert = new stack;
	insert->data = x;
	insert->next = NULL;
	insert->next = a;
	a = insert;
}
void pop(st& a)
{
	st p = a;
	a = a->next;
	delete p;
}
long long dec_to_bin(int dec)
{
	long long result = 0;
	st stck = new stack;
	init(stck);
	while (dec != 0)
	{
		push(stck, dec % 2);
		dec = dec / 2;
	}
	while (!empty(stck))
	{
		result = result * 10 + top(stck);
		pop(stck);
	}
	return result;
}


void HaNoi(int n, st& source, st& aux, st& dest)
{
    if (n == 1)
    {
        int disk = top(source);
        pop(source);
        push(dest, disk);
        cout << "Move disk " << disk << " from " << &source << " to " << &dest << endl;
        return;
    }

    HaNoi(n - 1, source, dest, aux);

    int disk = top(source);
    pop(source);
    push(dest, disk);
    cout << "Move disk " << disk << " from " << &source << " to " << &dest << endl;

    HaNoi(n - 1, aux, source, dest);
}


void TowerOfHanoi()
{
    st source, aux, dest;
    init(source);
    init(aux);
    init(dest);

    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    for (int i = n; i > 0; i--)
    {
        push(source, i);
    }

    HaNoi(n, source, aux, dest);

    while (!empty(dest))
    {
        pop(dest);
    }
}



// long long dec_to_oct(int dec)
// {
// 	st a = new stack;
// 	init(a);
// 	while (dec != 0)
// 	{
// 		push(a, dec % 8);
// 		dec = dec / 8;
// 	}
// 	long long result = 0;
// 	while (!empty(a))
// 	{
// 		result = result * 10 + top(a);
// 		pop(a);
// 	}
// 	return result;
// }
// string dec_to_hex(int dec)
// {
// 	map <int,char> hex_table = { {10,'A'},{11,'B'},{12,'C'},{13,'D'},{14,'E'},{15,'F'}};
// 	st a = new stack;
// 	init(a);
// 	while (dec != 0)
// 	{
// 		push(a, dec % 16);
// 		dec = dec / 16;
// 	}
// 	string result = "";
// 	while (!empty(a))
// 	{
// 		if (top(a) <= 9)
// 		{
// 			result = result + char(48 + top(a));
// 		}
// 		else
// 		{
// 			result = result + hex_table[top(a)];
// 		}
// 		pop(a);
// 	}
// 	return result;
// }
int main()
{
	int dec1; cout << "Input a dec num to transform to bin num : "; cin >> dec1;
	cout << "Dec to bin : " << dec_to_bin(dec1) << endl;
    TowerOfHanoi();
	return 0;
}
