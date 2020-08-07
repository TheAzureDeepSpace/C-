#include <cstdio>
long int a[1000000];
int main ()
{
	long int n, maxing = 0, max = 0;
	scanf ("%ld", &n);
	for (int i = 0;i < n;i++)
	{
		scanf ("%d", &a[i]);
		if (a[i] > a[i - 1])
		{
			maxing++;
		}
		else
		{
			max = maxing > max ? maxing : max;
			maxing = 0;
		}
	}
	printf ("%ld", max + 1);
	return 0;
}
