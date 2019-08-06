#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;
typedef int ElementType;
typedef struct LNode * PtrToLNode;
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
    ElementType n;
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
void Creat2() //头插法 逆序
{
    int N;
    cout<<"num of Node:\n";
    cin>>N;
    List L = (List)malloc(sizeof(LNode));
    L->Next = NULL;
    ElementType n;
    List head = L;
    List p;
    while(N--)
    {
        cin>>n;
        p = (List)malloc(sizeof(LNode));
        p->Date = n;
        p->Next = head->Next;
        head->Next = p;
    }
    //p->Next->Next = NULL;
    while(head->Next){
        head = head->Next;
        cout<<head->Date<<" ";
    }

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
    Creat2();
    system("pause");
    List L = Creat();
    L = L->Next;
    print(L);cout<<endl;
    L = Delete(L,6);
    print(L);cout<<endl;
    system("pause");
    L = Insert(L,20,3);
    print(L);cout<<endl;
    cout<<Length(L)<<endl;
    cout<<Findkth(L,1)<<" "<<Findkth(L,4)<<endl;
    if(Find(L,20)){
        cout<<"Find"<<Find(L,20)->Date<<endl;
    }else cout<<"Not Find";
    return 0;
}
