#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
#define M 80
char mapp[M][M];
int vis[M][M];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int w,h;
struct Node
{
    int x,y;
    int cnt;
    int i_dir;
};
Node s,e;
int bfs()
{
    memset(vis,0,sizeof(vis));
    queue<Node> q;
    s.cnt = 0;
    s.i_dir = -1;
    vis[s.x][s.y] = 1;
    q.push(s);
    Node d,nd;
    while(!q.empty())
    {
        d = q.front();
        q.pop();
        if(d.x==e.x&&d.y==e.y)
        {
            return d.cnt;
        }
        for(int i=0; i<4; i++)
        {
            nd.x = d.x + dir[i][0];
            nd.y = d.y + dir[i][1];
            if(nd.x>=0&&nd.x<=h+1&&nd.y>=0&&nd.y<=w+1&&!vis[nd.x][nd.y])
            {
                if(nd.x==0||nd.y==0||nd.x==h+1||nd.y==w+1
                   ||mapp[nd.x][nd.y]==' '||(nd.x==e.x&&nd.y==e.y))
                {
                    //cout<<nd.x<<","<<nd.y<<endl;
                    vis[nd.x][nd.y] = 1;
                    if(d.i_dir==-1)
                    {
                        nd.cnt = 1;
                        nd.i_dir = i;
                    }
                    else
                    {
                        if(i==d.i_dir)
                        {
                            nd.cnt = d.cnt;
                            nd.i_dir = i;
                        }
                        else
                        {
                            nd.cnt = d.cnt + 1;
                            nd.i_dir = i; //cout<<"dir:"<<i<<endl;
                        }

                    }
                    q.push(nd);
                }

            }
        }
    }
    return -1;
}
int main()
{
    int board = 1;
    while(scanf("%d%d", &w,&h)&&(w&&h))
    {

        for(int i=1;i<=h;i++){
            getchar();
            for(int j=1;j<=w;j++){
                scanf("%c",&mapp[i][j]);
            }
         }
        printf("Board #%d:\n",board++);
        int pai = 1;
        while(scanf("%d%d%d%d",&s.y,&s.x,&e.y,&e.x)&&(s.x))
        {
            int ans = bfs();
            if(ans==-1)
            {
                printf("Pair %d: impossible.\n",pai++);
            }
            else
            {
                printf("Pair %d: %d segments.\n",pai++,ans);
            }
        }
        printf("\n"); // PE
    }

}
