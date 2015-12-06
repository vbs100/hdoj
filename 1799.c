#include <stdio.h>
int c[2001][2001];
int combin(int n,int m)
{
	if(c[n][m])
		return c[n][m];
	if(m>n)
		return c[n][m]=0;
	if(m==0)
		return c[n][m]=1;
	else if(m==1)
		return c[n][m]=n%1007;
	else
		return c[n][m]=(combin(n-1,m-1)+combin(n-1,m))%1007;
}
int main()
{
	int t,m,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&n);
		printf("%d\n",combin(n,m));
	}
	return 0;
}
