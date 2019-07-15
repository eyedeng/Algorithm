#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*  合数分解
 *  合数的分解需要先进行素数的筛选
 *  factor[i][0]存放分解的素数  i : [0..fatCnt-1]
 *  factor[i][1]存放对应素数出现的次数
 *  fatCnt存放合数分解出的素数个数(相同的素数只算一次)
 */
const int MAXN=10000;
int prime[MAXN+1];
void getPrime()
{
    memset(prime,0,sizeof(prime));
    for(int i=2; i<=MAXN; i++)
    {
        if(!prime[i])prime[++prime[0]]=i;
        for(int j=1; j<=prime[0]&&prime[j]<=MAXN/i; j++)
        {
            prime[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}
long long factor[100][2];
int fatCnt;
int getFactors(long long x)
{
    fatCnt=0;
    long long tmp=x;
    for(int i=1; prime[i]<=tmp/prime[i]; i++)
    {
        factor[fatCnt][1]=0;
        if(tmp%prime[i]==0)
        {
            factor[fatCnt][0]=prime[i];  // 要分解的素数
            while(tmp%prime[i]==0)
            {
                factor[fatCnt][1]++;    // 对应素数出现次数
                tmp/=prime[i];
            }
            fatCnt++;    // 合数分解出的素数个数(相同的素数只算一次)
        }
    }
    if(tmp!=1)
    {
        factor[fatCnt][0]=tmp;
        factor[fatCnt++][1]=1;
    }
    return fatCnt;
}
//******************************************
int main()
{
    ll cnt,n;
    getPrime();
	while(cin>>n)
	{
		cnt = getFactors(n);
        printf("%lld has %lld prime factors:", n, cnt);
        for(int i = 0; i < cnt; i++)  // 0..cnt-1
            printf("%lld^%lld * ", factor[i][0], factor[i][1]);
	}
    /*for(ll n=1; n<=50; n++)
    {
        cnt = getFactors(n);
        cout<<n<<": "<<cnt<<" ";
        cout<<factor[cnt][0]<<" "<<factor[cnt][1]<<endl;  // ?
    }*/
    return 0;
}
