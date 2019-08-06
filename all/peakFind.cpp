int bin_find(vector<int> nums, int left,int right)
    {
        if(left == right)
            return left;

        int n = (left+right)/2;

        if(n == 0)
            return nums[0] > nums[1]? 0:1;

        if(nums[n] <nums[n-1])
            return bin_find(nums, left, n-1);
        else if(nums[n] < nums[n+1])
            return bin_find(nums, n+1, right);
        else
            return n;
    }

int findPeakElement(vector<int>& nums) {
    if(nums.size() == 1)
        return 0;
    if(nums.size() == 2)
        return nums[0]>nums[1]?0:1;
    return bin_find(nums, 0, nums.size()-1);
}
struct loc
{
    int i,j;
    loc(int ii,int jj)
    {
        i = ii;
        j = jj;
    }
};
loc bin_find2D(vector<vector<int> >nums, int n, int m)
{
    int i = 0,j = m/2;

    for(int k=1; k<n; k++)
        if(nums[k][j] > nums[i][j])
            i = k;
    if(nums[i][j] < nums[i][j-1])
        return bin_find2D(nums, n, m-1);
    else if(nums[i][j] < nums[i][j-1])
        return bin_find2D(nums, n, m+1);
    else
        return loc(i, j);
}
loc findPeakElement2D(vector<vector<int> >& nums)  // n*m
{
    int m = nums[0].size();
    int n = nums.size();
    return bin_find2D(nums, n, m);
}

int main()
{
    vector<int> a = {1,2,1,3,5,6,4};
    //cout << findPeakElement(a);
    vector<int> b = {4,5,34,10,7,3,8};
    vector<int> c = {33,23,3,4,12,5,9};
    vector<vector<int> > nums;
    nums.push_back(a);
    nums.push_back(b);
    nums.push_back(c);
    loc l = findPeakElement2D(nums);
    cout << l.i<<","<< l.j <<endl;
}