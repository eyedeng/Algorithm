#include <bits/stdc++.h>
using namespace std;
#define ll long long
int gcd(int a,int b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
	//return b!=0?gcd(b,a%b):a ;
}

//返回 d=gcd(a,b); 和对应于等式 ax+by=d 中的 x,y
long long extend_gcd(long long a,long long b,long long &x,long long &y)
{
    if(a==0&&b==0) return -1;//无最大公约数
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    long long d=extend_gcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
//ax = 1(mod n)
long long mod_reverse(long long a,long long n){
	long long x,y;
	long long d=extend_gcd(a,n,x,y);
	if(d==1) return (x%n+n)%n;
	else return -1;
}	
int main()
{
    ll a,b;
    while (scanf("%lld%lld", &a, &b) != EOF )
    {
		ll x,y;
        ll d = extend_gcd(a, b, x, y);
		printf("(%lld,%lld) x=%lld y=%lld\n", a, b, x, y);
		printf("%lld\n", mod_reverse(a, b));
    }
    return 0;
}
