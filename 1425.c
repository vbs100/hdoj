#include <stdio.h>
#include <stdlib.h>

int a[1000000];
int cmp(const void *d1, const void *d2)
{
	return *(int *)d2 - *(int*)d1;
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int i;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		qsort(&a, n, sizeof(int), &cmp);
		for(i=0;i<m-1;i++)
			printf("%d ",a[i]);
		printf("%d\n",a[m-1]);
	}
}
