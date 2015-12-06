#include <stdio.h>
int main()
{
	int t,h1,h2,m1,m2,s1,s2;
	scanf("%d",&t);
	while(t--)
	{
		int c=0;
		scanf("%d%d%d%d%d%d"
				,&h1,&m1,&s1 ,&h2,&m2,&s2);
		c=(s1+s2)/60;
		s1=(s1+s2)%60;
		m1+=m2+c;
		c=m1/60;
		m1%=60;
		h1+=h2+c;
		printf("%d %d %d\n",h1,m1,s1);
	}
	return 0;
}
