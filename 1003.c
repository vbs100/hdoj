#include <stdio.h>
int a[100001];
int maxsum(int *from, int to)
{
	int i,p=*from,q=to;
	int sum=0,max=a[q];
	for(i=q;i>=p;i--)
	{
		sum+=a[i];
		if(max<sum)
		{
			max=sum;
			*from=i;
		}
	}	
	return max;
}

int main()
{
	int t,n=1;;
	scanf("%d",&t);
	while(t--)
	{
		int i,max,p,q,tmax,tp;
		scanf("%d",&a[0]);
		for(i=1;i<=a[0];i++)
			scanf("%d",&a[i]);

		max=a[1];
		q=p=1;
		for(i=2;i<=a[0];i++)
		{
			tp=p;
			tmax=maxsum(&tp,i);
			if(tmax>max)
			{
				max=tmax;
				p=tp;
				q=i;
			}
		}
		if(n>1)
			printf("\n");
		printf("Case %d:\n%d %d %d\n", n++,max,p,q);
	}
}
