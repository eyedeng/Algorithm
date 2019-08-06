#include <iostream>
#include <queue>
using namespace std;
int K,N;
int vis[100001];
struct Node
{
    int x,len;
};
Node s,e;
int bfs()
{
    queue<Node> q;
    s.len = 0;
    s.x = N;
    q.push(s);
    vis[N] = 1;
    while(!q.empty())
    {
        Node n = q.front();
        q.pop();
        if(n.x==K)
            return n.len;
        for(int i=1; i<=3; i++)
        {
            Node nn;
            switch (i)
            {
            case 1:

                nn.x = n.x-1;
                if(nn.x>=0 && nn.x<100001 && !vis[nn.x]   ){
                    vis[nn.x] = 1;
                    nn.len = n.len+1;
                    q.push(nn);
                }
                break;
            case 2:
               // Node nn;
                nn.x = n.x+1;
                if(nn.x>=0 && nn.x<100001 && !vis[nn.x]){
                    vis[nn.x] = 1;
                    nn.len = n.len+1;
                    q.push(nn);
                }
                break;
            case 3:
               // Node nn;
                nn.x = n.x*2;
                if(nn.x>=0 && nn.x<100001 && !vis[nn.x] ){
                    vis[nn.x] = 1;
                    nn.len = n.len+1;
                    q.push(nn);
                }
                break;
            }

        }

    }
    return -1;
}
int main()
{
    cin>>N>>K;
    if(N>=K)
        cout<<N-K<<endl;
    else{
        cout<<bfs()<<endl;
    }
}
