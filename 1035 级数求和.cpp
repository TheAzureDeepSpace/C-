#include <cstdio>
int main ()
{
	int k, n;
	double s;
	scanf("%d", &k);
	for (n = 1;s <= k;n++)
	{
		s += 1.0 / n;
//		printf("%lf %d\n", s, n);
	}
	n--;
	printf("%d", n);
	return 0;
}
