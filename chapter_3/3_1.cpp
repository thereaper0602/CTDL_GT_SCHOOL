#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};
typedef node* nd;
nd a;
void init(nd &a)
{
    a = NULL;
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
        else if(a->data < x) {return insert_node(a->right,x);}
        else {return insert_node(a->left,x);}
    }
}
nd search(nd a,int x)
{
    if(a==NULL) return NULL;
    else
    {
        if(a->data==x) {return a;}
        else if(a->data > x) {return search(a->left,x);}
        else { return search(a->right,x);}
    }
}
void search_stand_for(nd &p,nd &q)
{
    if(q->left==NULL)
    {
        p->data = q->data;
        p = q;
        q = q->left;
    }
    else search_stand_for(p,q->left);
}
int Delete(nd &a,int x)
{
    if(a==NULL) return 0;
    if(a->data==x)
    {
        nd p = a;
        if(a->left==NULL)
        {
            a = a->right;
        }
        else if(a->right==NULL)
        {
            a = a->left;
        }
        else
        {
            search_stand_for(p,a->right);
        }
        delete p;
        return 1;
    }
    if(a->data<x) return Delete(a->right,x);
    if(a->data>x) return Delete(a->left,x);
}
void NLR(nd a)
{
    if(a!=NULL)
    {
        cout << a->data << " ";
        NLR(a->left);
        NLR(a->right);
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
void LRN(nd a)
{
    if(a!=NULL)
    {
        LRN(a->left);
        LRN(a->right);
        cout << a->data << " ";
    }
}
int cnt(nd a)
{
    static int count = 0;
    if (a!=NULL)
    {
        count++;
        cnt(a->left);
        cnt(a->right);
    }
    return count;
}
float average(nd a)
{
    static float sum = 0;
    if(a!=NULL)
    {
        sum+=a->data;
        average(a->left);
        average(a->right);
    }
    return sum/cnt(a);
}
int max(nd a)
{
    if(a==NULL) return -1;
    else
    {
        if(a->right==NULL) return a->data;
        else max(a->right);
    }
}
bool is_prime(int n)
{
    for(int i = 2;i<=sqrt(n);i++)
    {
        if(n%i==0) return false;
    }
    return true;
}
int prime_num(nd a)
{
    static int prime = 0;
    if(a!=NULL)
    {
        if(is_prime(a->data)==true) {prime++;}
        prime_num(a->left);
        prime_num(a->right);
    }
    return prime;
}
int main()
{
    system("cls");
    return 0;
}