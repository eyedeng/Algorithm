#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define M 500
int main()
{
	int i,j,k,l;
	int ret=0;
	for(i=0; i<=M/5; i++)
		for(j=0; j<=M/10; j++)
			for(k=0; k<=M/25; k++)
				for(l=0; l<=M; l++)
					if(M==5*i+10*j+25*k+1*l) {
						//printf("5:%d 10:%d 25:%d 1:%d\n",i,j,k,l);
						ret++; 
					} 
	printf("%d\n",ret);		//242	142511 13s
	return 0;
 } 
