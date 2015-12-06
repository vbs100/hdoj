#include <stdio.h>
#include <string.h>

/* BASE must in pow(10,k) */
#define BASE 10000
/* WIDTH=log10(BASE) */
#define WIDTH 4
#define PRTFMT "%04d"

typedef struct
{
	int len;
	int num[30];
}big_t;

int cmp(big_t *a, big_t *b)
{
	if(a->len>b->len)
		return 1;
	else if(a->len<b->len)
		return -1;
	else
	{
		int i=a->len-1;
		while(a->num[i]==b->num[i]&&i>0)
			i--;
		return a->num[i]-b->num[i];
	}
}

void big_add(big_t *a, big_t *b, big_t *c)
{
	int i=0,p=0;
	memset(c,0,sizeof(*c));
	while(i<a->len&&i<b->len)
	{

		c->num[i]=a->num[i]+b->num[i]+p;
		p=c->num[i]/BASE;
		c->num[i]=c->num[i]%BASE;
		c->len++;
		i++;
	}
	while(i<a->len)
	{
		c->num[i]=a->num[i]+p;
		p=c->num[i]/BASE;
		c->num[i]=c->num[i]%BASE;
		c->len++;
		i++;
	}
	while(i<b->len)
	{

		c->num[i]=b->num[i]+p;
		p=c->num[i]/BASE;
		c->num[i]=c->num[i]%BASE;
		c->len++;
		i++;
	}
	while(p)
	{
		c->num[i]=p;
		p=c->num[i]/BASE;
		c->num[i]=c->num[i]%BASE;
		c->len++;
		i++;
	}
}


/* buf changed after func */
int big_from_str(big_t *c, char *buf)
{
	char *p=buf;
	int len=strlen(buf);
	memset(c,0,sizeof(*c));
	for(p=buf+len;p-WIDTH>buf;p-=WIDTH)
	{
		c->len++;
		c->num[c->len-1]=atoi(p-WIDTH);
		*(p-WIDTH)=0;
	}
	c->len++;
	c->num[c->len-1]=atoi(buf);
	return 0;
}

big_t a,b,f[481]={0};
void init_tab()
{
	int i;
	f[1].num[0]=1;
	f[1].len=1;
	f[2].num[0]=1;
	f[2].len=1;
	for(i=3;i<=480;i++)
		big_add(&f[i-2],&f[i-1],&f[i]);
}

int main()
{
	char str1[128],str2[128];

	init_tab();
	while(scanf("%s %s",str1,str2)!=EOF)
	{
		int i,c;
		if(!(strcmp(str1,"0")||strcmp(str2,"0")))
			break;
		big_from_str(&a,str1);
		big_from_str(&b,str2);
		for(i=2,c=0;i<=480;i++)
		{
			if(cmp(&f[i],&a)<0)
				continue;
			if(cmp(&f[i],&b)>0)
				break;
			c++;
		}
		printf("%d\n",c);
	}
}
