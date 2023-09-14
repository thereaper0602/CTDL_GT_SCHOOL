#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Ôn tập cây nhị phân 
/* 
- thực hiện các thao tác cũ dùng theo các phương pháp : đệ qui , không đệ qui , stack
- Đếm các node là node cha bậc 1,2
- Tính chiều cao cây , nhánh bên trái , nhánh bên phải
- đếm các node là số chẵn , đếm các node là số lẻ , số nguyên tố , số đảo ngược = số gốc
- lấy dữ liệu từ file tx
*/

/*
   Làm bài tập 
*/


// tree
struct node{
    int val;
    node* left;
    node* right;
};

typedef node* nd;

struct stack{
    nd data;
    stack *next;
};

typedef stack* st;

void inStack(st &a)
{
    a = NULL;
}

bool empty(st a)
{
    if(a==NULL) return true;
    else return false;
}

void push(st &a,nd x)
{
    st insert = new stack;
    insert->data = x;
    insert->next = a;
    a = insert;
}

void pop(st &a)
{
    if(a!=NULL){
    st p = a;
    a = a->next;
    delete p;
  }
}

nd top(st a)
{
    return a->data;
}

// 1.

void  init(nd &a)
{
    a = NULL;
}

 bool searchNoLoop(nd a,int x)
{
    if(a!=NULL)
    {
        if(a->val==x) return true;
        else if(a->val < x)
        {
            return searchNoLoop(a->right,x);
        }
        else
        {
            return searchNoLoop(a->left,x);
        }
    }
    else return false;
}

bool searchLoop(nd a,int x)
{
    if(a==NULL) {return false;}
    else
    {
        nd p = a;
        while(p!=NULL)
        {
            if(p->val==x) {return true;}
            else if(p->val < x)
            {
                if(p->right!=NULL) {p = p->right;}
                else return false;
            }
            else if(p->val > x)
            {
                if(p->left!=NULL) {p = p->left;}
                else return false;
            }
        }
    }
    return false;
}

void addNoLoop(nd &a,int x)
{
    nd insert = new node;
    insert->val = x;
    insert->left = NULL;
    insert->right = NULL;
    if(a==NULL)
    {
        a = insert;
    }
    else
    {
        if(a->val==x) return;
        else if(a->val > x) addNoLoop(a->left,x);
        else addNoLoop(a->right,x);
    }
}

void addLoop(nd &a,int x)
{
    nd insert = new node;
    insert->val = x;
    insert->left = NULL;
    insert->right = NULL;
    if(a==NULL) a = insert;
    else
    {
        nd p = a;
        while(p)
        {
            if(p->val==x) return;
            else if(p->val > x)
            {
                if(p->left!=NULL)
                {
                    p = p->left;
                }
                else p->left = insert;
            }
            else
            {
                if(p->right != NULL)
                {
                    p = p->right;
                }
                else p->right = insert;
            }
        }
    }
}

void searchStandFor(nd &p,nd &q)
{
    if(q->left==NULL)
    {
        p->val = q->val;
        p = q;
        q = q->right;
    }
    else searchStandFor(p,q->left);
}

int deleteNoLoop(nd &a,int x)
{
    if(a==NULL) return 0;
    if(a->val==x)
    {
        nd p = a;
        if(a->right==NULL)
        {
            a = a->left;
        }
        else if(a->left==NULL)
        {
            a = a->right;
        }
        else {searchStandFor(p,a->right);}
        delete p;
        return 1;
    }
    if(a->val < x) return deleteNoLoop(a->right,x);
    if(a->val > x) return deleteNoLoop(a->left,x);
}

void LNR(nd a)
{
    if(a!=NULL)
    {
        LNR(a->left);
        cout << a->val << " ";
        LNR(a->right); 
    }
}


void LNRloop(nd a)
{
    st stk = new stack;inStack(stk);
    nd curr = a;
    while(curr || !empty(stk))
    {
        while(curr)
        {
            push(stk,curr);
            curr = curr -> left;
        }
        curr = top(stk);
        cout << curr->val;
        pop(stk);
        curr = curr->right;
    }
}

void LRN(nd a)
{
    if(a)
    {
        LRN(a->left);
        LRN(a->right);
        cout << a->val << " ";
    }
}

void LRNloop(nd a)
{
    if(a==NULL) return;
    st stk = new stack;inStack(stk);
    nd curr = a;
    nd last = NULL;
    while(!empty(stk)||curr)
    {
        if(curr)
        {
            push(stk,curr);
            curr = curr->left;
        }
        else
        {
            nd topStack = top(stk);
            if(topStack->right && last!=topStack->right)
            {
                curr = topStack->right;
            }
            else
            {
                cout << topStack->val << " ";
                last = topStack;
                pop(stk);
            }
        }
    }

}


void NLR(nd a)
{
    if(a!=NULL)
    {
        cout << a->val << " ";
        NLR(a->left);
        NLR(a->right);
    }
}

void NLRloop(nd a)
{
    st stk = new stack;inStack(stk);
    nd curr = a;
    nd last = NULL;
    while(!empty(stk) || curr)
    {
        if(curr)
        {
            cout << curr->val << " ";
            push(stk,curr);
            curr = curr -> left; 
        }
        else
        {
            nd topStack = top(stk);
            if(topStack->right && last!=topStack->right)
            {
                curr = topStack->right;
            }
            else
            {
                last = topStack;
                pop(stk);
            }
        }
    }
}

int heightOfTree(nd a)
{
    if(a==NULL) return 0;
    int leftHeight = heightOfTree(a->left);
    int rightHeight = heightOfTree(a->right);
    return 1 + max(leftHeight,rightHeight);
}

/*int heightOfTreeNoLoop(nd a)
{

}*/



int main()
{
    nd a = new node;
    init(a);
    vector<int> v = {3,2,1,4,6,5,7};
    for(auto x : v)
    {
        addNoLoop(a,x);
    }
    LNR(a);cout << endl;
    cout << "LRN : ";LRN(a);cout << "\n";
    cout << "LRN loop ";LRNloop(a);cout << "\n";
    cout << "LNR no recursion : ";LNRloop(a);cout << '\n';
    cout << "NLR with recursion : ";NLR(a);cout << '\n';
    cout << "NLR with loop : ";NLRloop(a);cout << '\n';
    cout << "Height of the tree : ";cout << heightOfTree(a) << endl;
   /* int x;cout << "input the number you want to search : ";cin >> x;
    if (searchLoop(a,x)) cout << "y" << endl;
    else cout << "n" << endl;
    int x1;cout << "Input the number you want to delete : ";cin >> x1;
    deleteNoLoop(a,x1);
    cout << "The tree after delete " << x1 << " : ";LNR(a);cout << endl;
    */
    return 0;
}