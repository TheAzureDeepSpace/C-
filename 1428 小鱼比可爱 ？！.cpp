#include <cstdio>
int main ()
{
	int n, a[101];
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0;i < n;i++)
	{
		int s = 0;
		for (int in = i;in >= 0;in--)
		{
			if (a[i] > a[in])
				s++;
		}
		printf("%d ", s);
	}
	return 0;
}
