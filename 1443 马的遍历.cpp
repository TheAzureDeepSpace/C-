#include <cstdio>
#include <cstring>
#define go 8
using namespace std;
int n, m;
int map[400][400];
struct
{
	int x, y;
}queue[100000];
int BFS (int x, int y)
{
	int start = 0, end = 1;
	queue[0].x = x, queue[0].y = y;map[x][y] = 0;
	int gox[go] = {2, 1, -1, -2, -2, -1, 1, 2};
	int goy[go] = {1, 2, 2, 1, -1, -2, -2, -1};
	while (start != end)
	{
		int i = 0;
		for (i = 0;i < 8;i++)
		{
			int yes = 1;
			x = queue[start].x + gox[i], y = queue[start].y + goy[i];
			if (x < 0 || x >= n || y < 0 || y >= m || map[x][y] != -1)
				yes = 0;
			if (yes)
			{
				map[x][y] = map[queue[start].x][queue[start].y] + 1;
				queue[end].x = x, queue[end].y = y;
				end++;
			}
		}
		start++;
	}
}
int main ()
{
	memset (map, -1, sizeof(map));
	int x, y;
	scanf ("%d%d%d%d", &n, &m, &x, &y);
	BFS(x - 1, y - 1);
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
			printf ("%-5d", map[i][j]);
		printf ("\n");
	}
}
