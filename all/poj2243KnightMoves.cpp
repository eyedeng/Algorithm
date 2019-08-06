#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
int dir[8][2]={{-2,-1},{-2,1},{2,-1},{2,1},{-1,-2},{-1,2},{1,-2},{1,2}};
int vis[10][10];
//int Map[10][10];
struct Map
{
    int x,y;
    int len;
};
Map start,End;
int main()
{
    char a[3],b[3];
    while(~scanf("%s%s",a,b))
    {

        memset(vis,0,sizeof(vis));
        queue<Map> q;
        start.x = a[1]-'1'; // 0
        start.y = a[0]-'a';
        start.len = 0;
        vis[start.x][start.y] = 1;
        End.x = b[1]-'1';
        End.y = b[0]-'a';
        End.len = 0;
        q.push(start);

        while(!q.empty())
        {
            Map now,nt;
            now = q.front();
            q.pop();
            if(now.x==End.x&&now.y==End.y)
            {
                printf("To get from %s to %s takes %d knight moves.\n",a,b,now.len);
                break;
            }
            for(int i=0; i<8; i++)
            {
                nt.x = now.x + dir[i][0];
                nt.y = now.y + dir[i][1];
                if(nt.x>=0&&nt.x<8&&nt.y>=0&&nt.y<8
                   &&!vis[nt.x][nt.y])
                {
                    vis[nt.x][nt.y] = 1;
                    nt.len = now.len + 1;
                    q.push(nt);
                }
            }

        }

    }
    return 0;
}
