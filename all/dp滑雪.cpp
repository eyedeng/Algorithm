#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
struct Node
{
    int x,y,h;
}node[10010],tnode[10010];
int dirx[]={1,0,-1,0};
int diry[]={0,1,0,-1};
bool comp(const Node &a,const Node &b)
{
    return a.h<b.h;
}
int main()
{
    int r,c,h[110][110],L[110][110];
    cin>>r>>c;
    int i,j,p=0;
    for(int i=0; i<r; i++)
        for(j=0; j<c; j++)
        {
            scanf("%d", &h[i][j]);
        //    L[i][j] = 0;
            L[i][j] = 1;
            node[p].x = i;
            node[p].y = j;
            node[p++].h = h[i][j];
        }
    sort(node,node+p,comp); //对当前的高度由小到大排序来保证访问到的结点没有被其它结点访问过
    //（因为高度小的结点无法访问高度大的结点）。

    for(i=0; i<p; i++) //人人为我
    {
        int l = 1;
        for(j=0; j<4; j++)
        {
            tnode[i].x = node[i].x + dirx[j];
            tnode[i].y = node[i].y + diry[j];
            if(tnode[i].x>=0 &&tnode[i].y>=0 &&
               tnode[i].x<r &&tnode[i].y<c &&
               h[tnode[i].x][tnode[i].y]<node[i].h){
                   l = max(l,L[tnode[i].x][tnode[i].y]+1);
                   // printf("(%d,%d)=%d\n",tnode[i].x+1,tnode[i].y+1,l);
               }

        }
        L[node[i].x][node[i].y] = l;

    }
    int Max = 1;
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            Max = max(Max,L[i][j]);
           // cout<<L[i][j]<<" ";
        }
       // cout<<endl;
    }


    cout<<Max<<endl;
    return 0;
}
