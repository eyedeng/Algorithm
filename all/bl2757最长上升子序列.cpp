#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
/*
记忆化dp 05/11/2019
*/
int cache[100],S[100],n;
int LIS(int start)           //从S[start]开始的IS的最大长度
{
    cout<<start<<"  ";
    int& ret = cache[start];
    if(ret != 0)
        return ret;
    ret = 1;
    for(int next = start+1; next<n; next++)
    {
        if(S[next] > S[start])
        {
            ret = max(ret, LIS(next)+1);
        }
    }
    return ret;
}
int main()
{
    int N,a[1010],maxlen[1010];
    cin>>N;

    for(int i=0; i<N; i++)
    {
        scanf("%d", &a[i]);    S[i]=a[i];
        maxlen[i] = 1;
    }
    for(int i=1; i<N; i++)
    {
        for(int j=i-1; j>=0; j--)
        {
            if(a[i]>a[j])
            {
                maxlen[i] = max(maxlen[i],maxlen[j]+1);
            }
        }
    }
    cout<<* max_element(maxlen,maxlen + N  )<<endl;

    n=N;
    cout<<LIS(0)<<endl;
    return 0;

}
