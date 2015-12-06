#include <stdio.h>
#define _INT_MIN -2147483648
int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		int d,i,j,mi,mj,find=0,max;
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
			{
				scanf("%d",&d);
				if(i+j==2)
				{
					max=d;
					mi=i;
					mj=j;
					continue;
				}
				if(find==1)
					continue;
				if(d==_INT_MIN)
				{
					find=1;
					mi=i;
					mj=j;
					max=d;
					continue;
				}
				if(find!=2&&abs(d)==abs(_INT_MIN+1))
				{
					find=2;
					mi=i;
					mj=j;
					max=d;
					continue;
				}
				if(abs(d)>abs(max))
				{
					mi=i;
					mj=j;
					max=d;
				}
			}
		printf("%d %d %d\n",mi,mj,max);
	}
}
