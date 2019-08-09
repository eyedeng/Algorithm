#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
// C(n,r) = C(n-1,r-1) + C(n-1,r)
int cache[100][100];    // dp�Ʊ�洢
int bino(int n, int r)
{
    if(r == 0 || n == r)
        return 1;
    if(cache[n][r] != -1)
        return cache[n][r];
    cache[n][r] = bino(n-1, r-1) + bino(n-1, r);
    return cache[n][r];
}
// �������
int C[100][100];
int bino2(int n,int r)
{
    for(int i=0; i<=n; i++)
    {
        C[i][0] = C[i][i] = 1;  // ����
        for(int j=1; j<n; j++)
        {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
    return C[n][r];
}
void formula(int n,int k)
{
	k = min(k, n-k);
	double p = 1,dn = n,dk = k;
	for(int i=1; i<=k; i++,dn-=1,dk-=1)
	{
		p *= dn / dk;
	}
	printf("%.0f\n",p);
}

// poj 3219
//(n,r)(r<=n)����ż��ȡ����(n-r)��r�Ķ����Ʊ��ʽ�Ƿ����ͬһλ�ϵ����������Ϊ1�������ڣ���Ϊż������֮Ϊ����
bool is_even(int n,int r)
{
	if((n-r)&r)
		return true;
	return false;
}
int main()
{
    memset(cache, -1, sizeof(cache));
    int n, r;
    while(cin>>n>>r)
        cout<<bino(n, r)<<endl;
    return 0;
}
