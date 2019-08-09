#include <bits/stdc++.h>
using namespace std;
#define ll long long

// a^b % p
// a^2^(i+1) % c = a^2^i^2 % c   2^i项 -> 2^(i+1)项
long long qpow(long long a, long long b, long long p) {
  if (b == 0) return 1 % p;
  if (b == 1) return a % p;
  if (b % 2 == 0) {
    long long t = a * a % p;
    return qpow(t, b / 2, p);
  } else {
    long long t = a * a % p;
    return (qpow(t, b / 2, p) * a) % p;
  }
}

int main()
{
    cout<<qpow(2, 30000, 200);
    return 0;
}

ll binpow(ll a,ll n)  // 二分幂 a^n
{
    //cout<<a<<","<<n<<"\n";
    if(n==0)
        return 1;
    if(n==1)
        return a;
    ll ans = binpow(a, n>>1);
    if(n&1)
        return a*ans*ans;
    else
        return ans*ans;
}


