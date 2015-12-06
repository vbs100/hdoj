#include <stdio.h>
#include <string.h>
//not complete
struct 
{
	int val;
}dp[1000];

int val[1000];
/* sum[a][b] a means a chessmen before
   b means chessmen val until b */
int sum[1000],lmax,nmax,nmin;
int main()
{
	int n,i,j;
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&val[i]);
		memset(dp,0,sizeof(dp));
		printf("%d\n",max);

	}
}
