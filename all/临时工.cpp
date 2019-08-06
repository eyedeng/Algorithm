#include <stdio.h>
#include <algorithm>
//#include <bits/stl_algobase.h>
using namespace std; 
int dp[10];
int q[8][2];

int pre(int i)
{
	for(int j=i-1; j>0; j--)
	{
		if(q[j][1]<=q[i][0])
			return j;
	}
	return 0;
}

int main()
{
	int v[8];
	int i,j;
	for(i=1; i<=8; i++)
		scanf("%d%d%d",&v[i],&q[i][0],&q[i][1]);
	dp[0] = 0;
	dp[1] = v[1];
	for(i=2; i<=8; i++)
	{
		dp[i] = max(dp[i-1],v[i]+dp[pre(i)]);
		
	}
	for(i=1; i<=8; i++)
	printf("%d\n",dp[i]);	
}
