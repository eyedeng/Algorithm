// leetcode 169 majority element 随机化
int majorityElement(vector<int>& nums)
{
    srand(time(NULL));
    int n = nums.size();
    while(1)
    {
        int idx = rand() % n; // 概率上,期望选取次数<=2
        int major = nums[idx];
        int cnt = 0;
        for(int i:nums)
            if(i == major)
            {
                cnt++;
                if(cnt > n/2)
                    return major;
            }
    }
    return 0;
}