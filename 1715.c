#include <stdio.h>
#include <string.h>

/* BASE must in pow(10,k) */
#define BASE 100000000
/* WIDTH=log10(BASE) */
#define WIDTH 8
#define PRTFMT "%08d"

typedef struct
{
	int len;
	int num[31];
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


big_t f[1001]={0};
void init_tab()
{
	int i;
	f[1].num[0]=1;
	f[1].len=1;
	f[2].num[0]=1;
	f[2].len=1;
	for(i=3;i<=1000;i++)
		big_add(&f[i-2],&f[i-1],&f[i]);
}

int main()
{
	int i,t,n;
	char str[256];

	init_tab();

	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		big_to_str(&f[n],str,sizeof(str));
		printf("%s\n",str);
	}
	return 0;
}
