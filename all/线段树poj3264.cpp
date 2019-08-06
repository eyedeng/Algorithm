#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 0xffffff0;
int minV = INF;
int maxV = -INF;
int h[200010];
struct Node
{
    int left,right;
    int minV,maxV;
    int mid(){
        return (left+right)/2;
    }
    Node():minV(INF),maxV(-INF){};
};
Node tree[4*200001];

void build_treee(int root,int l,int r)
{
    tree[root].left = l;
    tree[root].right = r;
    //tree[root].minV = INF;
    //tree[root].maxV = -INF;
    if(r!=l)
    {
        build_treee(2*root,l,(l+r)/2);
        build_treee(2*root+1,(l+r)/2+1,r);
        tree[root].maxV = max(tree[2*root].maxV,tree[2*root+1].maxV);
        tree[root].minV = min(tree[2*root].minV,tree[2*root+1].minV);

    }
    else
    {
        tree[root].maxV = tree[root].minV = h[r];
    }
}

void query(int root,int s,int e)
{
    if(tree[root].minV>=minV && tree[root].maxV<=maxV)
        return;                                    // ¼ôÖ¦
    if(tree[root].left==s && tree[root].right==e)
    {
        maxV = max(tree[root].maxV,maxV);
        minV = min(tree[root].minV,minV);
        return;
    }
    if(e<=tree[root].mid())
        query(2*root,s,e);
    else if(s>tree[root].mid())
        query(2*root+1,s,e);
    else
    {
        query(2*root,s,tree[root].mid());
        query(2*root+1,tree[root].mid()+1,e);
    }
}
int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=1; i<=n; i++)
        scanf("%d", &h[i]);
    build_treee(1,1,n);

   for(int i=1; i<=q; i++)
    {
        int s,e;
        scanf("%d%d", &s,&e);
        minV = INF;
        maxV = -INF;
        query(1,s,e);
        printf("%d\n",maxV-minV);
    }
    return 0;
}

