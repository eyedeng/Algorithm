#include<iostream>
#include<cstdio>
#include<algorithm>
#include <queue>
#include <vector>
using namespace std;
#define M 30010
#define INF 100000;
struct Node
{
    int k; //÷’µ„
    int w; //»®÷µ
};
bool operator < (const Node & d1,const Node & d2){
    return d1.w > d2.w;
}
priority_queue<Node> pq;
bool isUsed[M];
vector<vector<Node> > v;

int main()
{
    int t,n,a,b,c;
    int i,j,k;
    Node p;
    scanf("%d%d", &t, &n);
    //v.clear();
    v.resize(n+1);
    for(i=1; i<=t; i++)
     {
        scanf("%d%d%d", &a,&b,&c);
        p.k = b;
        p.w = c;
        v[a].push_back(p);
        p.k = a;
        p.w = c;
        v[b].push_back(p);
     }
     p.k = 1;
     p.w = 0;
     pq.push(p);
     while(!pq.empty())
     {
         p = pq.top();
         pq.pop();
         if(isUsed[p.k])
            continue;
         isUsed[p.k] = 1;
         if(p.k == n)
            break;
         for( i=0, j=v[p.k].size(); i<j; i++)
         {
             Node q;
             q.k = v[p.k][i].k;
             if(isUsed[q.k])
                continue;
             q.w = p.w + v[p.k][i].w;
             pq.push(q);
         }
     }
     printf("%d\n",p.w);
     return 0;
}
