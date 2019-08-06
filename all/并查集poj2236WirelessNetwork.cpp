#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define M 1010
#define EPS 1e-6
struct Node
{
    int x,y;
};
Node node[M];
int parent[M];
int dis[M][M];
int repaired[M];  //修复了（并过）
double dist( Node a,Node b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int getRoot(int a)
{
    if(a!=parent[a])
        parent[a] = getRoot(parent[a]);
    return parent[a];
}
void Merge(int a,int b)
{
    int roota = getRoot(a);
    int rootb = getRoot(b);
    if(roota!=rootb)
        parent[roota] = rootb;

}
int Quary(int a,int b)
{
    return getRoot(a)==getRoot(b);
}
int main()
{

    int n,d;
    scanf("%d%d", &n, &d);
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d", &node[i].x,&node[i].y);
        parent[i] = i;
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(dist(node[i],node[j])<=d+EPS)
                dis[i][j] = 1; //可连接

    char s[2];
    int p,q;
    while(~scanf("%s", s))
    {
        if(s[0]=='O')
        {
            scanf("%d", &p);
            if(!repaired[p])
            {
                for(int i=1; i<=n; i++)
                    if(repaired[i]&&dis[p][i]) //
                        Merge(p,i);
                repaired[p] = 1;
            }
        }
        else
        {
            scanf("%d%d", &p,&q);
            if(Quary(p,q))
                printf("SUCCESS\n");
            else
                printf("FAIL\n");
        }
    }
}
