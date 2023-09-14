#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
struct stack
{
    char data;
    stack *next;
};
typedef stack *st;
void init(st &a)
{
    a = NULL;
}
void push(st &a, char x)
{
    st insert = new stack;
    insert->data = x;
    insert->next = NULL;
    if (a == NULL)
        a = insert;
    else
    {
        insert->next = a;
        a = insert;
    }
}
char top(st a)
{
    st p = a;
    return p->data;
}
void pop(st &a)
{
    st p = a;
    a = a->next;
    delete p;
}
bool empty(st a)
{
    if (a != NULL)
    {
        return false;
    }
    else
        return true;
}

int priority(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/' || c == '%')
    {
        return 2;
    }
    else if (c == '^')
        return 3;
    else
        return 0;
}

void hauTo()
{
    st s = new stack;
    s = NULL;
    string str, str1 = "";
    getline(cin, str);
    int i = 0;
    while (i < str.length())
    {
        char c = str.at(i);
        if (c != ' ')
        {
            if (c - '0' >= 0 && c - '0' <= 9 || isalpha(c))
            {
                str1 += c;
            }
            else
            {
                cout << str1 << " ";
                str1 = "";
                if (c == '(')
                    push(s, c);
                else
                {
                    if (c == ')')
                    {
                        while (top(s) != '(')
                        {
                            cout << top(s) << " ";
                            pop(s);
                        }
                        pop(s);
                    }
                    else
                    {
                        while (!empty(s) && priority(c) <= priority(top(s)))
                        {
                            cout << top(s) << " ";
                            pop(s);
                        }
                        push(s, c);
                    }
                }
            }
        }
        i++;
    }
    if (str1 != "")
        cout << str1 << " ";
    while (!empty(s))
    {
        cout << top(s) << " ";
        pop(s);
    }
}

void hauTo_copy()
{
    st s = new stack; s = NULL;
    string str,str1 = "";
    getline(cin,str);
    int i = 0;
    while(i<str.length())
    {
        char c = str.at(i);
        if(c!=' ')
        {
            if(c-'0' >=0 && c-'0' <=9 || isalpha(c))
            {
                str1+=c;
            }
            else
            {
                cout << str1 << " ";
                str1 = "";
                if(c=='(')
                {
                    push(s,c);
                }
                else
                {
                    if(c==')')
                    {
                        while(top(s)!='(')
                        {
                            cout << top(s) << " ";
                            pop(s);
                        }
                        pop(s);
                    }
                    else
                    {
                        if(!empty(s) && priority(c) <= priority(top(s)))
                        {
                            cout << top(s) << " ";
                            pop(s);
                        }
                        push(s,c);
                    }
                }
            }
        }
        i++;
    }
    if(str1!="")
    {
        cout << str1 << " ";
    }
    while(!empty(s))
    {
        cout << top(s) << " ";
        pop(s);
    }
}


string reverseString(string a)
{
    string str = "";
    for(int i = a.length()-1;i>=0;i--)
    {
        if(a[i]=='(')
        {
            a[i] = ')';
        }        
        else if(a[i]==')')
        {
            a[i] = '(';
        }
        str+=a[i];
    }
    return str;
}

void infix2prefix()
{
    st s = new stack;
    s = NULL;
    string str, str1 = "",result = "";
    getline(cin, str);
    string restr = reverseString(str);
    int i = 0;
    while (i < restr.length())
    {
        char c = restr.at(i);
        if (c != ' ')
        {
            if (c - '0' >= 0 && c - '0' <= 9 || isalpha(c))
            {
                str1 += c;
            }
            else
            {
                result+=(str1);
                //cout << str1 << " ";
                str1 = "";
                if (c == '(')
                    push(s, c);
                else
                {
                    if (c == ')')
                    {
                        while (top(s) != '(')
                        {
                            //cout << top(s) << " ";
                            result+=(top(s));
                            pop(s);
                        }
                        pop(s);
                    }
                    else
                    {
                        while (!empty(s) && priority(c) <= priority(top(s)))
                        {
                            result+=(top(s));
                            //cout << top(s) << " ";
                            pop(s);
                        }
                        push(s, c);
                    }
                }
            }
        }
        i++;
    }
    if (str1 != "")
        result+=(str1);
    while (!empty(s))
    {
        result+=(top(s));
        pop(s);
    }
    cout << reverseString(result) << endl;
} 

void infix2postfix()
{
    st a = new stack;
    a = NULL;
    string str;getline(cin,str);
    string s = "";
    int i = 0;
    while(i<str.length())
    {
        char c = str.at(i);
        if(c!=' ')
        {
            if(c - '0' >= 0 && c-'0' <= 9 || isalpha(c))
            {
                s += c;
            }
            else
            {
                cout << s << " ";
                s = "";
                if(c == '(')
                {
                    push(a,c);
                }
                else
                {
                    if(c==')')
                    {
                        while(top(a)!='(')
                        {
                            cout << top(a) << " ";
                            pop(a);
                        }
                        pop(a);
                    }
                    else{
                        while(!empty(a) && priority(c) <= priority(top(a)))
                        {
                            cout << top(a) << " ";
                            pop(a);
                        }
                        push(a,c);
                    }
                }
            }
        }
        i++;
    }
    if(s!="")
    {
        cout << s << endl;
    }
    while(!empty(a))
    {
        cout << top(a) << " ";
        pop(a);
    }
}

string reverseString_new(string a)
{
    string newa = "";
    for(int i = a.length()-1;i>=0;i--)
    {
        if(a[i] == '(')
        {
            newa = newa + ')';
        }
        else if(a[i]==')')
        {
            newa = newa + '(';
        }
        else
        {
            newa+=a[i];
        }
    }
    return newa;
}

void infix2prefix_new()
{
    st a = new stack;a = NULL;
    string b = "";
    string str;getline(cin,str);
    string rever = reverseString_new(str);
    string s = "";
    int i = 0;
    while(i<rever.length())
    {
        char c = rever.at(i);
        if(c!=' ')
    {
        if(c-'0' >= 0 && c-'0' <= 9 || isalpha(c))
        {
            s+=c;
        }
        else
        {
            b = b + s;
            s = "";
            if(c=='(')
            {
                push(a,c);
            }
            else
            {
                if(c==')')
                {
                    while(top(a)!='(')
                    {
                        b += top(a);
                        pop(a);
                    }
                    pop(a);
                }
                else
                {
                    while(!empty(a) && priority(c) <= priority(top(a)))
                    {
                        b+=top(a);
                        pop(a);
                    }
                    push(a,c);
                }
            }
        }
    }
        i++;
    }
    if(s!="")
    {
        b+=s;
    }
    while(!empty(a))
    {
        b+=top(a);
        pop(a);
    }
    cout << reverseString(b) << endl;
}

int main()
{
    system("cls");
    //hauTo();
    infix2prefix_new();

    return 0;
}