#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <ctime>
using namespace std;
#define For(i, n) for(int i=0; i<n; i++)
#define For1(i, n) for(int i=1; i<=n; i++)
#define LL long long
typedef struct Node * BT;
struct Node
{
    int val;
    BT left;
    BT right;
};
void show(BT &bt)
{
    if(bt)
    {
        show(bt->left);
        cout << bt->val << " ";
        show(bt->right);
    }
}
void insert_(BT &bt,int v)
{
    if(!bt)
    {
        BT p = new Node;
        p->val = v;
        p->left = p->right = NULL;
        bt = p;
        return;
    }
    if(v > bt->val)
    {
        insert_(bt->right, v);
    }
    else if(v < bt->val)
    {
        insert_(bt->left, v);
    }
}
BT find_(BT &bt, int v)
{
    if(!bt)
    {
        return NULL;
    }
    if(v > bt->val)
    {
        return find_(bt->right, v);
    }
    else if(v < bt->val)
    {
        return find_(bt->left, v);
    }
    else
        return bt;

}
BT delete_(BT & bt, int v)
{
    if(!bt)
        printf("no\n");
    else if(v > bt->val)
    {
        bt->right = delete_(bt->right, v);
    }
    else if(v < bt->val)
    {
        bt->left = delete_(bt->left, v);
    }
    else
    {
        if(bt->left==NULL && bt->right==NULL)
        {
            return NULL;
        }
        else if(bt->left)
        {
            return bt->left;
        }
        else if(bt->right)
        {
            return bt->right;
        }
        else
        {
            BT t = bt->left;  // 找左子树最大值
            BT pre = bt;
            while(t->right)
            {
                pre = t;
                t = t->right;
            }
            bt->val = t->val;
            if(pre == bt)
                bt->left = t->left;
            else
                pre->right = t->left;
        }
    }
    //cout << "gggggg\n";
    return bt;
}
int main()
{
    BT b = NULL;
    int n,v;
    cin >> n;
    For(i, n)
    {
        cin >> v;
        insert_(b,v);
    }
    show(b);cout << endl;
    BT db = delete_(b, 5);
    show(db);
}
