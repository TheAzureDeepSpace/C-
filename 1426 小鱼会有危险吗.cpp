#include <cstdio>
int main ()
{
	double m = 7;
	int s, n;
	scanf("%d%d", &s, &n);
	for (int i = 0;s > 0;i++)
	{
		s -= m;
		m *= 0.98;
	}
	if (m > n * 2)
		printf("n");
	else printf("y");
}
