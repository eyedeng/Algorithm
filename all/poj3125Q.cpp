#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Node
{
    int v;int position;
} x[101],temp;
typedef Node ElementType;
typedef struct LNode * PtrToLNode;

bool comp(const struct Node &a,const struct Node &b){
    return a.v<b.v;
}
struct LNode
{
    ElementType Date;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;
List Creat()
{
    int N;
    cout<<"节点个数";
    cin>>N;
    int n;
    List L = (List)malloc(sizeof(struct LNode));
    List r = L;
    r->Next = NULL;
    for(int i=0; i<N; i++)
    {
        cin>>n;
        List p = (List)malloc(sizeof(struct LNode));
        p->Date = n;
        p->Next = NULL;
        r->Next = p;
        r = p;
    }
    r->Next = NULL;
    return L;
}
void print(List L)
{
    while(L){
        cout<<L->Date<<" ";
        L = L->Next;
    }
}
int Length(List L)
{
    Position p = L;
    int cnt = 0;
    while(p){
        p = p->Next;
        cnt++;
    }
    return cnt;
}

ElementType Findkth(List L,int k)
{
    Position p = L;
    int cnt = 1;
    while(p && cnt<k){
        p = p->Next;
        cnt++;
    }
    if(cnt==k && p)
        return p->Date;
    else
        return -1;
}
Position Find(List L,ElementType x)
{
    Position p = L;
    while(p && p->Date != x)
        p = p->Next;
    return p;
}
List Insert(List L,ElementType x,int i)
{
    Position temp,pre;
    temp = (List)malloc(sizeof(struct LNode));
    temp->Date = x;
    if(i==1){
        temp->Next = L;
        return temp;
    }
    else{
        int cnt=1;
        pre = L;
        while(pre && cnt<i-1){
            pre = pre->Next;
            cnt++;
        }
        if(pre==NULL || cnt!=i-1){
            cout<<"Insert Position Error";
            free(temp);
        }
        else{
            temp->Next = pre->Next;
            pre->Next = temp;
            return L;
        }
    }
}
List Delete(List L,int i)
{
    List temp,pre;
    if(i==1){
        temp = L; //
        if(L!=NULL)
            L = L->Next;
        else
            return NULL;
        free(temp); //
        return L;
    }
    //pre = Findkth(L,i-1);
    int cnt = 1;
    pre = L;
    while(pre && cnt<i-1){
        pre = pre->Next;
        cnt++;
    }
    if(pre == NULL || pre->Next == NULL){
        cout<<"第"<<i-1<<"or"<<i<<"个节点不存在,Delete Position Error"<<endl;
        return NULL;
    }
    else{
        temp = pre->Next;
        pre->Next = temp->Next;
        free(temp); //
        return L;
    }
}

int main()
{
    int N,n,m,ans,po;

    cin>>N;
    while(N--)
    {
        List q;
        ans = 0;
        cin>>n>>m;
        for(int i=0; i<n; i++)
        {
            scanf("%d", &x[i].v);
            x[i].position = i;
            q.push(x[i]);
        }

        //m = x[m];
        po = m;
        m = x[m].v;
        sort(x,x+n,comp);
        for(int i=n-1; ; )
        {
            temp = q.front();
            if(x[i].v==temp.v ){
                ans++;
                if(x[i].v==m && temp.position==po){
                    break;
                }
                q.pop();
                i--;
            }
            else{
                q.push(temp);
                q.pop();
            }
        }
        cout<<ans<<endl;
    }
}
