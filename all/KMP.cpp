#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define FOR(i,n) for(int i=0; i<n; i++)

void prefix_table(char pattern[], int prefix[], int n)
{
    prefix[0] = 0;
    int len = 0;   //max匹配长度
    int i = 1;     //指向pattern[1]
    while( i<n )
    {
        if( pattern[i]==pattern[len] )
        {
            len++;
            prefix[i] = len;
            i++;
        }
        else
        {
            if(len>0)
                len = prefix[len-1];
            else
            {
                prefix[i] = 0;
                i++;
            }
        }
    }

}

void move_prfix_tabel(int prefix[], int n)
{
    for(int i=n-1; i>0; i--)
        prefix[i] = prefix[i-1];
    prefix[0] = -1;
}

void kmp_search(char text[], char pattren[])
{
    int n = strlen(pattren);
    int *prefix = new int[n];
    prefix_table(pattren, prefix, n);
    move_prfix_tabel(prefix, n);

    int i = 0, m = strlen(text); // text[i] , len = m
    int j = 0;
    while( i<m )
    {

        if( j==n-1 && text[i]==pattren[j] )
        {
            cnt++;
            j = prefix[j];
        }
        if( j==-1||text[i]==pattren[j] )
        {
            i++;
            j++;
        }
        else
        {
            j = prefix[j];
        }
  /*
        if( j==n-1 && text[i]==pattren[j] )
        {
            printf("%d\n", i-j);
            j = prefix[j];   //继续,j前已匹配
            if( j==-1 ){
                j++;i++;
            }
        }
        if( text[i]==pattren[j] )
        {
            i++; j++;
        }
        else
        {
            j = prefix[j];
            if( j==-1 )
            {
                i++; j++;
            }
        }
*/
    }
}
int main()
{
    char pattern[] = "A";
//    int prefix[9];
//    int n = 9;
//    prefix_table(pattern, prefix, n);
//    move_prfix_tabel(prefix, n);
//    FOR(i,n)
//        cout<<prefix[i]<<" ";
    char text[] = "ABABABCABAABABABAB";
    kmp_search(text, pattern);
    return 0;
}
