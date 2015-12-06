#include <stdio.h>
int pow_mod(int a,int b,int mod)
{
	int ans=1,t=a%mod;
	while(b)
	{
		if(b&1)
			ans=(ans%mod)*(t%mod);
		t=(t%mod)*(t%mod);
		b>>=1;
	}
	return ans%mod;
}
int main()
{
	int a,b;
	while(~scanf("%d%d",&a,&b)&&a&&b)
		printf("%d\n",pow_mod(a,b,1000));
	return 0;
}
