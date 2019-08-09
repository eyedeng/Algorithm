#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
#define For(i, n) for(int i=0; i<n; i++)
#define For1(i, n) for(int i=1; i<=n; i++)
void quick_sort(int a[],int l,int r)
{
    if(l > r)
        return;
    int pivot = a[l];
    int i = l,j = r;
    while(i < j)
    {
        while(a[j] >= pivot && i < j)  // 先j往左找小于pivot的
        {
            j--;
        }
        while(a[i] <= pivot && i < j)
        {
            i++;
        }
        if(i < j)
            swap(a[i], a[j]);
//       cout<<i<<","<<j<<endl;
    }
    a[l] = a[i];
    a[i] = pivot;
    quick_sort(a, l, i-1);
    quick_sort(a, i+1, r);
}
int main()
{
    int n;
    int a[10000];
    cin>>n;
    For1(i, n)
        scanf("%d", &a[i]);
    quick_sort(a, 1, n);
    For1(i, n)
        cout<<a[i]<<" ";
    return 0;
}
