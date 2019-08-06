#include <stdio.h>
typedef int (*math_fun)(int,int);  //º¯ÊýÖ¸Õë
int Max(int a,int b)
{
    return a>b?a:b;
}
//int Max2(int (*ptr_call)(int a,int b),int x)
  int Max2(math_fun f,int x)
{
    int t = 10;
    //return ptr_call(t,x);
    return f(t,x);
}

typedef struct Node* List;
struct Node
{
    int x;
    //struct Node* next;
    List next;
};
int main()
{
    Node n,n2;
    n.x = 10;
    n2.x = 20;
    n.next = &n2;
    printf("%d\n",n.x);

    printf("%d\n", Max2(&Max,11));
    typedef char* PCHAR;
    PCHAR pa,pb;
    char s1[10];
    scanf("%s",s1);
    pb = s1;
    printf("%s.\n",pb);
    return 0;
}
