#include <stdio.h>
struct 
{
	int n;
	int num;
	int pos;
} ans[100];
int fix(int guess,int index)
{
	int i,j,k;
	char src[5],dst[5];
	sprintf(src,"%d",guess);
	sprintf(dst,"%d",ans[index].n);
	for(i=0,k=0;i<4;i++)
		if(src[i]==dst[i])
			k++;
	if(k!=ans[index].pos)
		return 0;
	k=0;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(src[i]==dst[j])
			{
				k++;
				dst[j]=-1;
				break;
			}
	
	if(k!=ans[index].num)
		return 0;
	return 1;
}
int main()
{
	int n;
	while(scanf("%d",&n)&&n)
	{
		int i,j,find=0,key;
		for(i=0;i<n;i++)
			scanf("%d%d%d",&ans[i].n,&ans[i].num,&ans[i].pos);
		for(i=1000;i<=9999;i++)
		{
			for(j=0;j<n;j++)
				if(!fix(i,j))
					break;
			if(j==n)
			{
				find++;
				key=i;
			}
		}
		if(find==1)
			printf("%d\n",key);
		else
			printf("Not sure\n");
	}
}
