#include <queue>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef int ElementType;
typedef struct TNode * Position;
typedef Position BinTree;
struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};
BinTree bt;
BinTree CreatBinTree()
{
    BinTree BT,T;
    queue<BinTree> q;
    BT = (BinTree)malloc(sizeof(struct TNode));
    BT->Data = 1;
    BT->Left = BT->Right = NULL;
    q.push(BT);
    int cnt=1;
    double tot = pow(2,20);
    while (cnt<tot) //¶ÓÁÐ ·ÇµÝ¹é
    {
        T = q.front();
        q.pop();
        T->Left = (BinTree)malloc(sizeof(struct TNode));
        T->Left->Data = 1;
        T->Left->Left = T->Left->Right = NULL;
        q.push(T->Left);

        T->Right = (BinTree)malloc(sizeof(struct TNode));
        T->Right->Data = 0;
        T->Right->Left = T->Right->Right = NULL;
        q.push(T->Right);
        cnt++;
    }
    return BT;
}
void bfs(int n)
{
    queue<BinTree> tq;
    tq.push(bt);
    long long res = 0;
    while(!tq.empty())
    {
        res*=10;
        res += tq.front()->Data;
        if( res%n==0){
            cout<<res<<endl;
            return;
        }

        tq.pop();
        tq.push(bt->Left);
        tq.push(bt->Right);
    }
}

int main()
{
    bt = CreatBinTree();

    int n;
    while(cin>>n && n)
    {
        bfs(n);
    }
}
