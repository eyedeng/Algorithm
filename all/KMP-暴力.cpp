#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int violentMatch(char *s,char *p) //文本串s,模式串p
{
    int sLen = strlen(s);
    int pLen = strlen(p);
    int i=0,j=0;
    while(i<sLen && j<pLen)
    {
        if(s[i]==p[j]){
            i++,j++;
        }
        else{
            i = i-j+1;
            j = 0;
        }
    }
    if(j==pLen)
        return i-j;
    else
        return -1;
}
int main()
{
    char s[1000],p[1000];
    while(scanf("%s%s",s,p))
    {
        printf("%d\n",violentMatch(s,p));
    }
}
