#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define M 100010
int l_dp[M],l_max[M];
int r_dp[M],r_max[M];
int maxL;
int main()
{
    int N,a[M];
    while(~scanf("%d", &N))
    {
        if(N==0)
            break;
        maxL = -1000000;  // !==0
        for(int i=0; i<N; i++)
            scanf("%d", &a[i]);
        l_dp[0] = l_max[0] = a[0];
        r_dp[N-1] = r_max[N-1] = a[N-1];
        for(int i=1; i<N; i++)
        {
            l_dp[i] = max(l_dp[i-1]+a[i],a[i]);
            l_max[i] = l_dp[i];
            l_max[i] = max(l_max[i],l_max[i-1]);

        }
        for(int i=N-2; i>=0; i--)
        {
            r_dp[i] = max(r_dp[i+1]+a[i],a[i]);
            r_max[i] = r_dp[i];
            r_max[i] = max(r_max[i+1],r_max[i]);
        }
        for(int k=0; k<N-1; k++)
        {

            maxL = max(l_max[k]+r_max[k+1],maxL);
        }
        printf("%d\n",maxL);
    }
    return 0;

}
