#include<iostream>
#include<vector>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};

// https://leetcode.com/problemset/all/?topicSlugs=binary-tree&page=1&sorting=W3sic29ydE9yZGVyIjoiQVNDRU5ESU5HIiwib3JkZXJCeSI6IkRJRkZJQ1VMVFkifV0%3D

typedef node* nd;
nd a;
void init(nd &a)
{
    a = NULL;
}
// Search
nd search(nd a,int x)
{
    if(a!=NULL)
    {
    if(a->data==x)
    {
        return a;
    }
    else if(a->data < x)
    {
        return search(a->right,x);
    }
    else
    {
        return search(a->left,x);
    }
    }
    return NULL;
}

void insert_node(nd &a,int x)
{
    nd insert = new node;
    insert->data = x;
    insert->left = NULL;
    insert->right = NULL;
    if(a==NULL)
    {
        a = insert;
    }
    else
    {
        if(a->data==x) return;
        else if(a->data < x)
        {
            return insert_node(a->right,x);
        }
        else
        {
            return insert_node(a->left,x);
        }
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

void NLR(nd a)
{
    if(a!=NULL)
    {
        cout << a->data << " ";
        NLR(a->left);
        NLR(a->right);
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

int Delete(nd a,int x)
{
    if (a==NULL) return 0;
    if(a->data == x)
    {
        nd p = a;
        if(a->left==NULL){
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

int main()
{
    system("cls");
    vector<int> v = {40,20,50,10,25,5,15,30,43,55,47,60};
    a = new node;
    init(a);
    for(int i = 0;i<v.size();i++)
    {
        insert_node(a,v[i]);
    }
    LNR(a);cout << endl;
    NLR(a);cout << endl;
    LRN(a);cout << endl;
    return 0;
}