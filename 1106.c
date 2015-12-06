#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
int main()
{
	char line[1024], *p;
	int a[1024],len,i;
	while(gets(line)!=NULL)
	{
		for(len=0,p=strtok(line,"5");p!=NULL;p=strtok(NULL,"5"))
			a[len++]=atoi(p);
		qsort(&a, len, sizeof(int), &cmp);
		for(i=0;i<len-1;i++)
			printf("%d ", a[i]);
		printf("%d\n", a[len-1]);
	}
}
