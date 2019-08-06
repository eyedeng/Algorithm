#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int maxlen[1001][1001];	 //dp ״̬ 
int main()			// s1���i���ַ��γ��ִ��� 
{					// s2    j�� 			����������г��� 
	char s1[1001],s2[1001];                  	//#������# 
	int i,j;							 
	
	while(scanf("%s%s",s1,s2) != EOF)
	{
		int len1 = strlen(s1);
		int len2 = strlen(s2);		
		for(i=0; i<max(len1,len2); i++)  //#��ʼ�߽�����# 
		{
			maxlen[i][0] = 0;
			maxlen[0][i] = 0;
		}
		
		for(i=1; i<=len1; i++)
		{
		
			for(j=1; j<=len2; j++)
			{									//#״̬ת�Ʒ���#	
				if(s1[i-1]==s2[j-1]){
					maxlen[i][j] = maxlen[i-1][j-1]+1;
				}
				else{
					maxlen[i][j] = max(maxlen[i][j-1],maxlen[i-1][j]); //key
				}
			}			
		}
		printf("%d\n",maxlen[len1][len2]);
				
	}


	return 0;
}
