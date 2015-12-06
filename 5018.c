#include <stdio.h>
int main()
{
	int a,b,c,t;
	scanf("%d",&t);
	while(t--)
	{
		int f,flag=0;
		scanf("%d%d%d",&a,&b,&c);
		if(c==a||c==b)
			flag=1;
		else do
		{
			f=a+b;
			a=b;
			b=f;
			if(f==c)
			{
				flag=1;
				break;
			}
		}while(f<c);
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
			
	}
}
