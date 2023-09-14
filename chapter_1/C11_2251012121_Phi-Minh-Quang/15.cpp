#include<iostream>
#include<vector>
using namespace std;
struct poly{
    int val;
    int pow;
    poly *next;
};
typedef poly* pl;
void init(pl &a)
{
    a = NULL;
}

void create(pl &a,int x,int y)
{
    pl insert = new poly;
    insert->val = x;
    insert->pow = y;
    insert->next = NULL;
    if(a==NULL)
    {
        a = insert;
    }
    else{
        pl p = a;
        while(p->next!=NULL)
        {
            p = p->next;
        }
        p->next = insert;
    }
}


void _input(pl &a)
{
    int n;cout << "How many value : ";cin >> n;
    cout << "Input to the function f(x) " << endl;
    for(int i = 0;i<n;i++)
    { 
    int val;cout << "Input the value : ";cin >> val;
    int pow;cout << "Input the power for x : ";cin >> pow;
    pl insert = new poly;
    insert->val = val;
    insert->pow = pow;
    insert->next = NULL;
    if(a==NULL)
    {
        a = insert;
    }
    else
    {
        pl p = a;
        while(p->next!=NULL)
        {
            p = p->next;
        }
        p->next = insert;
    }
    }
}

void _output(pl a)
{
    cout << "F(x) = ";
    pl p = a;
    int count = 0;
    while(p!=NULL)
    {
        if(count==0 || p->val < 0)
        {
            cout << p->val << "x" << "^" << p->pow << " ";
            count++;
        }
        else if(p->val > 0)
        {
            cout << " + " <<  p->val << "x" << "^" << p->pow << " ";
        }
        p = p->next;
    }
    cout << endl;
}



void delete_zero(pl &a)
{
    pl p = a;
    pl new_list = new poly;init(new_list);
    while(p!=NULL)
    {
        if(p->val!=0)
        {
            create(new_list,p->val,p->pow);
        }
        a = a->next;
        p = p->next;
    }
    a = new_list;
}

int count(pl a)
{
    int cnt = 0;
    pl p = a;
    while(p!=NULL)
    {
        cnt++;
        p = p->next;
    }
    return cnt;
}

pl _addFunc(pl a,pl b)
{
    pl add = new poly;init(add);
    pl fa = a;
    vector<bool> seen_a(count(a),false);
    vector<bool> seen_b(count(b),false);
    int count_a = 0;
    while(fa!=NULL)
    {
        pl fb = b;
        int count_b = 0;
        while(fb!=NULL)
        {
            if(fb->pow==fa->pow && seen_a[count_a]==false && seen_b[count_b]==false)
            {
                create(add,fa->val+fb->val,fa->pow);
                seen_a[count_a] = true;
                seen_b[count_b] = true;
            }
            count_b++;
            fb = fb->next;
        }
        count_a++;
        fa = fa->next;
    }
    count_a = 0;
    int count_b = 0;
    pl re_fa = a,re_fb = b;
    while(re_fa!=NULL)
    {
        if(seen_a[count_a] == false) { create(add,re_fa->val,re_fa->pow);seen_a[count_a]=true;}
        count_a++;
        re_fa = re_fa->next;
    }
    while(re_fb!=NULL)
    {
        if(seen_b[count_b] == false) { create(add,re_fb->val,re_fb->pow);seen_b[count_b]=true;}
        count_b++;
        re_fb = re_fb->next;
    }
    return add;
}

pl _minusFunc(pl a,pl b)
{
    pl add = new poly;init(add);
    pl fa = a;
    vector<bool> seen_a(count(a),false);
    vector<bool> seen_b(count(b),false);
    int count_a = 0;
    while(fa!=NULL)
    {
        pl fb = b;
        int count_b = 0;
        while(fb!=NULL)
        {
            if(fb->pow==fa->pow && seen_a[count_a]==false && seen_b[count_b]==false)
            {
                create(add,fa->val-fb->val,fa->pow);
                seen_a[count_a] = true;
                seen_b[count_b] = true;
            }
            count_b++;
            fb = fb->next;
        }
        count_a++;
        fa = fa->next;
    }
    count_a = 0;
    int count_b = 0;
    pl re_fa = a,re_fb = b;
    while(re_fa!=NULL)
    {
        if(seen_a[count_a] == false) { create(add,re_fa->val,re_fa->pow);seen_a[count_a]=true;}
        count_a++;
        re_fa = re_fa->next;
    }
    while(re_fb!=NULL)
    {
        if(seen_b[count_b] == false) { create(add,-(re_fb->val),re_fb->pow);seen_b[count_b]=true;}
        count_b++;
        re_fb = re_fb->next;
    }
    return add;
}

pl _multiFunc(pl a,pl b)
{
    pl multi = new poly;init(multi);
    pl fa = a;
    while(fa!=NULL)
    {
        pl fb = b;
        while(fb!=NULL)
        {
            create(multi,fa->val*fb->val,fa->pow+fb->pow);
            fb = fb->next;
        }
        fa = fa->next;
    }
    return multi;
}

void _divideFunc(pl a,pl b)
{
    pl divide = new poly;init(divide);
    pl fa = a;
    pl fb = b;
    while(fa->pow >= fb->pow)
    {
        create(divide,fa->val/fb->val,fa->pow-fb->pow);
        pl minus = _multiFunc(divide,b);
        fa = _minusFunc(fa,minus);
        delete_zero(fa);
    }
    cout << "Divide : ";_output(divide);
    cout << "Extra : ";_output(fa);
}

int main()
{
    system("cls");
    pl a = new poly;init(a);
    pl b = new poly;init(b);
    pl add = new poly;init(add);
    pl minus = new poly;init(minus);
    pl multi = new poly;init(multi);
    _input(a);cout << endl;
    _input(b);
    system("cls");
    _output(a);
    _output(b);
    add = _addFunc(a,b);
    minus = _minusFunc(a,b);
    multi = _multiFunc(a,b);
    cout << "Add : ";_output(add);
    cout << "Minus : ";_output(minus);
    cout << "Multiply : ";_output(multi);
    _divideFunc(a,b);
    return 0;
}