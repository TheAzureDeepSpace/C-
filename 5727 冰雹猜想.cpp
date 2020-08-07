#include <cstdio>
int main()
{
	int n, i = 0;
	scanf ("%d", &n);
	int can[1000];
	can[i] = n;
	for (;n != 1;)
	{
		if (n % 2)
			n = n * 3 + 1, can[++i] = n;
		else
			n /= 2, can[++i] = n;
	}
	printf ("1 ");
	while (i--)
		printf ("%d ", can[i]);
}
