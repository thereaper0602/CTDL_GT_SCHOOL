#include<iostream>
using namespace std;
#define M 100
void selection_sort(int a[],int n)
{
    for(int i = 0;i<n-1;i++)
    {
        int min = i;
        for(int j = i+1;j<n;j++)
        {
            if(a[min] > a[j]) min = j;
        }
        swap(a[i],a[min]);
    }
}

void interchange_sort(int a[],int n)
{
    for(int i = 0;i < n-1;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            if(a[i] > a[j]) swap(a[i],a[j]);
        }
    }
}

void inserttion_sort(int a[],int n)
{
    for(int i = 1;i<n;i++)
    {
        int j = i-1;
        int x = a[i];
        while(j>=0 && a[j] > x)
        {
            a[j+1] = a[j];
            j--;           
        }
        a[j+1] = x;
    }
}

void bubble_sort(int a[],int n)
{
    for(int i = 0;i<n-1;i++)
    {
        for(int j = n-1;j>i;j--)
        {
            if(a[j] < a[j-1])
            {
                swap(a[j],a[j-1]);
            }
        }
    }
}

void merge(int a[],int l,int m,int r)
{
    int x = m - l + 1;
    int y = r - m;
    int X[M];
    int Y[M];
    for(int i = 0;i<x;i++)
    {
        X[i] = a[l+i];
    }
    for(int j = 0;j<y;j++)
    {
        Y[j] = a[m+1+j];
    }

    int i = 0,j = 0,k = l;
    while(i<x && j<y)
    {
        if(X[i] < Y[j])
        {
            a[k] = X[i];
            i++;
        }
        else {a[k] = Y[j];j++;}
        k++;
    }
    while(i<x)
    {
        a[k] = X[i];
        i++;k++;
    }
    while(j<y)
    {
        a[k] = Y[j];j++;k++;
    }
}

void merge_sort(int a[],int l,int r)
{
    if(l<r)
    {
        int m = l + (r-l)/2;
        merge_sort(a,l,m);
        merge_sort(a,m+1,r);
        merge(a,l,m,r);
    }
}

void quick_sort(int a[],int l,int r)
{
    int i = l;
    int j = r;
    int x = a[l + (r-l)/2];
    while(i<j)
    {
        while(a[i] < x) i++;
        while(a[j] > x) j--;
        if(i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if(i < r) quick_sort(a,i,r);
    if(j > l) quick_sort(a,l,j);
}


void output(int a[],int n)
{
    for(int i = 0;i<n;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}


int main()
{
    system("cls");
    int a[] = {2,5,7,4,3,8,1,6};
    int n = sizeof(a)/sizeof(a[0]);
    quick_sort(a,0,n-1);
    output(a,n);
    return 0;
}