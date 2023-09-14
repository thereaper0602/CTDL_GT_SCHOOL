#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

struct frequency{
    int value,fre,index;
};

struct ele{
    int count,index,val;
};

bool mycomp(ele a,ele b)
{
    return (a.val < b.val);
}

bool mycomp2(ele a,ele b)
{
    if(a.count!=b.count)
    {
        return (a.count < b.count);
    }
    else return a.index > b.index;
}


void printByFrequency(vector<int>&arr)
{
    int n = arr.size();
    ele element[arr.size()];
    for(int i = 0;i<arr.size();i++)
    {
        element[i].index = i;
        element[i].count = 0;
        element[i].val = arr[i];
    }


    stable_sort(element,element+n,mycomp);
    element[0].count = 1;
    for(int i = 1;i<n;i++)
    {
        if(element[i].val==element[i-1].val)
        {
            element[i].count+=element[i-1].count+1;
            element[i-1].count = -1;
            element[i].index = element[i-1].index;
        }
        else element[i].count = 1;
    }
    stable_sort(element,element+n,mycomp2);
    for(int i = n-1,index = 0;i>=0;i--)
    {
        if(element[i].count!=-1)
        {
            for(int j = 0;j<element[i].count;j++)
            {
                arr[index++] = element[i].val;
            }
        }
    }
}


int main()
{
    system("cls");
    vector<int>v = {5, 2, 2, 8, 5, 6, 8, 8};
    printByFrequency(v);
    for(auto x : v)
    {
        cout << x << " ";
    }
    return 0;
}