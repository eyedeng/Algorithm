#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    int tmp,i,j;
    //printf("input n:");
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d=",n);
        for(i=2; i<=sqrt(n)+1; i++)
        {
            while(n>i)
            {
                if(n%i==0)
                {
                    printf("%d*",i);
                    n = n/i;
                }
                else
                {
                    break;
                }
            }
        }
        printf("%d\n",n);
    }
    return 0;
}
