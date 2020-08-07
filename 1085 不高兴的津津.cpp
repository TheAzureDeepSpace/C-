#include <cstdio>
int main ()
{
	int a[7], max = 0, maxday;
	for (int i = 0;i < 7;i++)
	{
		int s;
		scanf("%d%d", &a[i], &s);
		a[i] += s;
		if (max < a[i])
		{
			max = a[i];
			maxday = i;
		}
	}
	printf("%d", maxday + 1);
}
