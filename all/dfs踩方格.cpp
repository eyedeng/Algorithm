#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int mapp[25][45];
int vis[25][45];
int dfs(int n,int i,int j)
{
    if(n==0)
        return 1;
    vis[i][j] = 1;
    int ways = 0;
    if( !vis[i][j-1] )
        ways += dfs(n-1,i,j-1);
    if( !vis[i][j+1] )
        ways += dfs(n-1,i,j+1);
    if( !vis[i+1][j] )
        ways += dfs(n-1,i+1,j);
    vis[i][j] = 0;
    return ways;
}
int main()
{
    int n;
    cin>>n;
    cout<<dfs(n,1,20)<<endl;
}
