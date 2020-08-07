#include <cstdio>
#include <algorithm>
int main()
{
	int a[1000], n;
	scanf ("%d", &n);
	for (int i = 0;i < n;i++)
		scanf ("%d", &a[i]);
	std::sort(a, a + n);
	while (n--)
	{
		printf ("%d", a[n]);
	}
}
