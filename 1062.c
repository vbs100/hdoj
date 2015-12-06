#include<stdio.h>
void str_reverse(char *s,char *t)
{
	while(s<t)
	{
		*s^=*t;
		*t^=*s;
		*s^=*t;
		s++;
		t--;
	}
}

char *ws(char *s)
{
	while(*s==' ')
		s++;
	return s;
}

char *we(char *s)
{
	while(*(s+1)!='\0'&&*(s+1)!=' ')
		s++;
	return s;
}

void text_reverse(char *p)
{
	char *s,*t;
	for(s=ws(p),t=we(s); *s&&*t; s=ws(t+1),t=we(s))
		str_reverse(s,t);
}

int main()
{
	int t;
	char line[1024];
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		gets(line);
		text_reverse(line);
		puts(line);
	}
	return 0;
}
