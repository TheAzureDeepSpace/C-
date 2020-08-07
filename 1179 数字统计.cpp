#include <cstdio>
int main ()
{
	int l, r, c = 0;
	scanf ("%d%d", &l, &r);
	for (int i = l;i <= r;i++)
	{
		int s = i;2
		while (s)
		{
			if (s % 10 == 2)
				c++;
			s /= 10;
		}
	}
	printf ("%d", c);
	return 0;
}
