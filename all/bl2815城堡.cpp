#include <iostream>
using namespace std;
int R,C;
int room[60][60];
int vis[60][60];
int roomNum = 0;
int maxRA = 0,roomArea=0;

void dfs(int i,int j)
{
    if(vis[i][j])   //over!!!
        return;     //over!!!
    vis[i][j] = 1;
    roomArea++;
    if( !(room[i][j]&1) )
    {
        dfs(i,j-1);
    }
    if( !(room[i][j]&2) )
    {
        dfs(i-1,j);
    }
    if( !(room[i][j]&4) )
    {
        dfs(i,j+1);
    }
    if( !(room[i][j]&8) )
    {
        dfs(i+1,j);
    }

}
int main()
{
    cin>>R>>C;
    for(int i=1; i<=R; i++)
        for(int j=1; j<=C; j++)
            cin>>room[i][j];
    for(int i=1; i<=R; i++)
        for(int j=1; j<=C; j++)
            if(!vis[i][j])
            {
                roomNum++;
                dfs(i,j);
                maxRA = max(maxRA,roomArea);
                roomArea=0;
            }
    cout<<roomNum<<endl<<maxRA<<endl;
    return 0;
}
