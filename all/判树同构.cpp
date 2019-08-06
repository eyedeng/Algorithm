#include <queue>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int vis[10],head[2],hea=0;
struct Node
{
    char nodec;
    int left;
    int right;
} Tree1[10],Tree2[10];

void creat(Node tree[])
{
    int N;
    cin>>N;
    char inb,inc;
    memset(vis,0,sizeof(vis));
    for(int i=0; i<N; i++)
    {
        cin>>tree[i].nodec>>inb>>inc;
        if(inb=='-')
            tree[i].left = -1;
        else{
            tree[i].left = inb-'0';
            vis[tree[i].left]= 1;
        }
        if(inc=='-')
            tree[i].right = -1;
        else{
            tree[i].right = inc-'0';
            vis[tree[i].right]= 1;
        }
    }
    for(int i=0;i<N; i++)
        if(!vis[i]){
            head[hea++] = i;
            break;
        }
}
bool isHeadSample(Node tree1[],Node tree2[])
{
    if(tree1[head[0]].nodec==tree2[head[1]].nodec)
        return 1;
    return 0;
}
bool isSample(int node1,int node2)
{
    if(node1==-1 && node2==-1)
        return 1;
    if( (node1==-1&&node2!=-1)||(node2==-1&&node1!=-1) )
        return 0;
    if(Tree1[node1].nodec!=Tree2[node2].nodec)
        return 0;
    else
        return 1;
    if((Tree1[node1].left!=-1&&Tree2[node2].left!=-1)
       && Tree1[Tree1[node1].left].nodec==Tree2[Tree2[node2].left].nodec)
        return (isSample(Tree1[node1].left,Tree2[node1].left)
                && isSample(Tree1[node1].right,Tree2[node1].right));
    else
        return (isSample(Tree1[node1].left,Tree2[node1].right)
                && isSample(Tree1[node1].right,Tree2[node1].left));

    if(Tree1[node1].left==-1&&Tree2[node2].left==-1)
        return isSample(Tree1[node1].right,Tree2[node2].right);
    if(Tree1[node1].right==-1&&Tree2[node2].right==-1)
        return isSample(Tree1[node1].left,Tree2[node2].left);
    if(Tree1[node1].left==-1&&Tree2[node2].left!=-1)
        return isSample(Tree1[node1].right,Tree2[node2].left);
    if(Tree1[node1].right==-1&&Tree2[node2].right!=-1)
        return isSample(Tree1[node1].left,Tree2[node2].right);

}
int main()
{
    creat(Tree1);
    creat(Tree2);

    if(isSample(head[0],head[1]))
            cout<<"ËûÂèµÄYES\n";
    else
        cout<<"chaos\n";
}
