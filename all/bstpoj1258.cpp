#include<iostream>
#include<cstdio>
#include<algorithm>
#include <vector>
using namespace std;
#define M 105
#define INF 1<<30
int N;
int gra[M][M];
int prim()
{
    int vis[M]={0},dist[M];
    int i,j,minSum=0,index;
    vis[0] = 1;                //从0点出发
    for(i=0; i<N; i++)
        dist[i] = gra[0][i];   //dist: 0点扩展
    for(i=1; i<N; i++)
    {
        int mincost = INF;
        for(j=1; j<N; j++)
        {
            if(!vis[j] && dist[j]<mincost){ //找最小距离
                mincost = dist[j];
                index = j;
            }
        }
        vis[index] = 1;
        minSum += mincost;
        for(j=1; j<N; j++) //更新最短距离
            if(!vis[j] && dist[j]>gra[index][j]) //index点扩展的 与 原来的
                dist[j] = gra[index][j];        // 比较dist
    }
    return minSum;
}

struct Edge
{
    int s,e,w;
    Edge(int ss,int ee,int ww):s(ss),e(ee),w(ww){}
    Edge(){}
    bool operator < (const Edge &a)const
    {
        return a.w > w;
    }
};
vector<Edge> edges;
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
int kruscal()
{
     sort(edges.begin(),edges.end());
     int cnt=0,minSum=0;
     for(int i=0; i<edges.size(); i++)
     {
         if(getRoot(edges[i].s)!=getRoot(edges[i].e))
         {
             Merge(edges[i].s,edges[i].e);
             minSum += edges[i].w;
             cnt++;
         }
         if(cnt==N-1)
            break;
     }
     return minSum;
}
int main()
{

    while(~scanf("%d", &N))
    {
//        for(int i=0; i<N; i++)
//            for(int j=0; j<N;j++)
//                scanf("%d", &gra[i][j]);
//        printf("%d\n",prim());
        edges.clear();
        for(int i=0; i<N; i++)
            parent[i] = i;
        int w;
        for(int i=0; i<N; i++)
            for(int j=0; j<N;j++)
            {
                scanf("%d", &w);
                edges.push_back(Edge(i,j,w));
            }
        printf("%d\n",kruscal());
    }
    return 0;
}
