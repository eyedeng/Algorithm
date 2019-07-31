Part1
// https://www.youtube.com/watch?v=Jakbj4vaIbE 黄浩杰
struct Job
{
    int en,st,val;
};
Job job[9];
int main()
{
    //int pre[8] = {0,0,0,1,0,2,3,5};
    int pre[9] = {0};
    for(int i=1; i<=8; i++)
        scanf("%d%d%d", &job[i].st,&job[i].en, &job[i].val);
    for(int i=1; i<=8; i++)
        for(int j=1; j<i; j++)
            if(job[j].en <= job[i].st)
                pre[i]++;
    
    int opt[9] = {0};
    opt[0] = 0;
    for(int i=1; i<=8; i++)
    {
        opt[i] = max(opt[i-1] ,job[i].val + opt[pre[i]]);
        cout<<opt[i]<<" ";
    }
    cout<<opt[8];
    return 0;
}
/*
1 4 5
3 5 1
0 6 8
4 7 4
3 8 6
5 9 3
6 10 2
8 11 4
*/

int main()
{
    int arr[7] = {1, 2, 4, 1, 7, 8, 3};
    int opt[7] = {0};
    opt[0] = arr[0];
    opt[1] = max(opt[0], arr[1]);
    for(int i=2; i<7; i++)
    {
        opt[i] = max(opt[i-1], opt[i-2]+arr[i]);
        cout<<opt[i]<<" ";
    }
    cout<<opt[6];
}


Part2
https://oi-wiki.org/dp/knapsack/

// 01背包 一件物品 luogu2871
int dp[13000];  // dp[i]: 已装weight=i时的总价值
int main()
{
    int N,W;
    int wei[MAX],val[MAX];
    cin>>N>>W;
    for(int i=1; i<=N; i++)
    {
        cin>>wei[i]>>val[i];
    }
    for(int i=1; i<=N; i++)
    {
        for(int j=W; j>=wei[i]; j--)
        //for(int j=wei[i]; j<=W; j++)  // 选了多次
        {
            dp[j] = max(dp[j], dp[j-wei[i]]+val[i]);
            cout<<dp[j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[W]<<endl;
    return 0;
}
// https://www.youtube.com/watch?v=CO0r6kcwHUU
// 搜索 适用:N<20  W,w[] >> 10^6(dp枚举超时)
int N = 5; 
int W = 15;
int w[] = {-1,5,4,7,2,6};
int v[] = {-1,12,3,10,3,6};
int ans;
void dfs(int s,int cur_w,int cur_v)  // 第s件物品
{
    ans = max(ans, cur_v);
    cout<<ans<<endl;
    if(s>N)
    {
        return;
    }
    for(int i=s; i<=N; i++)
    {
        if(cur_w+w[i] <= W)
        {
            dfs(i+1, cur_w+w[i], cur_v+v[i]);
        }

    }
}
int main()
{
    dfs(1,0,0);  // index start from 1
    cout<<ans;
	return 0;
}

// 完全背包 无限物品 luogu1616
int dp[100010];  // dp[i]: 已用time=i时的总价值
int main()
{
    int T,nums;
    int time[MAX],val[MAX];
    cin>>T>>nums;
    for(int i=1; i<=nums; i++)
    {
        cin>>time[i]>>val[i];
    }
    for(int i=1; i<=nums; i++)
    {
        //for(int j=W; j>=wei[i]; j--)
        for(int j=time[i]; j<=T; j++)  // 选了多次
        {
            dp[j] = max(dp[j], dp[j-time[i]]+val[i]);
        }
    }
    cout<<dp[T]<<endl;
    return 0;
}

// 多重背包


