#include<iostream>
#include<vector>
#include<set>
#include<cstdlib>
#include<ctime>
using namespace std;
#define M 100
int a[M],b[M];
int m,n;

// 12 23 4 23 56 2 1 7 89 23 12 90 3
// 45 23 45 89 24 12 34 45 91 3 22 9 7
void input(int a[],int m)
{
    for(int i = 0;i<m;i++)
    {
        cin >> a[i];
    }
}

void output(int a[],int n)
{
    for(int i = 0;i<n;i++)
    {
        cout << a[i] <<  " ";
    }
    cout << endl;
}

void HOP(int a[],int b[],int m,int n)
{
    vector<int> v;
    int hop[M];
    for(int i = 0;i<m;i++)
    {
        v.push_back(a[i]);
    }
    for(int i = 0;i<n;i++)
    {
        v.push_back(b[i]);
    }
    set<int> s;
    for(int i = 0;i<v.size();i++)
    {
        s.insert(v[i]);
    }
    int count = 0;
    for(auto x : s)
    {
        hop[count] = x;count++;
    }
    output(hop,count);
}

void delete_el(int a[],int &n,int pos)
{
    for(int i = pos+1;i<=n;i++)
    {
        a[i-1] = a[i];
    }
    n--;
}

void GIAO(int a[],int b[],int m,int n)
{
    int giao[M];
    int count = 0;
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(a[i]==b[j])
            {
                giao[count] = a[i];
                count++;
            }
        }
    }
    for(int i = 0;i<count;i++)
    {
        for(int j = i+1;j<count;j++)
        {
            if(giao[i]==giao[j])
            {
                delete_el(giao,count,j);
                j--;
            }
        }
    }
    output(giao,count);
}

void del_same(int a[],int &n,int x)
{
    for(int i = 0;i<n;i++)
    {
        if(a[i]==x)
        {
            delete_el(a,n,i);
            i--;
        }
    }
}

void HIEU(int a[],int b[],int m,int n)
{
    int bu_a[M];
    int bu_b[M];
    bool seen_a[M] = {false};
    bool seen_b[M] = {false};
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(a[i]==b[j])
            {
                seen_a[i] = true;
            }
        }
    }
    int count_a = 0;
    for(int i = 0;i<m;i++)
    {
        if(seen_a[i]==false)
        {
            bu_a[count_a] = a[i];
            count_a++;
        }
    }
    
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(a[j]==b[i])
            {
                seen_b[i] = true;
            }
        }
    }
    int count_b = 0;
    for(int i = 0;i<n;i++)
    {
        if(seen_b[i]==false)
        {
            bu_b[count_b] = b[i];
            count_b++;
        }
    }
    int cpy_a = count_a,cpy_b = count_b;
    for(int i = 0;i<cpy_a-1;i++)
    {
        for(int j = i+1;j<cpy_a;j++)
        {
            if(bu_a[i]==bu_a[j])
            {
                delete_el(bu_a,count_a,j);
            }
        }
    }

    for(int i = 0;i<cpy_b-1;i++)
    {
        for(int j = i+1;j<cpy_b;j++)
        {
            if(bu_b[i]==bu_b[j])
            {
                delete_el(bu_b,count_b,j);
            }
        }
    }
    cout << "Phan bu cua a : ";output(bu_b,count_b);
    cout << "Phan bu cua b : ";output(bu_a,count_a);
}

int main()
{
    system("cls");
    srand(time(NULL));
    cout << "m : ";cin >> m;
    cout << "n : ";cin >> n;
    input(a,m);input(b,n);
    output(a,m);output(b,n);
    HOP(a,b,m,n);
    GIAO(a,b,m,n);
    HIEU(a,b,m,n);
    return 0;
}