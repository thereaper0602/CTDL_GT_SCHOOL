//#include<iostream>
//using namespace std;
//struct queue
//{
//	int data;
//	queue* next;
//};
//typedef queue* qu;
//void init(qu& a)
//{
//	a = NULL;
//}
//void push(qu& a, int x)
//{
//	qu insert = new queue;
//	insert->data = x;
//	insert->next = NULL;
//	if (a == NULL) a = insert;
//	else
//	{
//		qu p = a;
//		while (p->next != NULL)
//		{
//			p = p->next;
//		}
//		p->next = insert;
//	}
//}
//void pop(qu& a)
//{
//	qu p = a;
//	a = a->next;
//	delete p;
//}
//bool empty(qu a)
//{
//	if (a == NULL) return true;
//	else return false;
//}
//int front(qu e)
//{
//	return e->data;
//}
//void process(qu e)
//{
//	qu p = e;
//	while (p != NULL)
//	{
//		cout << p->data << " ";
//		p = p->next;
//	}
//	cout << endl;
//}
//int reverse_num(int num)
//{
//	int result = 0;
//	qu a;
//	init(a);
//	for (int i = num; i != 0; i = i / 10)
//	{
//		push(a,i % 10);
//	}
//	while (!empty(a))
//	{
//		result = result * 10 + front(a);
//		pop(a);
//	}
//	return result;
//}
//int main()
//{
//	int num; cin >> num;
//	cout << reverse_num(num) << endl;
//	return 0;
//}