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
        thisSum += n;    //向右累加
        if(thisSum>maxSum)
            maxSum = thisSum;   //更新
        else if(thisSum<0)
            thisSum = 0;        //抛弃

        c = getchar();
        if(c=='\n'){
            printf("%d\n",maxSum);
            break;
        }
    }
}
