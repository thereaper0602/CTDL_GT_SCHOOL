#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

struct node{
    int val;
    node *next;
};
typedef node* nd;

void init(nd &a)
{
    a = NULL;
}

void create(vector<int>&v,int m)
{
    for(int i = 0;i<m;i++)
    {
        int x;cin >> x;
        v.push_back(x);
    }
}

void append(nd &a,int x)
{
    nd insert = new node;
    insert->val = x;
    insert->next = NULL;
    if(a==NULL)
    {
        a = insert;
    }
    else
    {
        nd p = a;
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = insert;
    }
}

void sort_order(nd &a,int x)
{
    nd insert = new node;
    insert->val = x;
    insert->next = NULL;
    if(a==NULL)
    {
        a = insert;
    }
    else
    {
        nd p = a;
        nd q = NULL;
        while(p!=NULL && p->val < x)
        {
            q = p;
            p = p->next;
        }
        q->next = insert;
        insert->next = p;
    }
}

void sort(nd &a)
{
    nd new_arr = new node;
    nd p = a;
    while(p!=NULL)
    {
        sort_order(new_arr,p->val);
        a = a->next;
        p = p->next;
    }
    a = new_arr->next;
}

void process(nd a)
{
    if(a!=NULL)
    {
        nd p = a;
        while(p!=NULL)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
}

void del_el(nd &a,nd x)
{
    if(a==NULL) return;
    else
    {
        nd p = a;
        nd q = NULL;
        while(p!=NULL && p!=x)
        {
            q = p;
            p = p->next;
        }
        if(q==NULL)
        {
            a = NULL;
        }
        else if(p==NULL)
        {
            q->next = NULL;
        }
        else
        {
            q->next = p->next;
        }
        delete p;
    }
}

int count(nd a)
{
    if(a==NULL) return 0;
    else 
    {
        int cnt = 0;
        nd p = a;
        while(p!=NULL)
        {
            cnt++;
            p = p->next;
        }
        return cnt;
    }
}

void delete_same(nd &start)
{
    node *ptr1, *ptr2, *dup;
    ptr1 = start;
    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        
        while (ptr2->next != NULL)
        {
            /* If duplicate then delete it */
            if (ptr1->val == ptr2->next->val)
            {
                /* sequence of steps is important here */
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete(dup);
            }
            else /* This is tricky */
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

nd HOP(nd a,nd b)
{
    nd hop = new node;init(hop);
    nd p_a = a,p_b = b;
    while(p_a!=NULL)
    {
        append(hop,p_a->val);
        p_a = p_a -> next;
    }
    while(p_b!=NULL)
    {
        append(hop,p_b->val);
        p_b = p_b -> next;
    }
    delete_same(hop);
    sort(hop);
    return hop;
}

nd GIAO(nd a,nd b)
{
    nd giao = new node;
    giao = NULL;
    nd p_a = a;
    while(p_a!=NULL)
    {
        nd p_b = b;
        while(p_b!=NULL)
        {
            if(p_a->val==p_b->val)
            {
                append(giao,p_a->val);
            }
            p_b = p_b->next;
        }
        p_a = p_a->next;
    }
    sort(giao);
    delete_same(giao);
    return giao;
}

void BU(nd a,nd b)
{
    nd bu_a = new node;init(bu_a);
    nd bu_b = new node;init(bu_b);
    nd p_a = a;
    while(p_a!=NULL)
    {
        nd p_b = b;
        while(p_b!=NULL && p_b->val!=p_a->val)
        {
            p_b = p_b -> next;
        }
        if(p_b==NULL)
        {
            append(bu_a,p_a->val);
        }
        p_a = p_a->next;
    }
    nd p_b = b;
    while(p_b!=NULL)
    {
        nd p_a = a;
        while(p_a!=NULL && p_a->val!=p_b->val)
        {
            p_a = p_a -> next;
        }
        if(p_a==NULL)
        {
            append(bu_b,p_b->val);
        }
        p_b = p_b->next;
    }
    sort(bu_a);sort(bu_b);
    cout << "Bu a : ";process(bu_b);
    cout << "Bu b : ";process(bu_a);
}

int main()
{
    system("cls");
    nd a = new node;a = NULL;
    nd b = new node;b = NULL;
    nd c = new node;c = NULL;
    nd d = new node;d = NULL;
    vector<int>v1 = {12,23,4,23,56,2,1,7,89,23,12,90,3};
    vector<int>v2 = {45,23,46,89,24,12,34,45,91,3,22,9,7};
    for(int i = 0;i<v1.size();i++)
    {
        append(a,v1[i]);
    }
    for(int i = 0;i<v2.size();i++)
    {
        append(b,v2[i]);
    }
    process(a);
    process(b);
    nd hop = new node;init(hop);
    hop = HOP(a,b);
    cout << "Hop : ";process(hop);
    nd giao = new node;init(giao);
    giao = GIAO(a,b);
    cout << "Giao : ";process(giao);
    BU(a,b);
    return 0;
}