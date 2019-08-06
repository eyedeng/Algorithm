#include <stack>
#include <iostream>
#include <math.h>
using namespace std;
class Stack
{
public:

    int *base;
    int N;
    Stack(int c):base(new int[c]),N(0) {};
    void push(int e)
    {
        base[N++] = e;
    }
    int top()
    {
        return base[N-1];
    }
    void pop()
    {
        N--;
    }
    bool empty()
    {
        return N==0;
    }
    void show()
    {
        for(int i=0; i<N; i++)
            printf("%d ",base[i]);
        printf("\n");
    }
};
void binary(int n)
{
    //stack<int> bi;
    Stack bi(100);
    while(n)
    {
        bi.push(n&1);
        n = n>>1;
    }
    while(!bi.empty()){
        cout<<bi.top();
        bi.pop();
    } cout<<endl;

}
void LitBinary(double x)
{
    for(int i=0; i<20; i++)
    {
        if( abs(x-0.0)<0.001)
        {
            cout<<"__"<<i<<endl;
            return;
        }
        x *= 2;
        if( x>=1.0 )
        {
            cout<<1;
            x -= 1;
        }
        else
            cout<<0;

    }
}
int main()
{
    double x;
    while(cin>>x)
    {
        LitBinary(x);
    }
    int dn;
    while(cin>>dn && dn>=0 )
    {
        binary(dn);
    }
}
