// lc 1000 石子合并
// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1000-minimum-cost-to-merge-stones/
int mergeStones(vector<int>& stones, int K)
{
    int n = stones.size();
    if((n-1)/(K-1) != 0)
        return -1;
    int dp[40][40][40]; // dp[i][j][k] : stones[i..j]分k堆min cost
    memset(dp, 127, sizeof(dp));
    for(int i=0; i<n; i++)
        dp[i][i][1] = 0;
    int sum[40];
    sum[0] = 0;
    for(int i=0; i<n; i++)
        sum[i+1] = stones[i] + sum[i];


    for(int l=2; l<=n; l++)  // 子问题规模 l:堆数
        for(int i=0; i<=n-l; i++)  // 起点
        {
            int j=i+l-1;  // 终点
            for(int k=2; k<=K; k++)  // i..j k堆
            {
                for(int m=i; m<j; m+=K-1)  // 分割点
                {
                    //                                 左边1堆
                    dp[i][j][k] = min(  dp[i][j][k],dp[i][m][1]+dp[m+1][j][k-1] );
                }
            }
            //               最优
            dp[i][j][1] = dp[i][j][K] + sum[j+1]-sum[i];  // K -> 1 堆
        }
    return dp[0][n-1][1];
}
