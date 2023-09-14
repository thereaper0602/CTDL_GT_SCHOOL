#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};

#define M 100
int stack_in[M],stack_in_NLR[M];
int stack_out[M],stack_out_NLR[M];
int sp_in =-1,sp_in_NLR = -1;
int sp_out = -1,sp_out_NLR = -1;
typedef node *nd;
void init(int &sp)
{
    sp = -1;   
}

void insert_node_loops(nd &a, int x)
{
    nd newnode = new node;
    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;
    if(a==NULL)
    {
        a = newnode;
    }
    else
    {
        nd p = a;
        nd q = NULL;
        while(p!=NULL && p->data!=x)
        {
            q = p;
            if(p->data > x)
            {
                p = p->left;
            }
            else
            {
                p = p->right;
            }
        }
        if(p==NULL)
        {
            if(q->data < x)
            {
                q->right = newnode;
            }
            else
            {
                q->left = newnode;
            }
        }
    }
}

int top(int stack[],int sp)
{
    return stack[sp];
}

void pop(int stack[],int &sp)
{
    int x;
    if(sp!=-1)
    {
        x = stack[--sp];
    }
    else return;
}

void push(int stack[],int &sp,int x)
{
    if(sp<M-1)
    {
        stack[++sp] = x;
    }
}

void push_to_stack_LNR(nd a)
{
    if(a!=NULL)
    {
        push_to_stack_LNR(a->left);
        push(stack_in,sp_in,a->data);
        push_to_stack_LNR(a->right);
    }
}

bool empty(int sp)
{
    if(sp==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void outstack(nd a)
{
    push_to_stack_LNR(a);
    while(empty(sp_in)==false)
    {
        push(stack_out,sp_out,top(stack_in,sp_in));
        pop(stack_in,sp_in);
    }
    while(empty(sp_out)==false)
    {
        cout << top(stack_out,sp_out) << " ";
        pop(stack_out,sp_out);
    }
    cout << endl;
}

void push_to_stack_NLR(nd a)
{
    if(a!=NULL)
    {
        push(stack_in_NLR,sp_in_NLR,a->data);
        push_to_stack_NLR(a->left);
        push_to_stack_NLR(a->right);
    }
}

void outstack_NLR(nd a)
{
    push_to_stack_NLR(a);
    while(empty(sp_in_NLR)==false)
    {
        push(stack_out_NLR,sp_out_NLR,top(stack_in_NLR,sp_in_NLR));
        pop(stack_in_NLR,sp_in_NLR);
    }
    while(empty(sp_out_NLR)==false)
    {
        cout << top(stack_out_NLR,sp_out_NLR) << " ";
        pop(stack_out_NLR,sp_out_NLR);
    }
}

int queue[M];
int rear = -1;
void push_queue(int queue[],int x)
{
    if(rear<M-1)
    {
       queue[++rear] = x;
    }
}

void pop_queue(int queue[],int &rear)
{
    for(int i = 0;i<rear;i++)
    {
        queue[i] = queue[i+1];
    }
    rear--;
}

int front(int queue[])
{
   return queue[0]; 
}

bool empty_queue()
{
    if(rear==-1)
    {
        return true;
    }
    else return false;
}

void push_to_queue(nd a)
{
    if(a!=NULL)
    {
        push_to_queue(a->left);
        push_to_queue(a->right);
        push_queue(queue,a->data);
    }
}

void out_queue(nd a)
{
    push_to_queue(a);
    while(empty_queue()==false)
    {
        cout << front(queue) << " ";
        pop_queue(queue,rear);
    }
    cout << endl;
}

int main()
{
    system("cls");
    nd a = new node;
    a = NULL;
    vector<int> v = {40, 20, 50, 10, 25, 43, 55, 5, 15, 30, 47, 60};
    for (int i = 0; i < v.size(); i++)
    {
        insert_node_loops(a, v[i]);
    }
    outstack(a);
    outstack_NLR(a);
    out_queue(a);
    return 0;
}