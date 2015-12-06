#include <stdio.h>
int gcd(int m,int n)
{
	if(m%n==0)
		return n;
	return gcd(n,m%n);
}
int main()
{
	int p,q;
	while(~scanf("%d%d",&q,&p))
		printf("%d\n",p+q-gcd(p,q));
}
