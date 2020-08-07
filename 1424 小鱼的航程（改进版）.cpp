#include <cstdio>
int main ()
{
	int x, n, m = 0;
	scanf("%d%d", &x, &n);
	for (int i = 0;i < n;i++)
	{
		if (x == 8)
			x = 1;
		if (x != 6 && x!= 7)
			m += 250;
		x++;
	}
	printf("%d", m);
}
