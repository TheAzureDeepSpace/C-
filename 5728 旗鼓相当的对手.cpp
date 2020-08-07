#include <cstdio>
int main()
{
	int a[100][3], n, ans = 0;
	scanf ("%d", &n);
	for (int i = 0;i < n;i++)
	{
		scanf ("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
	}
	for (int i = 0;i < n - 1;i++)
	{
		for (int j = i + 1;j < n;j++)
		{
			int sum = a[i][0] + a[i][1] + a[i][2];
			int sum2 = a[j][0] + a[j][1] + a[j][2];
			int t1 = a[i][0] - a[j][0];
			int t2 = a[i][1] - a[j][1];
			int t3 = a[i][2] - a[j][2];
			if (t1 <= 5 && t2 <= 5 && t3 <= 5 && sum - sum2 <= 10)
				ans++;
		}
	}
	printf ("%d", ans);
	return 0;
}
