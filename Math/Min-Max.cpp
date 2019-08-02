// 博弈
//https://leetcode.com/problems/predict-the-winner/ 
// code1
bool canWin(int s,int e,bool isTurn1,int sum1,int sum2, vector<int>& nums)  // player1 can win?
{
    if(s == e)
    {
        return sum1 >= sum2;
       /* if(isTurn1)
            return sum1+nums[s] >= sum2;
        else
            return sum1 >= sum2 + nums[s]; */
    }
    if(isTurn1)
    {
        return canWin(s+1,e,!isTurn1,sum1+nums[s],sum2, nums)
             | canWin(s,e-1,!isTurn1,sum1+nums[e],sum2, nums);
    }
    else
    {
        return canWin(s+1,e,!isTurn1,sum1,sum2+nums[s], nums)
             & canWin(s,e-1,!isTurn1,sum1,sum2+nums[e], nums);
    }
}
bool PredictTheWinner(vector<int>& nums)
{
    return canWin(0, nums.size()-1, 1,0,0, nums);
}
//code2
int getScore(int s,int e,vector<int>& nums) // 相对得分
{
    if(s == e)
        return nums[s];
    return max(nums[s] - getScore(s+1, e, nums),  // my score - your score
               nums[e] - getScore(s, e-1, nums) );
}
bool PredictTheWinner(vector<int>& nums)
{
    return getScore(0, nums.size()-1, nums) >= 0;
}
//code3 记忆化
int mem[20][20] = {0};
int getScore(int s,int e,vector<int>& nums) // 相对得分
{
    int &ret = mem[s][e];
    if(ret != 0)
        return ret;
    if(s == e)
        return ret = nums[s];
    return ret = max(nums[s] - getScore(s+1, e, nums),  // my score - your score
               nums[e] - getScore(s, e-1, nums) );
}
bool PredictTheWinner(vector<int>& nums)
{
    return getScore(0, nums.size()-1, nums) >= 0;
}
// leetcode stone-game
// DP 
int dp[500][500] = {0};  // dp[i][j]: max score of piles[i..j]
bool stoneGame(vector<int>& piles)
{
    int n = piles.size();
    for(int i=0; i<n; i++)  // 区间长度=1
        dp[i][i] = piles[i];
    for(int len=2,i,j; len<=n; len++)  // 枚举区间长度
    {
        for(i=0; i<n-len+1 ; i++)
        {
            j = i+len-1; // j<n --> i<?
            dp[i][j] = max(piles[i]-dp[i+1][j],
                           piles[j]-dp[i][j-1] );  // 自底向上: len <-- len-1
        }
    }
    return dp[0][n-1]>0;
}
// 降维(DP优势) len只与len-1有关,不必显式表达j
int dp[500] = {0};  // dp[i]: max score of piles[i..i+len-1]
bool stoneGame(vector<int>& piles)
{
    int n = piles.size();
    for(int i=0; i<n; i++)  // 区间长度=1
        dp[i] = piles[i];
    for(int len=2,i; len<=n; len++)  // 枚举区间长度
    {
        for(i=0; i<n-len+1 ; i++)
        {
            //j = i+len-1;
//            dp[i][j] = max(piles[i]-dp[i+1][j],
//                           piles[j]-dp[i][j-1] );
            dp[i] = max(piles[i]-dp[i+1] , piles[i+len-1]-dp[i]);
        }
    }
    return dp[0]>0;
}
// stone-game-ii
#define INF 10000000
int len;
int mem[100][100];
int total[100];
int getScore(int M,int s,vector<int>& piles)
{
    //cout<<M<<"-"<<s<<endl;
    if(s == len)
        return 0;
    int &ret = mem[M][s];
    if(ret != INF)
        return ret;
    //cout<<M<<"-"<<s<<endl;
    int ans = -INF,sum = 0;
    if(s+2*M >= len)  // 直接全部取走 剪枝
        return ret = total[len-1]-total[s-1];
    for(int x=1; x<=2*M && s<len; x++)
    {
        sum += piles[s++];
        ans = max(ans, sum-getScore(max(M,x),s,piles) );
    }
    return ret = ans;
}
// n+score + n = total
int stoneGameII(vector<int>& piles)
{
    len = piles.size();
    for(int i=0; i<100; i++)
        for(int j=0; j<len; j++)
            mem[i][j] = INF;
    total[0]=piles[0];
    for(int i=1; i<len; i++)  // 前缀和预处理 优化
        total[i] = total[i-1]+piles[i];
    int score = getScore(1, 0, piles);
    return (total[len-1] - score) / 2 + score;
}


