#include <cstdio>
#include <cstring>
int x = 0, y = 0, n, map[1000][1000];
int c(int s, int z)
{
	while (s--)
	{
		map[x][y] = z;
		y++;
		if (y >= n)
			x++, y = 0;
	}
}
int main()
{
	memset (map, -1, sizeof(map));
	int z = 0;
	scanf ("%d", &n);
	for (int i = 0;map[n - 1][n - 1] == -1;i++)
	{
		int s;
		scanf ("%d", &s);
		c(s, z);
		if (z == 0)
			z = 1;
		else
			z = 0;
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
			printf ("%d", map[i][j]);
		printf ("\n");
	}
}
