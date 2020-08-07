#include <iostream>
#include <cstring>
using namespace std;
int map[1000][1000];
int main()
{
	int n;
	cin >> n;
	memset(map, -1, sizeof(map));
	for (int i = 1;i <= n;i++)
	{
		int x, y, lenx, leny;
		cin >> x >> y >> lenx >> leny;
		for (int iy = 0;iy < leny;iy++)
		{
			for (int ix = 0;ix < lenx;ix++)
			{
				map[y - iy][ix + x] = i;
			}
		}
	}
	int x, y;
	cin >> x >> y;
	cout << map[y][x];
}