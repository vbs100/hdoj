#include <stdio.h>
long long cubesum(long long m, long long n)
{
	return ( n*(n+1)/2 ) * ( n*(n+1)/2 ) - ( m*(m-1)/2 ) * ( m*(m-1)/2 );
}

int main()
{
	long long m,n;
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
#ifdef ONLINE_JUDGE
		scanf("%I64d%I64d",&m,&n);
		printf("Case #%d: %I64d\n",i,cubesum(m,n));
#else
		scanf("%lld%lld",&m,&n);
		printf("Case #%d: %lld\n",i,cubesum(m,n));
#endif
	}
}
