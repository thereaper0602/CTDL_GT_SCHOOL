#include <iostream>
#include<unordered_map>
using namespace std;

struct node
{
    int val;
    node *next;
    node() : val(0), next(nullptr) {}
    node(int x) : val(x), next(nullptr) {}
    node(int x, node *next) : val(x), next(next) {}
};


typedef node *nd;
nd removeEle(nd a, int x)
{
    while(a!=NULL && a->val==x)
    {
        a = a->next;
    }
    if(a==NULL) return NULL;
    nd temp = a;
    while(temp->next!=NULL)
    {
        if(temp->next->val==x)
        {
            temp->next = temp->next->next;
        }
        else temp = temp -> next;
    }
    return a;
}

void process(nd a)
{
    nd p = a;
    while(p!=NULL)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    system("cls");
    nd a = new node(1);
    a->next = new node(2);
    a->next->next = new node(6);
    a->next->next->next = new node(3);
    a->next->next->next->next = new node(4);
    a->next->next->next->next->next = new node(5);
    a->next->next->next->next->next->next = new node(6);
    nd q = a->next->next;
    process(a);
    nd newhead = new node;
    newhead = removeEle(a,6);
    process(a);
    return 0;
}