#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
    int val;
    node* right;
    node* left;
    node() : val(0),left(nullptr),right(nullptr){}
    node(int x) : val(x),left(nullptr),right(nullptr){}
    node(int x,node* left,node* right) : val(x),left(left),right(right){}
};

typedef node* nd;

void add_Vec(vector<int>&v,nd a)
{
    if(a!=NULL)
    {
        add_Vec(v,a->left);
        v.push_back(a->val);
        add_Vec(v,a->right);
    }
}

int minDiffInBST(nd a)
{
    vector<int> v;
    add_Vec(v,a);
    int min = v[1] - v[0];
    for(int i = 1;i<v.size();i++)
    {
        for(int j = i-1;j<i;j++)
        {
            if(min > v[i] - v[j])
            {
                min = v[i] - v[j];
            }
        }
    }
    return min;
}

int mini = INT_MAX;
int prev_1 = -1;
void inorder(nd root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        if(prev_1==-1) 
        {
            prev_1 = root->val;
        }
        else
        {
            mini = min(root->val-prev_1,mini);
            prev_1 = root->val;
        }
        inorder(root->right);
    }
}

int minDiffInBST_2(nd root)
{
    if(root==NULL || (root->left==NULL && root->right==NULL)) {return 0;}
    inorder(root);
    return mini;
}

int main()
{
    system("cls");
    nd a = new node(27);
    a->right = new node(34);
    a->right->right = new node(58);
    a->right->right->left = new node(50);
    a->right->right->left->left = new node(44);
    cout << minDiffInBST_2(a) << endl;
    cout << INT_MAX << endl;
    return 0;
}