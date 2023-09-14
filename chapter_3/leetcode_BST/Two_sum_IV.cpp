#include <iostream>
#include<vector>
#include<set>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
typedef TreeNode* nd;


void addVector(vector<int>& v,nd a)
{
    if(a!=NULL)
    {
        addVector(v,a->left);
        v.push_back(a->val);
        addVector(v,a->right);
    }
}

bool findTarget(nd root,int k)
{
    vector<int> v;
    addVector(v,root);
    for(int i = 0;i<v.size();i++)
    {
        for(int j = i+1;i<v.size();j++)
        {
            if(v[i] + v[j] == k) return true;
        }
    }
    return false;
}

void LRN(nd a)
{
    if(a!=NULL)
    {
        cout << a->val << " ";
        LRN(a->left);
        LRN(a->right); 
    }
}

bool anotherApproach(nd root,int k)
{
    static set<int>s;
    if(root==NULL) return false;
    if(s.find(k-root->val)!=s.end()) return true;
    else
    {
        s.insert(root->val);
    } 
    return (anotherApproach(root->left,k)||anotherApproach(root->right,k));
}

int main()
{
    system("cls");
    nd a = new TreeNode(5);
    a->left = new TreeNode(3);
    a->left->left = new TreeNode(2);
    a->left->left->right = new TreeNode(4);
    a->right = new TreeNode(6);
    a->right->right = new TreeNode(7);
    LRN(a);
    if(anotherApproach(a,9)==true) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}