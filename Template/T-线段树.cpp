#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 100010
#define ll long long
int arr[MAXN];
struct Node
{
    int l,r;
    int Max;
    int Sum;
//    int mid(){
//        return (l+r)/2;
//    }
} segTree[MAXN*3];
void build(int i,int l,int r)
{
    segTree[i].l = l;
    segTree[i].r = r;
    segTree[i].Max = 0;
    if(l == r)
    {
        segTree[i].Sum = arr[l];
        return;
    }
    int mid = (l+r)/2;
//    int left_node = i<<1;
//    int right_node = (i<<1)|1;
    build(i<<1,l,mid);
    build((i<<1)|1,mid+1,r);

}
void push_up(int i)
{
    segTree[i].Max = max(segTree[i<<1].Max,segTree[(i<<1)|1].Max);
    //segTree[i].Sum = segTree[i<<1].Sum + segTree[(i<<1)|1].Sum;
}
// 更新线段树的第 k 个值为 val
void update(int i,int k,int val)
{
    if(segTree[i].l == k && segTree[i].r == k)
    {
        segTree[i].Max = val;
        return;
    }
    int mid = (segTree[i].l + segTree[i].r)/2;
    if(k <= mid)update(i<<1,k,val);
    else update((i<<1)|1,k,val);
    push_up(i);
}
//查询线段树中 [l,r] 的最大值
int query(int i,int l,int r)
{
    if(segTree[i].l == l && segTree[i].r == r)
        return segTree[i].Max;
    int mid = (segTree[i].l + segTree[i].r)/2;
    if(r <= mid)return query(i<<1,l,r);
    else if(l > mid)return query((i<<1)|1,l,r);
    else return max(query(i<<1,l,mid),query((i<<1)|1,mid+1,r));
}
int main()
{
//    build(1, 1, n);
//    build(0, 0, n-1);
    return 0;
}
