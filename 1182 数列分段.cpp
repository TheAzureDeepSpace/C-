#include <cstdio>
int n, m, a[100000], l = 0, r = 0;
bool check (int x)
{
	int tot = 0, s = 0;
	for (int i = 0;i < n;i++)
	{
		if (tot + a[i] <= x)
		{
			tot += a[i];
		}
		else
		{
			tot = a[i], s++;
		}
		
	}
	return s >= m;
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
//		printf ("%d %d\n", l, r);
	}
	return l;
}
int main ()
{
	scanf ("%d%d", &n, &m);
	for (int i = 0;i < n;i++)
	{
		scanf ("%d", &a[i]);
		r += a[i];
		l = l > a[i] ? l : a[i];
	}
	int ans = getans ();
	printf ("%d", l);
}
