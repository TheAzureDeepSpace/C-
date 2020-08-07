#include <cstdio>
int main ()
{
	int a[101], i;
	for (i = 0;a[i - 1] != 0;i++)
	{
		scanf("%d", &a[i]);
	}
	i -= 2;
	for (;i >= 0;i--)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
