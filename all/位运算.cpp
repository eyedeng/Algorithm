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

        n |= 0xff;   // ��n�Ͱ�λ��1
        cout<<n<<endl;;
        bin(n);
        printf("\n\n");

        tn &= 0x80;  //�ж�n��7λ�Ƿ�Ϊ1 (1000 0000)
        if(tn==0)
            cout<<"not"<<endl;
        else
            bin(tn);
    }
    return 0;
}
