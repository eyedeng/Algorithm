//leetcode 983 DP Minimum Cost For Tickets
#include <bits/stdc++.h>
using namespace std;
int mincostTickets(vector<int>& days, vector<int>& costs)
{
    const int day[3] = {1,7,30};
    vector<int> dp(days.back()+1,1000000);  // dp[i]:min costs of i-th day
    dp[0] = 0;    // no day no cost
    vector<int> travel(days.back()+1, 0);
    for(int d:days)
        travel[d] = 1;    // 标记为travel

    for(int i=1; i<dp.size(); i++)
    {
        if(!travel[i])
        {
            dp[i] = dp[i-1];  // cost 不变
            continue;
        }
        for(int j=0; j<3; j++)
        {
            //                  第 i-day[j]..i 这些天花 costs[j]
            //cout<<i<<" "<<dp[max(0,i-day[j])]+ costs[j];
            dp[i] = min( dp[i], dp[max(0,i-day[j])]+ costs[j] );
            //cout<<" "<<dp[i]<<endl;
        }
    }
    return dp.back();
}
int main()
{
    vector<int> a = {1,4,6,7,8,20};
    vector<int> b = {2,7,15};
    cout<<mincostTickets(a,b);
    return 0;
}
