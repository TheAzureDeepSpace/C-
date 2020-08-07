#include <iostream>
#include <cstring>
using namespace std;
unsigned long long n, m;
unsigned long long x, y;
int check(unsigned long long n, unsigned long long m)
{
	if (n == x && m == y)
		return 0;
	if (n == x - 1 && m == y + 2)
		return 0;
	if (n == x + 1 && m == y + 2)
		return 0;
	if (n == x + 2 && m == y + 1)
		return 0;
	if (n == x + 2 && m == y - 1)
		return 0;
	if (n == x + 1 && m == y - 2)
		return 0;
	if (n == x - 1 && m == y - 2)
		return 0;
	if (n == x - 2 && m == y - 1)
		return 0;
	if (n == x - 2 && m == y + 1)
		return 0;
	return 1;
}
int main()
{
	unsigned long long map[100][100];
	memset(map, 0, sizeof(map));
	cin >> n >> m >> x >> y;
	for (unsigned long long i = 0;i <= n;i++)
	{
		for (unsigned long long j = 0;j <= m;j++)
		{
			map[i][j] = 0;
			if (check(i, j))
			{
				if (i == 0 && j == 0)
					map[i][j] = 1;
				else if (j == 0)
					map[i][j] = map[i - 1][j];
				else if (i == 0)
					map[i][j] = map[i][j - 1];
				else map[i][j] = map[i - 1][j] + map[i][j - 1];
			}
			else map[i][j] = 0;
		}
	}
	cout << map[n][m];
}