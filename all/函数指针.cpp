#include <stdio.h>
#include <stdlib.h>

void printMin(int a,int b)
{
    printf("%d\n", a<b? a:b);
}
int pfComp(const void *a,const void *b)
{
    int *p1,*p2;
    p1 = (int* )a;p2 = (int* )b;
    return *p1-*p2;
}
int main()
{
    void (*pf)(int,int) = NULL;
    pf = printMin;
    int x=6,y=5;
    pf(x,y);

    int arr[10] = {2,4,3,5,7,6,8,1,9,0};
    qsort(arr,10,sizeof(arr[0]),pfComp);
    for(int n:arr)
        printf("%d ",n);
    return 0;
}
