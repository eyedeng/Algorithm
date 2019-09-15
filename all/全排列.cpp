#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 111

int n = 10;
int vis[20];
int arr[20];
int cnt = 0;
void p(int step)
{
    if(step == n+1)
    {
//        for(int i=1; i<step; i++)
//        {
//            cout<<arr[i]<<" ";
//        }
//        cout<<endl;
        cnt++;
        return;
    }
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            arr[step] = i;
            vis[i] = 1;
            p(step+1);
            vis[i] = 0;
        }
    }
}

int main()
{
	p(1);
	cout<<cnt<<endl;
	return 0;
}

