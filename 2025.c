#include <stdio.h>
#include <string.h>
int main()
{
	char s[101],c;
	while(scanf("%s",s)!=EOF)
	{
		int i,len;
		len=strlen(s);
		for(i=0,c=s[0];i<len;i++)
			if(c<s[i])
				c=s[i];
		for(i=0;i<len;i++)
		{
			printf("%c",s[i]);
			if(s[i]==c)
				printf("(max)");
		}
		printf("\n");
	}
}
