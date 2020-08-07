#include <cstdio>
int n, k, l[10000], sum = 0;
int check (int mid)
{
	int s = 0;
	for (int i = 0;i < n;i++)
	{
		s += l[i] / mid;
	}
	if (s >= k)
		return 1;
	else
		return 0;
}
int getans (int l, int r)
{
	while (l <= r)
	{
		int mid = (r + l) / 2;
		if (mid == 0)
			break;
		if (check(mid))
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
//		printf ("%d %d\n", l, r);
	}
	return r;
}
int main ()
{
	scanf ("%d%d", &n, &k);
	for (int i = 0;i < n;i++)
	{
		double x;
		scanf ("%lf", &x);
		l[i] = x * 100;
		sum += l[i];
	}
	int ans = getans (0, 10000000);
	printf ("%.2f", ans / 100.0);
}
