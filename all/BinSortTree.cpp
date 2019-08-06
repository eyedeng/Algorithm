#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <windows.h>
using namespace std;
typedef int EleType;
typedef struct TNode* BSTree;
#define MAX 10000
struct TNode
{
    int Data;
    BSTree Left;
    BSTree Right;
};
int vis[MAX];
void insert_(BSTree &b, int e)
{
    vis[e] = 1;
    if( b==NULL )
    {
        BSTree s = new TNode;
        s->Data = e;
        s->Left = s->Right = NULL;
        b = s;
    }
    else if( e<b->Data )
        insert_(b->Left, e);
    else if( e>b->Data )
        insert_(b->Right, e);
    // e==b->Date
}
void creat_bst(BSTree &b)
{
    int e;
    cin>>e;
    while( e!=0 ) // '0'结束输入
    {
        if( vis[e]==0 )
            insert_(b, e);
        cin>>e;
    }
}
void travel(BSTree b) //中序遍历
{
    if(b)
    {
        travel(b->Left);
        printf("%3d ",b->Data);
        travel(b->Right);
    }
}
BSTree get_max_less(BSTree &b, int e)
{
    if( b==NULL )
        return NULL;
    if( e<=b->Data )
    {
        return get_max_less(b->Left, e);  // 向左找
    }
    else
    {
        BSTree r_get = get_max_less(b->Right, e);
        if( r_get==NULL )  // 在右孩子未找到较小值
            return b;      // 根即为最大较小值
        //else
            //return r_get;
    }
}
BSTree get_min_bigger(BSTree &b, int e)
{
    if( b==NULL )
    {
        return NULL;
    }
    if( e>=b->Data )
    {
        return get_min_bigger(b->Right, e);  // 向右找
    }
    else
    {
        BSTree l_get = get_min_bigger(b->Left, e);
        if( l_get==NULL )  // 在左孩子未找到较大值
            return b;      // 根即为最小较大值
        //else
            //return l_get;
    }
}
void delete_node(BSTree &node)
{
    if( node->Left==NULL&&node->Right==NULL )  // 叶子节点
    {
        node = NULL;
    }
    else if( node->Left==NULL )  // 只有右孩子，
    {
        node = node->Right;  // 接上来
    }
    else if( node->Right==NULL )  // 只有左孩子，
    {
        node = node->Left;
    }
    else
    {
        BSTree q = node;
        //BSTree s = get_max_less(node, node->Data);  // 找node前驱
        //找不到 s父节点
        BSTree s = node->Left;  // 找node前驱
        while( s->Right )
        {
            q = s;  // 记录s父节点
            s = s->Right;
        }
        node->Data = s->Data;  //仅替换值域 node左右指针不变，右子树整体照常

        //node左子树在 q的孩子改变
        if( q==node )      // 未进循环
             q->Left = s->Left;
        else
             q->Right = s->Left;
/*

  node=q --> O
            /  \
     S --> O    ...
          /
   SL--> O
__________________
    node --> O
            /  \
     q --> O    ...
            \
             O <-- S
            /
    SL --> O
*/

    }
}
void delete_(BSTree &b, int d)
{
    if( b==NULL )
        return;
    else
    {
        if( d==b->Data )
            delete_node(b);  // 删除此节点
        else if( d<b->Data )
            delete_(b->Left, d);  // 找
        else
            delete_(b->Right, d);

    }
}

int main()
{
    BSTree bst = new TNode;
    bst = NULL;
    creat_bst(bst);
    travel(bst);
    printf("\n");

    int del;
    cin>>del;
    delete_(bst, del);
    cout<<"删除"<<del<<":";
    travel(bst);
    printf("\n");

    int e;
    cin>>e;
    BSTree les = get_max_less(bst, e);
    BSTree big = get_min_bigger(bst, e);
    if( les!=NULL )
        cout<<"比"<<e<<"小的最大值："<<les->Data<<endl;
    else
        cout<<"no"<<endl;
    if( big!=NULL )
        cout<<"比"<<e<<"大的最小值："<<big->Data<<endl;
    else
        cout<<"no"<<endl;
    return 0;
}
//20 10 35 17 2 15 27 46 40 0
