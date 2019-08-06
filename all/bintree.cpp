#include <queue>
#include <iostream>
#include <stack>
#include <algorithm>
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

BinTree CreatBinTree()
{
    ElementType data;
    BinTree BT,T;
    queue<BinTree> q; //
    cin>>data;
    if(data==0) return NULL;
    else
    {
        BT = (BinTree)malloc(sizeof(struct TNode));
        BT->Data = data;
        BT->Left = BT->Right = NULL;
        q.push(BT);
    }
    while (!q.empty()) //队列 非递归
    {
        T = q.front();
        q.pop();
        cin>>data;
        if(data==0) T->Left = NULL;
        else
        {
            T->Left = (BinTree)malloc(sizeof(struct TNode));
            T->Left->Data = data;
            T->Left->Left = T->Left->Right = NULL;
            q.push(T->Left);
        }
        cin>>data;
        if(data==0) T->Right = NULL;
        else
        {
            T->Right = (BinTree)malloc(sizeof(struct TNode));
            T->Right->Data = data;
            T->Right->Left = T->Right->Right = NULL;
            q.push(T->Right);
        }
    }
    return BT;
}

//11.12 先序建树
void creat_preorder(BinTree &bt, char *s, int &index)  // index &使index累加
{
    if(s[index]=='\0'||s[index]=='0')
    {
        bt = NULL;
        return;
    }

    BinTree t = new TNode;
    t->Data = s[index];
    t->Left = t->Right = NULL;
    bt = t;
    creat_preorder(bt->Left, s, ++index);
    creat_preorder(bt->Right, s, ++index);
}

void PreorderTravelsal(BinTree BT) //先序遍历
{
    if(BT)
    {
        printf("%5d",BT->Data);
        PreorderTravelsal(BT->Left);
        PreorderTravelsal(BT->Right);
    }
}
void PreorderTravelsal2(BinTree BT) //先序 栈 非递归
{
    BinTree T = BT;
    stack<BinTree> s;
    while( T || !s.empty())
    {
        while(T){
            printf("%5d",T->Data);
            s.push(T);
            T = T->Left;
        }
        T = s.top();
        s.pop();
        T = T->Right;
    }
}
void InorderTravelsal2(BinTree BT) //中序遍历
{
    if(BT)
    {
        InorderTravelsal2(BT->Left);
        printf("%5d",BT->Data);
        InorderTravelsal2(BT->Right);
    }
}

void InorderTravelsal(BinTree BT) //中序 栈 非递归
{
    BinTree T = BT;
    stack<BinTree> s;
    while( T || !s.empty())
    {
        while(T){
            s.push(T);  //保存自己 由自己找到左右儿子
            T = T->Left;
        }
        if(!s.empty()){
            T = s.top();
            s.pop();
            printf("%5d",T->Data);
            T = T->Right;
        }
    }
}
void LevelorderTravelsal(BinTree BT) //bfs
{
    BinTree T = BT;
    queue<BinTree> q;
    q.push(T);
    if(!T) return;
    while(!q.empty())
    {
        T = q.front();
        q.pop();
        printf("%5d",T->Data);
        if(T->Left)
            q.push(T->Left);
        if(T->Right)
            q.push(T->Right);
    }
}
int GetHeight(BinTree BT)
{
    //int hl,hr,maxh;
    if(!BT) return 0;
    return max( GetHeight(BT->Left),GetHeight(BT->Right) )+1;

}

//二叉搜索树 L<Root<R
Position ItemFind(BinTree BST,ElementType x)
{
    while(BST)
    {
        if(x>BST->Data)
            BST = BST->Right;
        else if(x<BST->Data)
            BST = BST->Left;
        else
            return BST;
    }
    return NULL;
}
Position FindMax(BinTree bst)
{
    if(bst){
        while(bst->Right)
            bst = bst->Right;
    }
    return bst;
}
int main()
{
    BinTree bt = CreatBinTree();

    BinTree bst = FindMax(bt);
    if(bst)
        cout<<bst->Data;
    printf("\n");

    return 0;
}
//5 3 8 1 4 6 0 0 2 0 0 0 7 0 0 0 0
