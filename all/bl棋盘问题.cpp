#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int visR[10];
int visC[10];
char ma[10][10];
int step;
int n,k;
int ans;
void dfs(int step,int col)
{
    if(step==0){
        ans++;
        return;
    }
    if(col>=n)
        return;
    // 按列（大）行（小）搜索
    for(int i=0; i<n; i++)
    {
        if(ma[i][col]=='#' && !visR[i] && !visC[col]){
            visR[i] = visC[col] = 1;
            dfs(step-1,col+1);
            visR[i] = visC[col] = 0;
        }
    }
    dfs(step,col+1); //此列无

}
int main()
{
    while(scanf("%d%d", &n,&k) && k!=-1)
    {
        ans = step = 0;
        memset(visR,0,sizeof(visR));
        memset(visC,0,sizeof(visC));
        int C = 0;
        for(int i=0; i<n; i++)
            scanf("%s", ma[i]);
        dfs(k,0);
        printf("%d\n",ans);
    }
    return 0;
}
