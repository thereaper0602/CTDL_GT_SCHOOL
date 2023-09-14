#include<iostream>
#include<vector>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};
typedef node* nd;
void init(nd &a)
{
    a = NULL;
}

bool search(nd a,int x)
{
    if(a==NULL) return false;
    else
    {
        if(a->data == x) return true;
        if(a->data < x){
            return search(a->right,x);
        }
        else {
            return search(a->left,x);
        }
    }
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
    else
    {
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

void LRN(nd a)
{
    if(a!=NULL)
    {
        LRN(a->left);
        LRN(a->right);
        cout << a->data << " ";
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

void search_stand_for(nd &p,nd &q)
{
    if(q->left==NULL)
    {
        p->data = q->data;
        p = q;
        q = q->right;
    }
    else search_stand_for(p,q->left);
}

void delete_node(nd &a,int x)
{
    if(a==NULL) return;
    if(a->data==x)
    {
        nd p = a;
        if(a->left == NULL)
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
    }
    if(a->data < x) return delete_node(a->right,x);
    if(a->data > x) return delete_node(a->left,x);
}
int count = 0;

int main()
{
    system("cls");
    nd a = new node;
    init(a);
    vector <int> v = {60,50,40,15,70,20,30,45,80,90,25,65,75,29,62,68};
    for(auto x : v)
    {
        insert_node(a,x);
    }
    LNR(a);cout << endl;
    NLR(a);cout << endl;
    return 0;
}