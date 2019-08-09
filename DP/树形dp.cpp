// luogu1352
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <unordered_map>
using namespace std;
#define ll long long
#define INF 1000000010
#define M 6010
int ri[M];
vector<int> fa[M];
int vis[M];
int not_root[M];
int dp[M][2];  //
int dfs(int root,int flag)
{
    int &ret = dp[root][flag];
    if(ret != 0)
        return ret;
    if(flag)
    {
        ret = ri[root];
        for(int i=0; i<fa[root].size(); i++)
        {
            ret += dfs(fa[root][i], 0);
        }
        return ret;
    }
    else
    {
        for(int i=0; i<fa[root].size(); i++)
        {
            ret += max(dfs(fa[root][i], 0), dfs(fa[root][i], 1));
        }
        return ret;
    }


}
int main()
{
    int N;
    cin>>N;
    int s,f;
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &ri[i]);
    }
    for(int i=1; i<=N-1; i++)
    {
        scanf("%d%d", &s,&f);
        not_root[s] = 1;
        fa[f].push_back(s);
    }
    cin>>s>>f;
    for(int i=1; i<=N; i++)
        if(!not_root[i])
        {
            cout<<max(dfs(i, 0), dfs(i, 1))<<endl;
            //cout<<dp[i][0]<<","<<dp[i][1];
            break;
        }
    return 0;
}

