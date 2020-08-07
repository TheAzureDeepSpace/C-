#include <cstdio>
int a[100], b[9], n = 0;
int dfs (int x, int sum)
{
	if (sum == n)
	{
		int i = 1;
		for (;i < x - 1;++i)
		{
			printf ("%d+", a[i]);
		}
		printf ("%d=%d\n", a[x - 1], sum);
		return 0;
	}
	for (int i = a[x - 1];i <= n - sum;++i)
	{
		a[x] = i;
		dfs (x + 1, sum + i);
	}
}
int main ()
{
	scanf ("%d", &n);
	dfs (1, 0);
	return 0;
}
