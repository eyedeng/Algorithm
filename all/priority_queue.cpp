#include<iostream>
#include<queue>
using namespace std;
//struct Node
//{
//    int x;
//} d;
//bool operator <(Node a1,Node a2)
//{
//    return a1.x < a2.x ;
//}

int main()
{
    int a[5]={3,5,2,4,9};
    priority_queue<int> pq;
    for(int i=0; i<5; i++)
        pq.push(a[i]);
    for(int i=0; i<5; i++)
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    //priority_queue <int,vector<int>,less<int> > p;
    priority_queue <int,vector<int>,greater<int> > p;
    for(int i=0; i<5; i++)
        p.push(a[i]);
    for(int i=0; i<5; i++)
    {
        cout<<p.top()<<" ";
        p.pop();
    }
    return 0;
}
