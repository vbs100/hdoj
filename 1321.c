#include <stdio.h>
#include <string.h>
int main()
{
	char line[80];
	int n;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		int i,len;
		gets(line);
		len=strlen(line);
		for(i=len-1;i>=0;i--)
			printf("%c",line[i]);
		printf("\n");
	}
}
