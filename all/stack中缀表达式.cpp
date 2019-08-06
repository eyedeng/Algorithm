#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <stack>
//#include <windows.h>
using namespace std;
#define FOR(i,n) for(int i=0; i<n; i++)
stack<double> op_and;
stack<char> op_tor;
char OP[7] = {'+','-','*','/','(',')','='};
int priority[7][7] =     //1:大于，2:小于，3:等于，0:无
{
	{ 1, 1, 2, 2, 2, 1, 1 },  //左（栈顶）操作符与读入char 比
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
double ans(double r,char c,double l)
{
    switch (c)
    {
    case '+':
        return l+r;
        break;
    case '-':
        return l-r;
        break;
    case '*':
        return l*r;
        break;
    case '/':
        return l/r;
        break;
    default:
        break;
    }

}
double calcu(char *s)
{
    double val = 0;
    int pre = 0;    //前面为数字
    int point = 0;  //数在点后
    double topL,topR;
    op_tor.push('=');  //读入第一个操作符可有与之比较
    for(int i=0; s[i]!='='||op_tor.top()!='='; i++) // 或条件
    {
        if( s[i]=='.' )
        {
            point = 1;
        }
        else if( s[i]>='0'&&s[i]<='9' ) //每个操作数读全后直接入栈
        {
            if(pre)
            {
                if(point)
                {
                    val = op_and.top();
                    op_and.pop();
                    double t = s[i]-'0';
                    FOR(i,point)
                        t *= 0.1;
                    op_and.push(val+t);
                    point++;
                }
                else
                {
                    point = 0;
                    val = op_and.top();
                    op_and.pop();
                    val *= 10;
                    op_and.push(val+s[i]-'0');
                }

            }
            else
                op_and.push(s[i]-'0');
            pre = 1;
        }
        else
        {
            switch(get_pri(op_tor.top(),s[i]))
            {
            case 1:
                topR = op_and.top();
                op_and.pop();
                topL = op_and.top();
                op_and.pop();
                op_and.push(ans(topR, op_tor.top(),topL));
                op_tor.pop();
                i--;   //不读下一字符
                break;
            case 2:
                op_tor.push(s[i]);
                break;
            case 3:
                op_tor.pop();  //弹出 ( =
                break;
            }
            ;
            pre = point = 0;
        }
    }
    return op_and.top();
}

int main()
{
    char s[1000];
    while(scanf("%s", s))
    {
        while(!op_and.empty())
        {
            //cout<<op_and.top()<<" ";
            op_and.pop();
        }
        while(!op_tor.empty())
        {
            //cout<<op_tor.top()<<" ";
            op_tor.pop();
        }
        if(s[0]=='=')
            break;
        printf("%.2f\n",calcu(s));
    }
    return 0;
}
