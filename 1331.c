#include <stdio.h>
int ans[21][21][21];
void solve()
{
	int a,b,c;
	for(a=0;a<=20;a++)
	for(b=0;b<=20;b++)
	for(c=0;c<=20;c++)
		if(a==0||b==0||c==0)
			ans[a][b][c]=1;
	for(a=1;a<=20;a++)
	for(b=1;b<=20;b++)
	for(c=1;c<=20;c++)
		ans[a][b][c]=w(a,b,c);
}
int w(int a,int b,int c)
{
	if(a<=0||b<=0||c<=0) return 1;
	else if(a>20||b>20||c>20) 
		return ans[20][20][20];
	else if(a<b&&b<c)
	       	return ans[a][b][c-1]
			+ans[a][b-1][c-1]
			-ans[a][b-1][c];
	return ans[a-1][b][c]
		+ans[a-1][b-1][c]
		+ans[a-1][b][c-1]
		-ans[a-1][b-1][c-1];
}


int main()
{
	int a,b,c;
	solve();
	while(scanf("%d%d%d",&a,&b,&c)&&!(a==-1&&b==-1&&c==-1))
		printf("w(%d, %d, %d) = %d\n",a,b,c,w(a,b,c));
	return 0;
}
