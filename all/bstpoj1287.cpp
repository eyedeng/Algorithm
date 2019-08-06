#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
#define M 60
#define INF 10000
struct Edge
{
    int s,e,w;
    Edge(int ss,int ee,int ww):s(ss),e(ee),w(ww) {}
    Edge() {}
    bool operator < (const Edge &a)const
    {
        return a.w > w;
    }
};
//w<a.w
vector<Edge> edges;
//Edge edges[M];
int parent[M];
int getRoot(int a)
{
    if(a!=parent[a])
        parent[a] = getRoot(parent[a]);
    return parent[a];
}
void Merge(int a, int b)
{
    int roota = getRoot(a);
    int rootb = getRoot(b);
    if(roota!=rootb)
        parent[roota] = rootb;
}
int p;
int Kruscal()
{
    sort(edges.begin(),edges.end());
    //sort(edges,edges+r);
    int cnt = 0,minW = 0;
    for(int i=0; i<edges.size(); i++)
    {
        if(getRoot(edges[i].s)!=getRoot(edges[i].e))
        {
            Merge(edges[i].s,edges[i].e);
            minW += edges[i].w;
            cnt++;
        }
        if(cnt==p-1)
            break;
    }
    return minW;
}
int main()
{
    int r;
    int tEdge[M][M];
//    for(int i=0; i<M; i++)
//        for(int j=0; j<M; j++)
//            tEdge[i][j] = INF;
    while(scanf("%d", &p)&&p)
    {
        scanf("%d", &r);
        edges.clear();
        int i,j;
        for(i=0; i<=p; i++)
            parent[i] = i;
        //Edge in;
        int s,e,w;
        for(i=0; i<r; i++)
        {
            //scanf("%d%d%d",&in.s,&in.e,&in.w);
            //edges.push_back(in);
            scanf("%d%d%d",&s,&e,&w);
            edges.push_back(Edge(s,e,w));
            edges.push_back(Edge(e,s,w));

        }
        printf("%d\n",Kruscal());
    }
    return 0;
}
