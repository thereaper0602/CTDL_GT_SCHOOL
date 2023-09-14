#include<iostream>
#include<vector>
using namespace std;

void Dutch(vector<int>&v)
{
    int l = 0,m = 0;
    int h = v.size()-1;
    while(m<=h)
    {
        switch (v[m])
        {
            case 0:{
                swap(v[l],v[m]);
                l++;m++;
                break;
            }
            case 1:{
                m = m + 1;
                break;
            }
            case 2:{
                swap(v[m],v[h]);
                h = h-1;
                break;
            }
        }
    }
}

int main()
{
    system("cls");
    vector<int>v = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    Dutch(v);
    for(auto x : v)
    {
        cout << x << " ";
    }


    return 0;
}