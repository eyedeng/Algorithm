#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n,a[100010],k;
void arrangeRight(int i,int j)
{
    int key = a[i];
    while( i<j )
    {
        while(a[j]>=key && i<j)
            j--;
        swap(a[i],a[j]);
        while(a[i]<=key && i<j)
            i++;
        swap(a[i],a[j]);
    }
    if( n-i==k )
        return;
    else if(n-i>k)
    {
        arrangeRight(i+1,n);
    }
    else
    {
        arrangeRight(k-(n-i),i);
    }

}
int main()
{

    int i,j;
    cin>>n;
    for(int i=1; i<=n; i++)
        scanf("%d", &a[i]);
    cin>>k;
    arrangeRight(1,n);
    sort(a+(n-k),a+n+1);
    for(i=n; i>n-k; i--)
        printf("%d\n",a[i]);
}
