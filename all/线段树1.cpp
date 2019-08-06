#include <stdio.h>
#include <iostream>
using namespace std;
const int maxind = 256;
int a[maxind];
struct Tree
{
    int left,right;
    long long sum;
} tr[maxind<<2]; // *4

void build(int node,int left,int right)
{
    tr[node].left = left;
    tr[node].right = right;
    if(left==right){
        tr[node].sum = a[left];
        printf("[%d,%d],%d,%d\n",tr[node].left,tr[node].right,node,tr[node].sum); //node=4,5,6,7
        printf("[%d,%d],%d,%d\n",tr[node].left,tr[node].right,tr[node].sum,node); //node=0
    }
    else
    {
        long long mid = (tr[node].left+tr[node].right)>>1; // /2
        build(node<<1,left,mid);
        build((node<<1)+1,mid+1,right); //(x<<y)+z
        tr[node].sum = tr[node<<1].sum + tr[(node<<1)+1].sum;
    }
}
int search_sum(int node,int l,int r)
{
    if(tr[node].left>=l && tr[node].right<=r)
        return tr[node].sum;
    else
    {
        int mid = (tr[node].left+tr[node].right)>>1;
        if(r<=mid)
            return search_sum(2*node,l,r);
        else if(l>mid)
            return search_sum(2*node+1,l,r);
        else
            return search_sum(2*node,l,r)+search_sum(2*node+1,l,r);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    build(1,1,n); // root=1
    cout<<endl;
    for(int i=1; i<=7; i++)
    {
        printf("[%d,%d] %d  ",tr[i].left,tr[i].right,tr[i].sum);
        if(i==1 || i==3 || i==7)
            cout<<endl;
    }
    int l,r;
    while(cin>>l>>r)
        cout<<search_sum(1,l,r)<<endl;
    return 0;
}
/*
4
7 6 3 5
*/
