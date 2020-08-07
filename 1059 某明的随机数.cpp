#include <cstdio>
int main ()
{
	int n, a[101], m = 0;
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{
		scanf("%d", &a[i]);
	}
	m = n;
	for (int i = 0;i < n - 1;i++)
	{
		for (int in = 0;in < n - 1 - i;in++)
		{
			if (a[i] == a[in] && a[in] != 0 && i != in)
			{
				a[in] = 0;
				m--;
			}
		}
	}
	for (int i = 0;i < n - 1;i++)
	{
		for (int in = 0;in < n - 1 - i;in++)
		{
			if (a[in] > a[in + 1])
			{
				int t = a[in];
				a[in] = a[in + 1];
				a[in + 1] = t;
			}
		}
	}
	printf("%d\n", m);
	for (int i = 0;i < n;i++)
	{
		if (a[i] != 0)
			printf("%d ", a[i]);
	}
}

