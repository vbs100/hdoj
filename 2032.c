#include <stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i,j;
		int a[30]={1};
		for(i=0;i<n;i++)
		{
			for(a[i]=1,j=i-1;j>=1;j--)
				a[j]+=a[j-1];

			printf("1");
			for(j=1;j<=i;j++)
				printf(" %d", a[j]);
			printf("\n");
		}
		printf("\n");
	}
}

