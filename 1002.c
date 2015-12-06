#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char a[1001],b[1001],c[1001];
int main()
{
	int i,j,k,n,ma,mb,max;
	char *p;
	scanf("%d", &n);
	for(i=1;i<=n;i++)
	{
		memset(c,0,1001);
		scanf("%s %s",a,b);
		ma=strlen(a)-1;
		mb=strlen(b)-1;
		max=ma>mb?ma:mb;
		for(k=0;k<=max;k++)
		{
			if(ma-k>=0 && a[ma-k]>0)
				c[max-k+1] += a[ma-k]-'0';
			if(mb-k>=0 && b[mb-k]>0)
				c[max-k+1] += b[mb-k]-'0';
			if(c[max-k+1]>9)
			{
				c[max-k+1]-=10;
				c[max-k]++;
			}
			c[max-k+1]+='0';
		}
		if(c[0]>0)
		{
			c[0]+='0';
			p=&c[0];
		}
		else
			p=&c[1];
		while(*p=='0'&&*(p+1)!=0) p++;

		if(i>1)
			printf("\n");
		printf("Case %d:\n",i);
		printf("%s + %s = %s\n", a, b, p);
	}
}
