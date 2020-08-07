#include <cstdio>
int main ()
{
	int a[10001], n, s = 0;
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{
		scanf("%d", &a[i]);
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
				s++;
			}
		}
	}
	printf("%d", s);
}
