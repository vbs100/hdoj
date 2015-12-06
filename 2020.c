#include <stdio.h>
#include <stdlib.h>

int a[100];
int cmp(const void *d1, const void *d2)
{
	return abs(*(int *)d2) - abs(*(int*)d1);
}

int main()
{
	int n;
	while(scanf("%d",&n)&&n)
	{
		int i;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		qsort(&a, n, sizeof(int), &cmp);
		for(i=0;i<n-1;i++)
			printf("%d ",a[i]);
		printf("%d\n",a[n-1]);
	}
}
