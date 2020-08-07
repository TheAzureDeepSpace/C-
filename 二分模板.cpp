#include <cstdio>
int n, m, a[100000], l, r;
int check (int mid);
{
}
int getans ()
{
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (check(mid))
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	return r;
}
int main ()
{
	int n, m;
	scanf ("%d%d", &n, &m);
	for (int i = 0;i < n;i++)
	{
		scanf ("%d", a[i]);
	}
	int ans = getans ();
	printf ("%d", ans);
}
