#include <bits/stdc++.h>
using namespace std;
/*
 *  同时得到欧拉函数和素数表
 */
const int MAXN = 10000000;

bool check[MAXN + 10];
int phi[MAXN + 10];
int prime[MAXN + 10];
int tot;    //  素数个数

void phi_and_prime_table(int N)
{
    memset(check, false, sizeof(check));
    phi[1] = 1;
    tot = 0;
    for (int i = 2; i <= N; i++)
    {
        if (!check[i])
        {
            prime[tot++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] > N)
            {
                break;
            }
            check[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else
            {
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
        }
    }
    return ;
}

int main()
{
    phi_and_prime_table(100);
    cout<<tot<<endl;
    for(int i=0; i<=100; i++)
    {
        cout<<prime[i]<<","<<phi[i]<<endl;
    }
    return 0;
}