#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char test1[5010],test2[5010];
int getcase(char *data, int len)
{
	char *p = data,*end;
	int state=-1;/* data 0, E 1, N 2, D 3 */
	fread(p, 6, 1, stdin);
	if(memcmp(p, "START\n", 6)!=0)
		return -1;

	do
	{
		fread(p, 1, 1, stdin);
		switch(state)
		{
			case -1:
				if(*p=='\n')
					state=0;
				break;
			case 0:
				if(*p=='E')
				{
					state=1;
					end=p;
				}
				else if(*p=='\n')
				{
					end=p;
				}
				else
					state=-1;
				break;
			case 1:
				if(*p=='N')
					state=2;
				else
					state=-1;
				break;
			case 2:
				if(*p=='D')
					state=3;
				else
					state=-1;
				break;
			case 3:
				if(*p=='\n')
					state=4;
				else
					state=-1;
				break;
			default:
				return -1;
		}
		p++;
	}while(state!=4&&p-data<=len);

	return end-data;
}

int compare(char *data1, int len1, char *data2, int len2)
{
	int err=0;
	char *p = data1;
	char *q = data2;
	while(1)
	{
		if(*p == *q)
		{
			p++;
			q++;
		}
		/*start space*/
		else if((*p==' '||*p=='\n'||*p=='\t') && (*q==' '||*q=='\n'||*q=='\t'))
		{
			p++;
			q++;
			err++;
		}
		else if(*p==' '||*p=='\n'||*p=='\t')
		{
			p++;
			err++;
		}
		else if(*q==' '||*q=='\n'||*q=='\t')
		{
			q++;
			err++;
		}
		else
			return 2;
		if(p==data1+len1&&q==data2+len2)
		{
			if(err)
				return 1;
			return 0;
		}
		/*end space*/
		if(p==data1+len1)
		{
			while((*q==' '||*q=='\n'||*q=='\t'))
				q++;

			if(q==data2+len2)
				return 1;
			else 
				return 2;
		}
		if(q==data2+len2)
		{
			while((*p==' '||*p=='\n'||*p=='\t'))
				q++;

			if(p==data1+len1)
				return 1;
			else 
				return 2;
		}
	}
}
int main()
{
	int i,n,ret,len1,len2;
	scanf("%d\n",&n);
	for(i=0;i<n;i++)
	{
		len1=getcase(test1,sizeof(test1));
		len2=getcase(test2,sizeof(test1));
		if(len1<0||len2<0)
		{
			printf("bug\n");
			return -1;
		}
		ret=compare(test1,len1,test2,len2);
		if(ret==0)
			printf("Accepted\n");
		else if(ret==1)
			printf("Presentation Error\n");
		else
			printf("Wrong Answer\n");
	}
}
