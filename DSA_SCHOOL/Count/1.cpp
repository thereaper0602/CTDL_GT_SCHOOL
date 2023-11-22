#include<iostream>
#include<random>
#include<ctime>
#include<algorithm>
using namespace std;
#define M 101

void input(int a[], int n) {
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100 + 1;
	}
}

void ouput(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
}

void countingSort(int a[],int b[], int n) {
	// find max
	int max_num = a[0];
	for (int i = 1; i < n; i++) {
		max_num = max(max_num, a[i]);
	}
	int cnt[M] = { 0 };
	for (int i = 0; i < n; i++) {
		cnt[a[i]]++;
	}
	for (int i = 1; i <= max_num; i++) {
		cnt[i] += cnt[i - 1];
	}
	for (int i = n-1; i >= 0; i--) {
		b[cnt[a[i]] - 1] = a[i];
		cnt[a[i]]--;
	}
}

void output_sort(int b[], int n) {
	for (int i = 0; i < n; i++) {
		cout << b[i] << " ";
	}
	cout << "\n";
}


int main() {
	srand(time(NULL));
	int a[M], b[M], n;
	cout << "Nhap so phan tu cho mang : "; cin >> n;
	while (n <= 0 or n > M) {
		cout << "Nhap lai : "; cin >> n;
	}
	input(a, n);
	cout << "Mang ban dau la : "; ouput(a, n);
	countingSort(a, b, n);
	cout << "Mang luc sau la : "; output_sort(b, n);
	return 0;
}