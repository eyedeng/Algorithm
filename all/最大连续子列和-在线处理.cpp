#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    char c;
    int maxSum=0,thisSum=0;
    while(1)
    {
        scanf("%d", &n);
        thisSum += n;    //�����ۼ�
        if(thisSum>maxSum)
            maxSum = thisSum;   //����
        else if(thisSum<0)
            thisSum = 0;        //����

        c = getchar();
        if(c=='\n'){
            printf("%d\n",maxSum);
            break;
        }
    }
}
