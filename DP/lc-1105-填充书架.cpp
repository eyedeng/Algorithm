//leetcode 1105 DP 填充书架
#include <bits/stdc++.h>
using namespace std;

int minHeightShelves(vector<vector<int>>& books, int shelf_width)
{
    int len = books.size();
    vector<int> dp(len, 1000000);  // dp[i]:放置books[0]..books[i]的min height
    int sum_h = 0;
    int h = 0;
    int sum_w = 0;

     // [0 ... i-1 i ...j]
    for(int j=0; j<len; j++)  // 固定j
    {
        h = 0;
        sum_w = 0;
        for(int i=j; i>=0; i--)  // 枚举i
        {
            sum_w += books[i][0];
            if(sum_w > shelf_width)
                break;
            h = max(h, books[i][1]);
            //             dp[i-1]:已解决部分  h:可解部分的解（另起一层的高度）
            dp[j] = min(dp[j], (i==0? 0:dp[i-1]) + h );
        }
    }
    return dp[len-1];
}
int main()
{
    vector<vector<int>> v ={{1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}};
    cout<<minHeightShelves(v, 4);
    return 0;
}
