#include <stdio.h>
#include <iostream>
#include <queue>
#include<algorithm>
using namespace std;
struct Node
{
    int v;int position;
} x[101],temp;
bool comp(const struct Node &a,const struct Node &b){
    return a.v<b.v;
}
int main()
{
    int N,n,m,ans,po;

    cin>>N;
    while(N--)
    {
        queue<Node> q;
        ans = 0;
        cin>>n>>m;
        for(int i=0; i<n; i++)
        {
            scanf("%d", &x[i].v);
            x[i].position = i;
            q.push(x[i]);
        }

        //m = x[m];
        po = m;
        m = x[m].v;
        sort(x,x+n,comp);
        for(int i=n-1; ; )
        {
            temp = q.front();
            if(x[i].v==temp.v ){
                ans++;
                if(x[i].v==m && temp.position==po){
                    break;
                }
                q.pop();
                i--;
            }
            else{
                q.push(temp);
                q.pop();
            }
        }
        cout<<ans<<endl;
    }
}
