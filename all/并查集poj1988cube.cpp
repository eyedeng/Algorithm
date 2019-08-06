#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define M 30010
int parent[M];
int sum[M];
int under[M];
int getRoot(int a)
{
    if(a==parent[a])
        return a;
    int t = getRoot(parent[a]);   //˳��
    under[a] += under[parent[a]]; //·��ѹ��ʱ����
    //parent[a] = getRoot(parent[a]);
    parent[a] = t;
    return parent[a];
}
void Merge(int a, int b)
{
    int roota = getRoot(a);
    int rootb  = getRoot(b);
    if(roota==rootb)
        return;
    parent[rootb] = roota;
                                //˳��
    under[rootb] = sum[roota]; //�� ����
    sum[roota] += sum[rootb];  //��
}
int main()
{
    for(int i=0; i<M; i++)
    {
        parent[i] = i;
        sum[i]  = 1;
        under[i] = 0;
    }
    int p;
    scanf("%d",&p);
    while(p--)
    {
        getchar();
        char c;
        int x,y;
        scanf("%c", &c);
        if(c=='M')
        {
            scanf("%d%d",&x,&y);
            Merge(y,x);
        }
        else
        {
            scanf("%d", &x);
            getRoot(x);  //����
            printf("%d\n",under[x]);
        }

    }
    return 0;
}
