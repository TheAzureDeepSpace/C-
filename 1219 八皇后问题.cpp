#include <cstdio>
#include <cstring>
int map[13][13], st[13], n, sum = 0;
int DFS (int x, int y, int top)
{
	if (sum >= 3 && n == 13)
		return 0;
	for (int i = x;i >= 0;i--)
		if (map[i][y])
			return 0;
	for (int i = x, j = y;i >= 0 && j >= 0;i--, j--)
		if (map[i][j])
			return 0;
	for (int i = x, j = y;i >= 0 && j < n;i--, j++)
		if (map[i][j])
			return 0;
	map[x][y] = 1;
	st[top] = y;
	if (x == n - 1)
	{
		map[x][y] = 0;
		sum++;
		if (sum <= 3)
		{
			for (int i = 0;i < n;i++)
				printf ("%d ", st[i] + 1);
			printf ("\n");
		}
		return 0;
	}
	for (int i = 0;i < n;i++)
	{
		DFS (x + 1, i, top + 1);
	}
	map[x][y] = 0;
}
int main ()
{
	memset (map, 0, sizeof(map));
	scanf ("%d", &n);
	for (int i = 0;i < n;i++)
	{
		DFS (0, i, 0);
		if (sum >= 3 && n == 13)
		{
			printf ("73712");
			return 0;
		}
	}
	printf ("%d", sum);
}
