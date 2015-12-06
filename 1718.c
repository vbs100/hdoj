#include <stdio.h>
int main()
{
	int jacknum,jackmark;
	while(scanf("%d",&jacknum)!=EOF)
	{
		int num,mark,score[101]={0},i,rank;
		while(scanf("%d%d",&num,&mark)!=EOF&&(num||mark))
		{
			if(num==jacknum)
				jackmark=mark;
			score[mark]++;
		}
		for(i=100,rank=0;i>jackmark;i--)
			rank+=score[i];
		printf("%d\n",++rank);
	}
	return 0;
}
