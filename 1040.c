#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int t,n,i,a[1000];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		qsort(a,n,sizeof(int),cmp);
		printf("%d",a[0]);
		for(i=1;i<n;i++)
			printf(" %d",a[i]);
		printf("\n");
	}
}
