#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

typedef ListNode* nd;

void deleteNode(nd &a,nd x)
{
    if(a==NULL) return;
    else{
        nd p = a;
        nd q = NULL;
        while(p!=NULL && p!=x)
        {
            q = p;
            p = p->next;
        }
        if(q==NULL)
        {
            a = a->next;
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

nd deleteDuplicates(nd head)
{
    unordered_map<int,int> mp;
    nd p = head;
    while(p!=NULL)
    {
        mp[p->val]++;
        p = p->next;
    }
    nd q = head;
    while(q!=NULL)
    {
        if(mp[q->val] >= 2)
        {
            nd erase = q;
            q = q->next;
            mp[q->val]--;
            deleteNode(head,erase);
        }
        else q = q->next;
    }
    return head;
}

nd anotherApproach(nd head)
{
    nd temp = head;
    nd curr = temp;
    while(curr&&curr->next)
    {
        if(curr->val == curr->next->val)
        {
            nd erase = curr;
            curr = curr->next;
            deleteNode(head,erase);
        }
        else curr = curr->next;
    }
    return head;
}

int main()
{
    system("cls");
    nd a = new ListNode(1);
    a->next = new ListNode(1);
    a->next->next = new ListNode(2);
    nd newlist = new ListNode;newlist = NULL;
    newlist = anotherApproach(a);
    nd p = newlist;
    while(p!=NULL)
    {
        cout << p->val << " ";
        p = p->next;
    }
    return 0;
}