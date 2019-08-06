#include <stdio.h>
#include <iostream>
#include <ctime>
using namespace std;
#define M 1000000
#define N 100
clock_t start,stop;
int Max(int n1,int n2)
{
    if(n1>n2)
        return n1;
    else return n2;
}
inline Max2(int n1,int n2) //内联
{
    if(n1>n2)
        return n1;
    else return n2;
}
int main()
{
    int a,b;
    start = clock();
    for(int i=0; i<M; i++)
        for(int j=0; j<N; j++)
        {
            a = Max(23,56);
        }
    stop = clock();
    cout << ((double)(stop-start)/CLK_TCK) <<endl;

    start = clock();
    for(int i=0; i<M; i++)
        for(int j=0; j<N; j++)
        {
            a = Max2(23,56);     //速度更快
        }
    stop = clock();
    cout << ((double)(stop-start)/CLK_TCK) <<endl;
    return 0;
}
