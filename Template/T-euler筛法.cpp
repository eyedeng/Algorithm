#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
 *  筛法求欧拉函数
 */
#define MAXN 3000000
int euler[MAXN+1];  // phi(i)
void getEuler()
{
    memset(euler,0,sizeof(euler));
    euler[1] = 1;
    for(int i = 2; i <= MAXN; i++)
        if(!euler[i])
            for(int j = i; j <= MAXN; j += i)
            {
                if(!euler[j])
                    euler[j] = j;
                euler[j] = euler[j]/i*(i-1);
            }
}

//求单个数的欧拉函数
long long eular(long long n)
{
    long long ans = n;
    for(int i = 2; i*i <= n; i++)
    {
        if(n % i == 0)
        {
            ans -= ans/i;
            while(n % i == 0)
                n /= i;
        }
    }
    if(n > 1)ans -= ans/n;
    return ans;
}

int main()
{
    getEuler();
    for(int i=1; i<=100; i++)
        printf("%d ", euler[i]);
	printf("\n%lld\n", eular(1000000000));
    return 0;
}

