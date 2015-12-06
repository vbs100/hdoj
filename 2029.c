#include <stdio.h>
#include <string.h>
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		int i,j,len;
		char str[120];
		scanf("%s", str);
		i=0;
		j=strlen(str)-1;
		while(i<j)
		{
			if(str[i]!=str[j])
				break;
			i++;
			j--;
		}
		if(i>=j)
			printf("yes\n");
		else
			printf("no\n");
	}
}
