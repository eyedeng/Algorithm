#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
 *  分解质因数求欧拉函数 公式法
 *  对正整数n，欧拉函数是小于或等于n的数中与n互质的数的数目。例如euler(8)=4，因为1,3,5,7均和8互质。
 *  Euler函数表达通式：euler(x)=x(1-1/p1)(1-1/p2)(1-1/p3)(1-1/p4)…(1-1/pn),其中p1,p2……pn为x的所有素因数，x是不为0的整数。euler(1)=1
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


int main()
{
    ll cnt,n;
    getPrime();
    while(cin>>n)
    {
        cnt = getFactors(n);
        
        //欧拉公式
        int ret = n;
        for(int i = 0; i < cnt; i++)
        {
            ret = ret/factor[i][0]*(factor[i][0]-1);
        }
        cout<<ret<<endl;
        //
    }
    return 0;
}
