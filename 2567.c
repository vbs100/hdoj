#include <stdio.h>
#include <string.h>
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		char a[64];
		char b[64];
		int len,i;
		gets(a);
		gets(b);
		len=strlen(a);
		for(i=0;i<len/2;i++)
			printf("%c",a[i]);
		printf("%s",b);
		puts(a+len/2);
	}
}
