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
	int num[400];
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

int main()
{
	int n;
	char str[2048];

	while(scanf("%d",&n)!=EOF)
       	{
		big_t f[5]={0};
		{
			int i;
			f[0].num[0]=1;
			f[0].len=1;
			f[1].num[0]=1;
			f[1].len=1;
			f[2].num[0]=1;
			f[2].len=1;
			f[3].num[0]=1;
			f[3].len=1;
			for(i=4;i<=n;i++)
			{
				big_t t1,t2;
				big_add(&f[(i-1)%5],&f[(i-2)%5],&t1);
				big_add(&f[(i-3)%5],&f[(i-4)%5],&t2);
				big_add(&t1,&t2,&f[i%5]);
			}
		}
		big_to_str(&f[(n-1)%5],str,sizeof(str));
		printf("%s\n",str);
	}
	return 0;
}
