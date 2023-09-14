//#include<iostream>
//#include<vector>
//using namespace std;
//#define M 100
//
//struct P {
//	int cofficient[M];
//	string uknown_factor[M];
//};
//int input(P &a)
//{
//	int so_luong; cout << "Input the number of your polynomial : "; cin >> so_luong;
//	int i = 0;
//	while (so_luong >= 1)
//	{
//		int coef; cout << "Input the coefficient : "; cin >> coef;
//		string unknown; cout << "Input the unknown factor : "; cin >> unknown;
//		a.cofficient[i] = coef;
//		a.uknown_factor[i] = unknown;
//		i++;
//		--so_luong;
//	}
//	return i;
//}
//void output(P a, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		if (i == 0) cout << a.cofficient[i] << a.uknown_factor[i] << " ";
//		else if (a.cofficient[i] > 0)cout << " + " << a.cofficient[i] << a.uknown_factor[i] << " ";
//		else cout << a.cofficient[i] << a.uknown_factor[i] << " ";
//	}
//	cout << endl;
//}
//void add_end(P &a, int& n, int x, string s)
//{
//	n++;
//	a.cofficient[n - 1] = x;
//	a.uknown_factor[n-1] = s;
//}
//int sum(P a,P b,P &add,int n1,int n2)
//{
//	int n_sum = 0;
//	vector<bool> seen1(n1,false);
//	vector<bool> seen2(n2, false);
//	for (int i = 0; i < n1; i++)
//	{
//	     for (int j = 0; j < n2; j++)
//		 {
//			 if (a.uknown_factor[i] == b.uknown_factor[j]) 
//			 {
//				 add.cofficient[n_sum] = a.cofficient[i] + b.cofficient[j];
//				 add.uknown_factor[n_sum] = a.uknown_factor[i];
//				 seen1[i] = true;
//				 seen2[j] = true;
//				 n_sum++;
//			 }
//		 }
//	}
//	for (int i = 0; i < n1; i++)
//	{
//		if (seen1[i] != true)
//		{
//			add_end(add, n_sum, a.cofficient[i], a.uknown_factor[i]);
//		}
//	}
//	for (int i = 0; i < n2; i++)
//	{
//		if (seen2[i] != true)
//		{
//			add_end(add, n_sum, b.cofficient[i], b.uknown_factor[i]);
//		}
//	}
//	return n_sum;
//}
//int minus_rs(P a, P b, P& add, int n1, int n2)
//{
//	int n_sum = 0;
//	vector<bool> seen1(n1, false);
//	vector<bool> seen2(n2, false);
//	for (int i = 0; i < n1; i++)
//	{
//		for (int j = 0; j < n2; j++)
//		{
//			if (a.uknown_factor[i] == b.uknown_factor[j])
//			{
//				add.cofficient[n_sum] = a.cofficient[i] - b.cofficient[j];
//				add.uknown_factor[n_sum] = a.uknown_factor[i];
//				seen1[i] = true;
//				seen2[j] = true;
//				n_sum++;
//			}
//		}
//	}
//	for (int i = 0; i < n1; i++)
//	{
//		if (seen1[i] != true)
//		{
//			add_end(add, n_sum, a.cofficient[i], a.uknown_factor[i]);
//		}
//	}
//	for (int i = 0; i < n2; i++)
//	{
//		if (seen2[i] != true)
//		{
//			add_end(add, n_sum, b.cofficient[i], b.uknown_factor[i]);
//		}
//	}
//	return n_sum;
//}
////char power(string a,int n)
////{
////	for (int i = 0; i < n; i++)
////	{
////		if (isalnum(a[i]))
////		{
////			return char(int(a[i]));
////		} 
////	}
////}
//int multiplied(P a, P b, P &multi, int n1, int n2)
//{
//	int multi_count = 0;
//	for (int i = 0; i < n1; i++)
//	{
//		for (int j = 0; j < n2; j++)
//		{
//			multi.cofficient[multi_count] = a.cofficient[i] * b.cofficient[j];
//			multi.uknown_factor[multi_count] = a.uknown_factor[i] + b.uknown_factor[j];
//			multi_count++;
//		}
//	}
//	return multi_count;
//}
//int main()
//{
//	P p1; P sum_result; P minus_result; P multi_result;
//	cout << "First polynomial " << endl;
//	int count_p1 = input(p1);
//	P p2;
//	system("cls");
//	cout << "Second polynomial " << endl;
//	int count_p2 = input(p2);
//	system("cls");
//	cout << "P1 = "; output(p1, count_p1);
//	cout << "P2 = "; output(p2, count_p2);
//	//int add_count = sum(p1, p2, sum_result, count_p1, count_p2);
//	//cout << "Sum = ";output(sum_result, add_count);
//	//int minus_count = minus_rs(p1, p2, minus_result, count_p1, count_p2);
//	//cout << "Minus = "; output(minus_result, minus_count);
//	//int multi_count = multiplied(p1, p2, multi_result, count_p1, count_p2);
//	//cout << "Multiply = "; output(multi_result, multi_count);
//	return 0;
//}