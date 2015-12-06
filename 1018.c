#include <stdio.h>
#include <math.h>
#ifdef ONLINE_JUDGE
#define M_PI		3.14159265358979323846 /* pi */
#define M_LN10		2.30258509299404568402 /* log_e 10 */
#define M_LOG10E	0.43429448190325182765 /* log_10 e */
#endif
int fact_digitE(int n)
{
	return ceil((0.5*log(2.0*M_PI*n)+n*log(n)-n)/M_LN10);
}
int fact_digit10(int n)
{
	return ceil(0.5*log10(2.0*M_PI*n)+n*log10(n)-n*M_LOG10E);
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n", fact_digitE(n));
	}
}
