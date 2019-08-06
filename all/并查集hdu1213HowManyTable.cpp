#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define M 1010
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
int main()
{
    int T,n,m,a,b;
    cin>>T;
    while(T--)
    {
        scanf("%d%d", &n,&m);
        for(int i=1; i<=n; i++)
            parent[i] = i;
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d", &a,&b);
            Merge(a,b);
        }
        int cnt = 0;
        for(int i=1; i<=n;i++)
            if(getRoot(i)==i)
                cnt++;
        printf("%d\n", cnt);
    }
}
