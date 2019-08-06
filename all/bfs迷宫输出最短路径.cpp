#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maze[6][6];
struct Node
{
    int x,y;
    int pre;
    Node(int xx=0,int yy=0,int p=0):x(xx),y(yy),pre(p){ } //
};
Node que[100];
int head,tail;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int main()
{
    for(int i=1; i<=5; i++)
        for(int j=1; j<=5; j++)
        {
            scanf("%d", &maze[i][j]);
        }
    head = 0,tail = 1;
    que[0] = Node(1,1,-1);
    maze[1][1] = 1;
    while( head!=tail )
    {
        Node d = que[head];
        //head++;
        if(d.x==5 && d.y==5)
        {
//            cout<<d.pre<<endl;
//            cout<<que[d.pre].x<<","<<que[d.pre].y<<endl;
//            return 0;
            vector<Node> vt;
            while(1){
                vt.push_back(Node(d.x,d.y,1));// pre!=-1
                if(d.pre==-1)
                    break;
                d = que[d.pre];
            }
            for(int i=vt.size()-1; i>=0; i--)
                printf("(%d, %d)\n",vt[i].x-1,vt[i].y-1);
            return 0;
        }
        else
        {
            for(int i=0; i<4; i++){
                int nx = d.x+dir[i][0];
                int ny = d.y+dir[i][1];
                if( nx>=1&&nx<=5&&ny>=1&&ny<=5&&!maze[nx][ny] )
                {
                    que[tail++] = Node(nx,ny,head);
                    maze[nx][ny] = 1;
                }
            }
            head++;
        }
    }
    return 0;
}
