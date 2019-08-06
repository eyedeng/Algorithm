#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
	int N,m;
	int v[30],w[30];
	int i,j;
	scanf("%d%d", &N,&m);
	for(i=1; i<=m; i++){
		scanf("%d%d",&v[i],&w[i]);
		w[i] *= v[i];
	}
	//printf("jj");
	int dp[50000];
	memset(dp,0,sizeof(dp));
	for(i=1; i<=m; i++)
		for(j=N; j>=v[i] ;j--)
		{
			//printf("1\n");
			if(v[i]<=j){
				dp[j] = max(dp[j],dp[j-v[i]]+w[i]);
				
			}
		}
	printf("%d\n",dp[m]);
}
