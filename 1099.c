#include <stdio.h>
//a + b/c
typedef struct {
	long long a;
	long long b;
	long long c;
}fs_t;

fs_t fs_add(fs_t d1, fs_t d2)
{
	fs_t res;
	lldiv_t res1;
	res.a=d1.a+d2.a;
	res1=lldiv(d1.b*d2.c+d2.b*d1.c,d1.c*d2.c);
	res.a+=res1.quat;
	res.b=res
}

