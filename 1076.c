#include <stdio.h>
int isleap(int year)
{
	return (year%4==0&&year%100!=0)||year%400==0;
}
int main()
{
	int count,year,nth;
	scanf("%d",&count);
	while(count--)
	{
		int t,base;
		scanf("%d%d",&year,&nth);
		if(isleap(year))
			base=year;
		else if(isleap(year+4-(year+4)%4))
			base=year+4-(year+4)%4;
		else
			base=year+8-(year+8)%4;
		for(t=1;t<=nth;)
		{
			if(t==nth)
			{
				printf("%d\n",base);
				break;
			}
			base+=4;
			if(isleap(base))
				t++;
		}
	}
}
