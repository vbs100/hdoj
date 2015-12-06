#include <stdio.h>
int dn[1000064];
int d(int n)
{
	int sum=n;
	while(n)
	{
		sum+=n%10;
		n/=10;
	}
	return sum;
}
int main()
{
	int i;
	for(i=1;i<=1000000;i++)
		dn[d(i)]=1;
	for(i=1;i<=1000000;i++)
		if(!dn[i])
			printf("%d\n",i);
}
