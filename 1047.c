
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


int big_to_str(big_t *n, char *buf, int len)
{
	int i=n->len-1,ret;
	char *p=buf;
	if(n->len<1)
		return -1;
	ret=sprintf(p,"%d",n->num[i--]);
	p+=ret;
	len-=ret;
	while(i>=0&&len>0)
	{
		ret=sprintf(p,PRTFMT,n->num[i--]);
		p+=ret;
		len-=ret;
	}
	if(len<0)
		return len;
	else
		return p-buf;
}

/* BUGS:buf changed after func */
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

int main()
{
	int n;
	char str1[128];;
	scanf("%d",&n);
	while(n--)
	{
		big_t a,sum={1,0};
		while(scanf("%s",str1)
		big_from_str(&a,str1);
	}
	while(scanf("%s%s",str1,str2)!=EOF)
	{
		big_from_str(&b,str2);
		big_mult(&a,&b,&c);
		big_to_str(&c,str3,256);
		printf("%s * %s = %s\n",str1,str2,str3);
	}
}
