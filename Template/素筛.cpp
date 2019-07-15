#include <bits/stdc++.h>
using namespace std;

/*
 *  ����ɸѡ���ж�С��MAXN�����ǲ�������
 *  notprime��һ�ű�false��ʾ��������true��ʾ����
 */

const int MAXN = 1000010;
bool notprime[MAXN];

void init()
{
    memset(notprime, false, sizeof(notprime));
    notprime[0] = notprime[1] = true;
    for (int i = 2; i < MAXN; i++)
    {
        if (!notprime[i])
        {
            if (i > MAXN / i)   //  ��ֹ���i * i���������i,j��long long)
            {
                continue;
            }
            for (int j = i * i; j < MAXN; j += i)
            {
                notprime[j] = true;
            }
        }
    }
}

int main()
{
    init();
    cout<<notprime[101]<<endl;  // false
    cout<<notprime[100]<<endl;  // true
    return 0;
}
int prime[MAXN+1];  // -1:is prime   0:not prime
void ss()
{
	memset(prime,-1,sizeof(prime));
	prime[0] = prime[1] = 0;
	int i,j;
	for(i=2; i*i<=MAXN; i++)
	{
		if(prime[i])
		{
			for(j=i*i; j<=MAXN; j+=i)
				prime[j] = 0;
		}
	}
}

