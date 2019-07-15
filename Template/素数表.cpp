#include <bits/stdc++.h>
using namespace std;
/*
 *  素数筛选，查找出小于等于MAXN的素数
 *  prime[0]存素数的个数
 */

const int MAXN = 100000;
int prime[MAXN + 1];

void getPrime()
{
    memset(prime, 0, sizeof(prime));
    for (int i = 2; i <= MAXN; i++)
    {
        if (!prime[i])
        {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && prime[j] <= MAXN / i; j++)
        {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
}
int main()
{
	getPrime();
	for(int i=1; i<=10; i++)
	{
		printf("第%d个素数是%d\n", i, prime[i]);
	}
}