#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <windows.h>
#include <stack>
using namespace std;
#define FOR(i,n) for(int i=0; i<n; i++)
typedef struct Node * pNode;
char OP[7] = {'+','-','*','/','(',')','='};
int priority[7][7] =     //1:���ڣ�2:С�ڣ�3:���ڣ�0:��
{
	{ 1, 1, 2, 2, 2, 1, 1 },  //��ջ���������������char ��
	{ 1, 1, 2, 2, 2, 1, 1 },
	{ 1, 1, 1, 1, 2, 1, 1 },
	{ 1, 1, 1, 1, 2, 1, 1 },
	{ 2, 2, 2, 2, 2, 3, 0 },
	{ 1, 1, 1, 1, 0, 1, 1 },
	{ 2, 2, 2, 2, 2, 0, 3 }
};
int get_pri(char c1,char c2)
{
    int i,j;
    FOR(k,7)
    {
       if(OP[k]==c1)
            i = k;
       if(OP[k]==c2)
            j = k;
    }
    return priority[i][j];
}
void trans(char *s)    // ��׺ת��׺
{
    stack<char>op_tor;
    int l,r;
    op_tor.push('=');
    for(int i=0; s[i]!='='; i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            printf("%c", s[i]);    // ������ֱ�����
        }
        else
        {
            switch(get_pri(op_tor.top(),s[i]))
            {
            case 1:
                printf("%c", op_tor.top());
                op_tor.pop();
                i--;
                break;
            case 2:
                op_tor.push(s[i]);
                break;
            case 3:
                op_tor.pop();  //���� ( =
                break;
            }
            ;
        }
    }
    while(op_tor.size()>=2)
    {
        printf("%c", op_tor.top());
        op_tor.pop();
    }
    printf("\n");
}
int main()
{
    char s[10000];
    while(scanf("%s", s))
    {
        if(s[0]=='=')
            break;
        trans(s);
    }
    return 0;
}
