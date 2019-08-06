#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;
#define FOR(i,n) for(int i=0; i<n; i++)
#define M 10000
typedef struct huffman_node * htree;
struct huffman_node
{
    char c;
    int index;
    int weight;
    int parent;
    int left,right;
    bool operator < (const huffman_node &a) const
    {
        return a.weight < weight;
    }
};
//bool comp(const huffman_node& a,const huffman_node &b)
//{
//    return a.weight>b.weight;
//}
void show(htree ht, int m)
{

    for(int i=1; i<=m; i++)
        printf("%d %d %d %d %d\n",i,ht[i].weight,ht[i].parent,
               ht[i].left,ht[i].right);

}
void creat(htree &ht, int n,int *cnt)
{
    if( n<=1 )
        return;
    int m = (n<<1)-1;
    ht = new huffman_node[m+1];  // 2*n-1 + 1
    int i;
    for(i=1; i<=n; i++)
    {
        ht[i].parent = ht[i].left = ht[i].right = 0;
    }
    for(int i=1; i<=m; i++)
        ht[i].index = i;

    int inc = 1;
    for(i='a'; i<='z'; i++)
    {
        if(cnt[i])
        {
            ht[inc].weight = cnt[i];
            ht[inc++].c = i;
        }

    }
    //sort(ht+1,ht+m+1,comp);
    //show(ht, m);
    priority_queue<huffman_node> pq;
    for(i=1; i<=n; i++)
        pq.push(ht[i]);
//    while(!pq.empty())
//    {
//        printf("%d ", pq.top().weight);
//        pq.pop();
//    }
    for(i=n+1; i<=m; i++)
    {
        huffman_node minl = pq.top();
        pq.pop();
        huffman_node minr = pq.top();
        pq.pop();
        ht[i].weight = minl.weight+minr.weight;
        ht[i].left = minl.index;
        ht[i].right = minr.index;
        ht[ minl.index ].parent = i;
        ht[ minr.index ].parent = i;
        pq.push(ht[i]);
    }
    ht[i-1].parent = 0;
    show(ht, m);
}
/*
��Ҷ�ӽڵ㵽���ڵ�������շ�����HT��n��Ҷ�ӽڵ�ĺշ������룬��������HC��
*/
void huf_coding(htree HT,char** HC,int n, char *code_)
{
	HC = new char*[n+1];

	char *code = new char[n];

	code[n-1] = '\0';

	int i;
	for(i=1;i<=n;i++)
	{
		int current = i;           //���嵱ǰ���ʵĽڵ�
		int father = HT[i].parent; //��ǰ�ڵ�ĸ��ڵ�
		int start = n-1;           //ÿ�α����λ�ã���ʼΪ�����������λ��
		//��Ҷ�ӽڵ�����շ�����ֱ�����ڵ�
		while(father != 0)
		{
			if(HT[father].left == current)   //��������ӣ������Ϊ0
				code[--start] = '0';
			else                              //������Һ��ӣ������Ϊ1
				code[--start] = '1';
			current = father;
			father = HT[father].parent;
		}

		//Ϊ��i���ַ��ı��봮����洢�ռ�
		HC[i] = new char[n-start];

		//�����봮��code���Ƶ�HC
		//strcpy(HC[i],code+start);
		strcpy(HC[i], &code[start]);
		//cout<<i<<":"<<HC[i]<<endl;
	}
    for(i=1; i<n; i++)
        printf("%c:%s ",HT[i].c, HC[i]);
    printf("%c:%s\n",HT[i].c, HC[i]);
    for(i=0; i<strlen(code_); i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(HT[j].c==code_[i])
            {
                printf("%s",HC[j]);
                break;
            }

        }
    }
    printf("\n%s\n",code_);
}
int main()
{
    char code[M];
    int cnt['z'+1];
    htree ht = new huffman_node;
    int n_node, len;
    char **hufcd;
    while(scanf("%s", code))
    {

        if(code[0]=='0')
            break;
        ht = new huffman_node;
        len = strlen(code);
        n_node = 0;
        memset(cnt, 0, sizeof(cnt));
        int i,j;
        for(i=0; i<len; i++)
        {
            if(!cnt[ code[i] ])
            {
                n_node++;
            }
            cnt[ code[i] ]++;
        }
        for(i='a',j=0; j<n_node-1; i++)
        {
            if(cnt[i])
            {
                printf("%c:%d ",i,cnt[i]);
                j++;
            }
        }
        for(; i<='z'; i++)
             if(cnt[i])
                printf("%c:%d\n",i,cnt[i]);
        creat(ht, n_node, cnt);
        huf_coding(ht, hufcd, n_node, code);


    }

    return 0;
}