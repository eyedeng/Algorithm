#include <stdio.h>
#include <iostream>
using namespace std;

void bin(int n)
{
    if(n)
        bin(n/2);
    else
        return;
    printf("%d",n%2);
}
int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        int tn = n;
        printf("%0x  %d  %o\n",n,n,n);
        bin(n);
        printf("\n\n");

        n |= 0xff;   // 将n低八位置1
        cout<<n<<endl;;
        bin(n);
        printf("\n\n");

        tn &= 0x80;  //判断n第7位是否为1 (1000 0000)
        if(tn==0)
            cout<<"not"<<endl;
        else
            bin(tn);
    }
    return 0;
}
