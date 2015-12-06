#include <stdio.h>
char num[16]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
int main()
{
	int n,r;
	int ans[20];
	while(scanf("%d%d",&n,&r)!=EOF)
	{
		int i,m=0,flag=0;
		if(n<0)
		{
			n=-n;
			flag=1;
		}
		while(n)
		{
			ans[m++]=n%r;
			n=n/r;
		}
		if(flag)
			printf("-");
		for(i=m-1;i>=0;i--)
			printf("%c",num[ans[i]]);
		printf("\n");
	}
}
