//优先队列 邻接表 (未完成)
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
#define INF 10000
#define M 30
int n;
//int gra[M][M];
struct Edge
{
    int v; //端点
    int w; //权值
    Edge(int v_=0,int w_=INF):v(v_),w(w_){}
    bool operator < (const Edge & e)const
    {
        return e.w<w;
    }
};
vector< vector<Edge> >gra(M);
void prim()
{
    int vis[M]={0},dist[M];
    int i,j,minSum=0,index;
    priority_queue<Edge> pq;
    vis[0] = 1;
    for(i=0; i<n; i++)
        dist[i] = gra[0][i];
    for(i=1; i<n; i++)
    {
        int mincost = INF;
        for(j=1; j<n; j++)
        {
            if(!vis[j] && dist[j]<mincost){
                mincost = dist[j];
                index = j;
            }
        }
        vis[index] = 1;
        minSum += mincost;
        for(j=1; j<n; j++)
            if(!vis[j] && dist[j]>gra[index][j])
                dist[j] = gra[index][j];
    }
    printf("%d\n",minSum);
}
int main()
{

   char s[2],e[2];
   int m,q;

   while(scanf("%d", &n)&&n)
   {
       int i,j;
       for(i=0; i<n; i++)
            gra[i].clear();

       for(i=0; i<n-1; i++)
       {
           scanf("%s%d",s,&m);
           for(j=0; j<m; j++)
           {
               scanf("%s%d", e,&q);
               //gra[s[0]-'A'][e[0]-'A'] = gra[e[0]-'A'][s[0]-'A'] = q;
               gra[s[0]-'A'].push_back(Edge(e[0]-'A',q));
               gra[e[0]-'A'].push_back(Edge(s[0]-'A',q));
           }
       }
       prim();
   }
   return 0;
}
