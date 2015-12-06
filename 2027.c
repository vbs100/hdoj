#include <stdio.h>
int main ()
{
	int t, n = 1;
	scanf ("%d", &t);
	getchar();
	while (t--)
	{
		char line[112];
		int j = 0, a, e, i, o, u;
		a = e = i = o = u = 0;
		gets(line);
		do
		{
			switch (line[j++])
			{
				case 'a':
				case 'A':
					a++;
					break;
				case 'e':
				case 'E':
					e++;
					break;
				case 'i':
				case 'I':
					i++;
					break;
				case 'o':
				case 'O':
					o++;
					break;
				case 'u':
				case 'U':
					u++;
					break;
				default:
					break;
			}
		}
		while (line[j]);
		if (n != 1)
			printf ("\n");
		printf ("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n", a, e, i, o, u);
		n++;
	}
}
