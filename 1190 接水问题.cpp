#include <cstdio>
int main ()
{
	int n, m, a[10000];
	scanf ("%d%d", &n, &m);
	for (int i = 0;i < n;i++)
	{
		scanf ("%d", &a[i]);
	}
	int s = 0, qs = 0;
	for (;;s++)
	{
		int i = qs;
		while (a[i] == 0 && i < n)
			i++;
		qs = i;
		int k = m;
		bool yes = true;
		for (i = qs;i < n;i++)
		{
			if (a[i] != 0)
			{
				yes = false;
				if (k != 0)
				{
					a[i]--;
					k--;
				}else
					break;
			}
		}
		if (yes)
			break;
	}
	printf ("%d", s);
	return 0;
}
