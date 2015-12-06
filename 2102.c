#include <stdio.h>
int money[]={100,50,10,5,2,1};
int main()
{
	int n;
	while(scanf("%d",&n)&&n)
	{
		int i,a,count=0,sum=0;
		for(i=0;i<n;i++)
		{
			int j,t;
			scanf("%d",&a);
			for(j=0;j<6;j++)
			{
				t=a/money[j];
				a-=t*money[j];
				sum+=t;
			}
			
		}
		printf("%d\n",sum);
	}
	
}
