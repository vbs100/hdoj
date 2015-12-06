#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
	int n,i;
	char line[51];
	scanf("%d\n",&n);
	while(n--)
	{
		gets(line);
		if(!isalpha(line[0])&&line[0]!='_')
		{
			printf("no\n");
			continue;
		}
		for(i=1;line[i]!=0;i++)
		{
			
			if(!isalnum(line[i])&&line[i]!='_')
				break;
		}
		if(line[i]==0)
			printf("yes\n");
		else
			printf("no\n");
	}
}
