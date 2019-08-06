#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define M 30010
int parent[M];
int total[M];  //total[ getRoot(a) ] a所在group人数
//int Rank[M];
int sz[M];
inline void makeSet(int a)
{
    parent[a] = a;
    total[a] = 1;
    //Rank[a] = 0;
    //sz[i] = 1;
}
int getRoot(int a)
{
    if(a!=parent[a])
        parent[a] = getRoot(parent[a]);
    return parent[a];
}
void Merge(int a,int b)
{
    int roota = getRoot(a);
    int rootb = getRoot(b);
    if(roota==rootb)
        return;
    // Rank小并大 (实际用处不大)
//    if(Rank[roota]<Rank[rootb]){
//        parent[roota] = rootb;
//        total[rootb] += total[roota];
//    }
//    else if(Rank[rootb]<Rank[roota]){
//        parent[rootb] = roota;
//        total[roota] += total[rootb];
//    }
//    else{
//        parent[rootb] = roota;
//        total[roota] += total[rootb];
//        Rank[roota]++;
//    }
    if(sz[roota]<sz[rootb]){
        parent[roota] = rootb;
        total[rootb] += total[roota];
        sz[rootb] += sz[roota];
    }
    else{
        parent[rootb] = roota;
        total[roota] += total[rootb];
        sz[roota] += sz[rootb];
    }

}
int main()
{
    int n,m;
    while(scanf("%d%d", &n,&m) && n!=0)
    {
        for(int i=0; i<n; i++)
        {
            //parent[i] = i;total[i] = 1;
            makeSet(i);
        }
        while(m--)
        {
            int k,h,s;
            scanf("%d%d",&k,&h);
            while(--k)
            {
                scanf("%d", &s);
                Merge(h,s);
            }
        }
        printf("%d\n",total[getRoot(0)]);
    }
    return 0;
} //912K	16MS
//1028K	16MS
