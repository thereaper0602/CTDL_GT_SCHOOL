#include<iostream>
#include<vector>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

typedef node* nd;

bool isValidBST(nd a)
{
    if(a!=NULL)
    {
        if(a->left->data > a->data || a->right->data < a->data)
        {
            return false;
        }
        else
        {
            isValidBST(a->left);
            isValidBST(a->right);
        }
    }
    return true;
}

void insert_node(nd &a,int x)
{
    if(a==NULL)
    {
        a = new node;
        a->data = x;
        a->left = NULL;
        a->right = NULL;
    }
    else
    {
        if(a->data==x) return;
        if(a->data > x) {return insert_node(a->left,x);}
        else if(a->data < x) {return insert_node(a->right,x);}
    }
}

int main()
{
    system("cls");
    vector<int>v = {2,1,3};
    nd a = new node;
    a = NULL;
    for(int i = 0;i<v.size();i++)
    {
        insert_node(a,v[i]);
    }
    if(isValidBST(a)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}