#include<iostream>
#include<vector>
using namespace std;
#define MAX 100
void init(int a[],int &front,int &rear)
{
    front = -1;
    rear = -1;
}
int push_TT(int a[],int &front,int &rear,int x)
{
    if(rear - front==MAX-1) return 0; // queue full
    else
    {
        if(front==-1) front = 0;// queue is empty
        if(rear == MAX - 1) // overflow
        {
            for(int i = front;i<=rear;i++)
            {
                a[i-front] = a[i];
            }
            rear = MAX - 1 - front;
            front = 0;
        }
        a[++rear] = x;
        return 1;
    }
}

int pop_TT(int a[],int &front,int &rear,int x)
{
    if(front==-1) return 0;
    else{
        x = a[front++];
        if(front>rear)
        {
            front = -1;
            rear = -1;
        }
        return 1;
   }
}
void push_Loop(int a[],int &front,int &rear,int x)
{
    if((rear-front==MAX - 1)||(rear - front==-1)) return 0;
    else 
    {
        if(front==-1)
        {
            front = 0;
        }
        if(rear==MAX-1) rear = -1;
        a[++rear] = x;
        return 1;
    }
}

void pop_loop(int a[],int &x)
{
    if(front!=-1)
    {
        x = a[front];
        if(front==rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
            if(front>MAX-1) front = 0;
        }
        return 1;
    }
    return 0;
}
int main()
{
    system("cls");
    int a[MAX];
    vector<int>v = {1,2,3,4,5,6,7};
    int front,rear;
    init(a,front,rear);
    for(auto x : v)
    {
        push_TT(a,front,rear,x);
    }
    for(int i = front;i<=rear;i++)
    {
        cout << a[i] << " ";
    }
    int x;
    pop_TT(a,front,rear,x);
    cout << endl;
    cout << front;
    cout << endl;
    for(int i = front;i<=rear;i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}