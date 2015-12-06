#include <stdio.h>

#define BASE 10000

int ans[10000];

void mult(int c[], int k)
{
	int i,p=0;
	for(i=1;i<=c[0];i++)
	{
		c[i]=c[i]*k+p;
		p=c[i]/BASE;
		c[i]=c[i]%BASE;
	}
	while(p)
	{
		c[++c[0]]=p%BASE;
		p/=BASE;
	}
}

int fact(int n)
{
	int i;
	ans[0]=1;
	ans[1]=1;
	for(i=2;i<=n;i++)
		mult(ans,i);
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i;
		fact(n);
		printf("%d",ans[ans[0]]);
		for(i=ans[0]-1;i>=1;i--)
			printf("%04d",ans[i]);
		printf("\n");
	}
}
