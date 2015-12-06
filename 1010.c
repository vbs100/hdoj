#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char maze[8][8];
int n,m,t,dx,dy;

int dfs(int x,int y,int left)
{
	int ret;
	if(left==0)
	{
		if(maze[x][y]=='D')
			return 1;
		return 0;
	}
//	printf("maze[%d][%d]=%c\n",x,y,maze[x][y]);
	if(x<0||y<0||x==n||y==m||maze[x][y]=='X'||maze[x][y]=='D')
		return 0;
	if(left-(abs(dx-x)+abs(dy-y))<0)
		return 0;
	if(left%2-(abs(dx-x)+abs(dy-y))%2)
		return 0;

	maze[x][y]='X';
	ret=dfs(x+1,y,left-1);
	if(ret)
		return ret;
	ret=dfs(x-1,y,left-1);
	if(ret)
		return ret;
	ret=dfs(x,y+1,left-1);
	if(ret)
		return ret;
	ret=dfs(x,y-1,left-1);
	if(ret)
		return ret;
	maze[x][y]='.';
	return 0;
}

int main()
{
	while(~scanf("%d%d%d",&n,&m,&t)&&n&&m&&t)
	{
		int i,j,x,y;
		for(i=0;i<n;i++)
		{
			char *c;
			scanf("%s",maze[i]);
			c=strchr(maze[i],'S');
			if(c!=NULL)
			{
				x=i;
				y=c-maze[i];
			}
			c=strchr(maze[i],'D');
			if(c!=NULL)
			{
				dx=i;
				dy=c-maze[i];
			}
		}
		if( dfs(x,y,t) )
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
