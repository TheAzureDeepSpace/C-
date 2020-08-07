#include <cstdio>
#include <cstring>
int n, map[10][10], max = 0;
struct 
{
	int x, y, sum;
}queue[100];
int BFS ()
{
	int start = 0, end = 1;
	queue[0].x = queue[0].y = 1, queue[0].sum = 0;
	int gox[2] = {0, -1}, goy[2] = {1, 0};
	while (start != end)
	{
		for (int i = 0;i < 2;i++)
		{
			int x = queue[start].x + gox[i], y = queue[start].y + goy[i];
			if (x > 0 && x <= n && y > 0 && y <= n)
			{
				queue[end].sum = queue[start].sum + map[x][y];
				queue[end].x = x, queue[end].y = y;
				if (queue[end].sum > max)
					max = queue[end].sum;
				end++;
			}
		}
		start++;
	}
}
int main ()
{
	scanf ("%d", &n);
	memset (map, 0, sizeof(map));
	while (1)
	{
		int x, y, s;
		scanf ("%d%d%d", &x, &y, &s);
		if (x == 0 && y == 0 && s == 0)
			break;
		map[x][y] = s;
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
			printf ("%3d", map[i][j]);
		printf ("\n");
	}
	BFS ();
	printf ("%d", max);
}
