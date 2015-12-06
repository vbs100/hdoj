#include <stdio.h>
int cmp(const void *d1,const void *d2)
{
	return *(int *)d1-*(int *)d2;
}
int main()
{
	int n,cn[100],jp[100];
	while(scanf("%d",&n)&&n)
	{
		int i,retcn,retjp;
		for(i=0;i<n;i++)
			scanf("%d",&cn[i]);
		for(i=0;i<n;i++)
			scanf("%d",&jp[i]);
		qsort(cn,n,sizeof(int),cmp);
		qsort(jp,n,sizeof(int),cmp);

		retcn=retjp=0;
		for(i=0;i<n;i++)
		{
			if(cn[i]>jp[i])
				retcn+=2;
			else if(cn[i]<jp[i])
				retjp+=2;
			else
			{
				retcn++;
				retjp++;
			}

		}
		printf("%d vs %d\n",retcn,retjp);
	}
}
