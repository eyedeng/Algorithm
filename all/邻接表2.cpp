#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define For(i, n) for(int i=0; i<n; i++)
#define For1(i, n) for(int i=1; i<=n; i++)
#define M 1000
struct Edge
{
    int to;
    int w;
};
vector<Edge> G[M];
int main()
{
    int n,m;
    cin>>n>>m;  // n¶¥µã m±ß
    int s,e,w;
    Edge edg;
    For(i, m)
    {
        scanf("%d%d%d", &s, &e, &w);
        edg.to = e;
        edg.w = w;
        G[s].push_back(edg);
    }
    For1(i, n)
    {
        int siz = G[i].size();
        For(j, siz)
        {
            printf("%d %d %d\n", i, G[i][j].to, G[i][j].w);
        }
    }
    return 0;
}
/*
4 5
1 4 9
4 3 8
1 2 5
2 4 6
1 3 7
*/
