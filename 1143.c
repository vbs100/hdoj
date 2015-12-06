#include <stdio.h>
int func(int n)
{
	if(n%2)
		return 0;
	else if(n==0)
		return 1;
	else if(n==2)
		return 3;
	else 
		return 4*func(n-2)-func(n-4);
}

int main()
{
	int n;
	while(~scanf("%d",&n)&&~n)
		printf("%d\n",func(n));
}
