#include <stdio.h>
int main()
{
	int t,n,ans;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		while(n)
		{
			ans+=n/5;
			n/=5;
		}
		printf("%d\n",ans);
	}
}
