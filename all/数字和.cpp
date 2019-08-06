#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

bool f(int *a,int n,int s)
{
	int i=n-1;
	if(s==0)
		return 1;
	else if(i==0)
		return a[0]==s;
	else if(a[i]>s)
		return f(a,i-1,s);
	else
	{
		return f(a,i-1,s-a[i]);
		return f(a,i-1,s);
	}
}

int main()
{
	int n;
	int a[20];
	int s;
	int dp[20][20];
	memset(dp,0,sizeof(dp)); 
	scanf("%d%d",&n,&s);
	int i,j;
	for(i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
/*	for(i=0; i<n; i++)
	{
		if(a[i]==s)
			dp[0][i] = 1; 
		dp[i][0] = 1;	
	}
	for(i=1; i<n; i++)
		for(j=1; j<=s; j++)
		{
			int c = s-a[i];
			if(c<0){
				if(dp[i-1][j])
					dp[i][j] = 1;
			}	
			else if(dp[i-1][j] || dp[i-1][c])
				dp[i][j] = 1;
		}

	for(i=0; i<n; i++)
	{
		for(j=0; j<=s; j++)
			printf("%d",dp[i][j]);
		printf("\n");
	}		
*/	
	printf("%d\n",f(a,n,s));
	return 0;
}
/*
6 9
3 34 4 12 5 2
*/
