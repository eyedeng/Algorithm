#include <stdio.h>
#include <iostream>
using namespace std;
typedef int ElementType;
typedef struct Node * List;
struct Node
{
    ElementType data;
    List next,prev;
};
List creat()
{
    int N,d;
    cin>>N;
    List head = (List)malloc(sizeof(Node)),p;
    List h = (List)malloc(sizeof(Node));
    head->prev = head->next = NULL;
    h = head;
    for(int i=0; i<N; i++)
    {
        cin>>d;
        p = (List)malloc(sizeof(Node));
        p->data = d;
        head->next = p;
        p->prev = head;
        p->next = NULL;
        head = p;
    }
    return h;
}
void print(List l)
{
    cout<<"ÕýÐò£º\n";
    while(l->next)
    {
        l = l->next;
        cout<<l->data<<" ";
    }
    cout<<"\nÄæÐò£º\n";
    while(l->prev)
    {
        cout<<l->data<<" ";
        l = l->prev;
    }
}
int main()
{
    List l = creat();
    print(l);
    return 0;
}
