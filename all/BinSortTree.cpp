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
    while( e!=0 ) // '0'��������
    {
        if( vis[e]==0 )
            insert_(b, e);
        cin>>e;
    }
}
void travel(BSTree b) //�������
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
        return get_max_less(b->Left, e);  // ������
    }
    else
    {
        BSTree r_get = get_max_less(b->Right, e);
        if( r_get==NULL )  // ���Һ���δ�ҵ���Сֵ
            return b;      // ����Ϊ����Сֵ
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
        return get_min_bigger(b->Right, e);  // ������
    }
    else
    {
        BSTree l_get = get_min_bigger(b->Left, e);
        if( l_get==NULL )  // ������δ�ҵ��ϴ�ֵ
            return b;      // ����Ϊ��С�ϴ�ֵ
        //else
            //return l_get;
    }
}
void delete_node(BSTree &node)
{
    if( node->Left==NULL&&node->Right==NULL )  // Ҷ�ӽڵ�
    {
        node = NULL;
    }
    else if( node->Left==NULL )  // ֻ���Һ��ӣ�
    {
        node = node->Right;  // ������
    }
    else if( node->Right==NULL )  // ֻ�����ӣ�
    {
        node = node->Left;
    }
    else
    {
        BSTree q = node;
        //BSTree s = get_max_less(node, node->Data);  // ��nodeǰ��
        //�Ҳ��� s���ڵ�
        BSTree s = node->Left;  // ��nodeǰ��
        while( s->Right )
        {
            q = s;  // ��¼s���ڵ�
            s = s->Right;
        }
        node->Data = s->Data;  //���滻ֵ�� node����ָ�벻�䣬�����������ճ�

        //node�������� q�ĺ��Ӹı�
        if( q==node )      // δ��ѭ��
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
            delete_node(b);  // ɾ���˽ڵ�
        else if( d<b->Data )
            delete_(b->Left, d);  // ��
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
    cout<<"ɾ��"<<del<<":";
    travel(bst);
    printf("\n");

    int e;
    cin>>e;
    BSTree les = get_max_less(bst, e);
    BSTree big = get_min_bigger(bst, e);
    if( les!=NULL )
        cout<<"��"<<e<<"С�����ֵ��"<<les->Data<<endl;
    else
        cout<<"no"<<endl;
    if( big!=NULL )
        cout<<"��"<<e<<"�����Сֵ��"<<big->Data<<endl;
    else
        cout<<"no"<<endl;
    return 0;
}
//20 10 35 17 2 15 27 46 40 0
