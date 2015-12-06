#include <stdio.h>
int main()
{
	char a[10001];
	int b;
	while(scanf("%s %d",a,&b)!=EOF)
	{
		int i,s;
		for(i=0,s=0;a[i];i++)
		{
			s=s*10+a[i]-'0';
			s%=b;
		}
		printf("%d\n",s);
	}
}
