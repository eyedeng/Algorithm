#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
int n;
int map[35][35];
int vis[35][35];
int mayok[30][30];
int ret=1;
int fx[]={0,0,1,-1};
int fy[]={1,-1,0,0};
struct Node{
	int x;int y;
};
void bfs(int ii,int jj)
{
	Node d,nd,be;
	queue<Node> q;
	be.x = ii;
	be.y = jj;
	vis[be.x][be.y]=1;
	q.push(be);
	while(!q.empty())
	{
		
		d = q.front(); //
		//mayok[d.x][d.y]=ret;
		q.pop();
	//	if(d.x==0 || d.x==n-1 ||d.y==0 || d.y==n-1){ //d not nd
	//		ret++; // leave and ++
	//		return;
		for(int i=0; i<4; i++)
		{
			nd.x = d.x+fx[i];
			nd.y = d.y+fy[i];
			if(nd.x>=0&&nd.x<n&&nd.y>=0&&nd.y<n
				&&map[nd.x][nd.y]==0&&vis[nd.x][nd.y]==0){
					vis[nd.x][nd.y]=1;
					//mayok[nd.x][nd.y]=ret; //biaoji
					q.push(nd);
				}
		}	
	}
	return;
}
int main()
{
	memset(vis,0,sizeof(vis));
	memset(mayok,0,sizeof(mayok));
	
	scanf("%d", &n);
	int i,j;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			scanf("%d",&map[i][j]);
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
		{
			if(i==0 || i==n-1 ||j==0 || j==n-1)
				if(vis[i][j]==0&&map[i][j]==0)
				{
					bfs(i,j);
				}
		}
	for(i=0; i<n; i++){
		for(j=0; j<n-1; j++)
		{
			if(map[i][j]==0&&vis[i][j]==0)
				printf("2 ");
			else printf("%d ",map[i][j]);
		}	
		printf("%d\n",map[i][j]);
	}
	return 0;
}
