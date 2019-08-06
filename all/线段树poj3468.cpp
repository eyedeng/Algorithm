#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define M 100010
#define ll long long
ll a[M];
struct Node
{
    ll left,right;
    ll nSum; // 原来的和
    ll inc;  //增量c的累加
             // 区间和：nSum  +  inc* (r-l+1)(个数)
//    ll mid(){
//        return (left+right)/2;
//    }
};
Node tree[3*M];

void build(int root, ll l, ll r)
{
    tree[root].left = l;
    tree[root].right = r;
    tree[root].inc = 0;
    if(l==r){
        tree[root].nSum = a[l];
        return;
    }
    ll mid = (l+r)/2;
    build(2*root,l,mid);
    build(2*root+1,mid+1,r);
    tree[root].nSum = tree[2*root].nSum+tree[2*root+1].nSum;
}
void add(int root, ll l,ll r,ll v)
{
    if(tree[root].left==l && tree[root].right==r)  // inc不分下去了
    {
        tree[root].inc += v;
        return;
    }
    tree[root].nSum += v*(r-l+1);
    int mid = (tree[root].left+tree[root].right) / 2;
    if(r<=mid)
        add(2*root,l,r,v);
    else if(l>mid)
        add(2*root+1,l,r,v);
    else
    {
        add(2*root,l, mid,v);
        add(2*root+1,mid+1,r,v);
    }
}
ll Query(int root,ll l,ll r)
{
    if(tree[root].left==l &&tree[root].right==r)
        return tree[root].nSum+tree[root].inc*(r-l+1);

    int mid = (tree[root].left+tree[root].right) / 2;
    //                        not r              not l
    tree[root].nSum += ( tree[root].right - tree[root].left + 1 )*tree[root].inc;    // 若区间不一致,inc分下去
    add(2*root,   tree[root].left,   mid, tree[root].inc);
    add(2*root+1, mid+1,tree[root].right, tree[root].inc);
    tree[root].inc = 0;

    if(r<=mid)
        return Query(2*root,l,r);
    else if(l>mid)
        return Query(2*root+1,l,r);
    else
    {
        return Query(2*root,l,mid) + Query(2*root+1,mid+1,r);
    }

}
int main()
{
    ll n,q,A,B,v;
    cin>>n>>q;
    for(int i=1; i<=n; i++)
        scanf("%lld",&a[i]);
    build(1,1,n);
    while(q--)
    {
        char c;
        cin>>c;
        if(c=='Q')
        {
            scanf("%lld%lld",&A,&B);
            printf("%I64d\n", Query(1, A, B));
        }
        else
        {
            scanf("%lld%lld%lld",&A,&B,&v);
            add(1, A, B, v);
        }
    }
    return 0;
}
