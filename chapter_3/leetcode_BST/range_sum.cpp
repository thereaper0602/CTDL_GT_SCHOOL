#include<iostream>
#include<vector>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
typedef node* nd;
void init(nd &a)
{
    a = NULL;
}
void insert_node(nd &a,int x)
{
    if(a==NULL)
    {
        nd insert = new node;
        insert->data = x;
        insert->left = NULL;
        insert->right = NULL;
        a = insert;
    }
    else{
        if(a->data==x) return;
        else if(a->data < x)
        {
            insert_node(a->right,x);
        }
        else insert_node(a->left,x);
    }
}
void LNR(nd a)
{
    if(a!=NULL)
    {
        LNR(a->left);
        cout << a->data << " ";
        LNR(a->right);
    }
}


void add(vector<int> &v,nd a)
{
    if(a!=NULL)
    {
        add(v,a->left);
        v.push_back(a->data);
        add(v,a->right);
    }
}



int rangeSumBST(nd a,int low,int high)
{
    vector<int> v;
    add(v,a);
    int sum = 0;
    for(int i = 0;i<v.size();i++)
    {
        if(v[i]>=low && v[i] <= high)
        {
            sum+=v[i];
        }
    }
    return sum;
}

void pre(nd a,int low,int high,int &sum)
{
    if(a==NULL)
    {
        return;
    }
    if(a->data >= low && a->data <=high)
    {
        sum+=a->data;
    }
    pre(a->left,low,high,sum);
    pre(a->right,low,high,sum);
}

int anotherApproach(nd a,int low,int high)
{
    int sum = 0;
    pre(a,low,high,sum);
    return sum;
}

int main()
{
    system("cls");
    nd a = new node;init(a);
    int arr[] = {10,5,15,3,7,15,18};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0;i<n;i++)
    {
        insert_node(a,arr[i]);
    }
    LNR(a);cout << endl;
    cout << rangeSumBST(a,7,15) << endl;
    cout << anotherApproach(a,7,15) << endl;
    return 0;
}