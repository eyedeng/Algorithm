1. 给定nums数组，求最长上升子序列
### 记忆化递归
```cpp
// memorized recursion leetcode 300
#include <bits/stdc++.h>
using namespace std;

vector<int> cache;
int LIS_(vector<int>& nums, int index)  // len(以nums[index]结尾的LIS)
{
    int& ret = cache[index];

    if(ret != 1)
        return ret;

    if(index == 0)
        return 1;

    for(int i=0; i<index; i++)
    {
        if(nums[i] < nums[index])
        {
            ret = max(ret, LIS_(nums, i)+1);
        }
    }
    return ret;
}
int LIS(vector<int>& nums)
{
    cache = vector<int>(nums.size(), 1);  // init len = 1
    int max_len = 0;
    for(int i=0; i<nums.size(); i++)
    {
        max_len = max(max_len, LIS_(nums, i));
    }
    return max_len;
}
```
### DP递推
递推式：dp[i]=max(dp[i], dp[j]+1) (0<=j< i, a[j]< a[i])
```cpp
int DP(vector<int>& nums)
{
    vector<int> dp(nums.size(),1);  // dp[i]:len(以nums[i]结尾的LIS)
    int max_len = 0;
    for(int i=0; i<nums.size(); i++)
    {
        for(int j=0; j<i; j++)
        {
            if(nums[j] < nums[i])
            {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        max_len = max(max_len, dp[i]);
    }
    return max_len;
}
```
### O(n^2) -> O(nlgn) 贪心二分
_占位符_
```cpp
```
2. 给定nums数组，求最长上升子序列个数
### 记忆化递归
```cpp
//leetcode 673 NLIS time:1600ms!!! 需要改进
#include <bits/stdc++.h>
using namespace std;

vector<int> cache;
vector<int> cache_cnt;
int LIS_(vector<int>& nums, int index)  // len(以nums[index]结尾的LIS)
{
    int& ret = cache[index];

    if(ret != 1)
        return ret;

    if(index == 0)
        return 1;

    for(int i=0; i<index; i++)
    {
        if(nums[i] < nums[index])
        {
            ret = max(ret, LIS_(nums, i)+1);
        }
    }
    return ret;
}
int LIS(vector<int>& nums)
{
    cache = vector<int>(nums.size(), 1);
    int max_len = 0;
    for(int i=0; i<nums.size(); i++)
    {
        max_len = max(max_len, LIS_(nums, i));
    }
    return max_len;
}

int cnt(vector<int>& nums, int index)  // number(以nums[index]结尾的LIS)
{
    int& ret = cache_cnt[index];

    if(index == 0)
        return 1;
    if(ret != 1)
        return ret;

    int sum = 0;
    for(int i=0; i<index; i++)
    {
        if(nums[i]<nums[index] && cache[i]==cache[index]-1)
            sum += cnt(nums, i);
    }
    if(sum == 0)
        return ret = 1;
    else
        return ret = sum;
}
int findNumberOfLIS(vector<int>& nums)
{
    int max_len = LIS(nums);
    int sum = 0;
    cache_cnt = vector<int>(nums.size(), 1);

    for(int i=0; i<nums.size(); i++)
    {
        if(cache[i] == max_len)
        {
            sum += cnt(nums, i);
        }
    }
    return sum;
}
```
![p](https://zxi.mytechroad.com/blog/wp-content/uploads/2017/09/673-ep56-2.png)
### DP递推
```cpp
// 48ms!!!
int DP2(vector<int> nums)
{
    vector<int> len(nums.size(), 1);
    vector<int> cnt(nums.size(), 1);
    int max_len = 0;
    for(int i=0; i<nums.size(); i++)
    {
        for(int j=0; j<i; j++)
        {
            if(nums[j] < nums[i])
            {
                if(len[j] > len[i]-1)  // 没连起来
                {
                    len[i] = len[j] + 1;  // 连接
                    cnt[i] = cnt[j];       // 一脉相承
                }else if(len[j] == len[i]-1)  // 已经连着
                {
                    cnt[i] += cnt[j];     // 加上这一支
                }
                len[i] = max(len[i], len[j]+1);
            }
        }
        max_len = max(max_len, len[i]);
    }
    int max_num = 0;
    for(int i=0; i<nums.size(); i++)
    {
        if(len[i] == max_len)
            max_num += cnt[i];
    }
    return max_num;
}
```


