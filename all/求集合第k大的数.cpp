//第k大
// 1基于排序
#include <stdio.h>
#define N 10

int find_kth_number(int* s,int k,int length) // 2基于问题分解
{
    int e = s[0];
    int s1[N],s2[N];
    int i;
    int cnt=0,cnt2=0;
    for(int i=1; i<length; i++)
    {
        if(s[i]>=e)
            s1[cnt++] = s[i];
        else
            s2[cnt2++] = s[i];
    }

    if(cnt>=k){
        return find_kth_number(s1,k,cnt);
    }
    else if(cnt<k-1){
        return find_kth_number(s2,k-cnt-1,cnt2);
    }
    else return e;

}
int main()
{
    int s[9] = {6,5,9,8,2,1,7,3,4};
    printf("%d\n", find_kth_number(s,1,sizeof(s)/sizeof(s[0])));
}
