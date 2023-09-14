#include<iostream>
#include<vector>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node() : data(0),left(nullptr),right(nullptr){}
    node(int x) : data(x),left(nullptr),right(nullptr){}
    node(int x,node *left,node* right) : data(x),left(left),right(right){}
};
typedef node* nd;
void addVec(nd a,vector<int>&v)
{
    if(a!=NULL)
    {
        addVec(a->left,v);
        v.push_back(a->data);
        addVec(a->right,v);
    }
}

void addTree(nd a,nd b,int x)
{
    b->right = new node(x);
    b = b->right;
}

nd increasingBST(nd a)
{
    nd newNode = new node;
    vector<int> v;
    addVec(a,v);
    nd curr = newNode;
    for(auto x : v)
    {
        curr->right = new node(x);
        curr = curr->right;
    }
    return newNode->right;
}
void process(nd a)
{
    if(a!=NULL)
    {
        process(a->left);
        cout << a->data << " ";
        process(a->right);
    }
}

int main()
{
    system("cls");
    nd a = new node(5);
    a->left = new node(3);
    a->left->left = new node(2);
    a->left->left->left = new node(1);
    a->left->right = new node(4);
    a->right = new node(6);
    a->right->right = new node(8);
    a->right->right->left = new node(7);
    a->right->right->right = new node(9);
    //process(a);cout << endl;
    nd newNode = new node;
    newNode = increasingBST(a);
    process(newNode);
 
 

    return 0;
}