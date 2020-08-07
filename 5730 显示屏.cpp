#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int map[5][1000];
int draw(int x, int num)
{
	x = x * 3;
	if (num == 0)
		map[0][x] = map[0][x + 1] = map[0][x + 2] = map[1][x] = map[1][x + 2] = map[2][x] = map[2][x + 2] = map[3][x] = map[3][x + 2] = map[4][x] = map[4][x + 1] = map[4][x + 2] = 1;
	if (num == 1)
		map[0][x + 2] = map[1][x + 2] = map[2][x + 2] = map[3][x + 2] = map[4][x + 2] = 1;
	if (num == 2)
		map[0][x] = map[0][x + 1] = map[0][x + 2] = map[1][x + 2] = map[2][x] = map[2][x + 1] = map[2][x + 2] = map[3][x] = map[4][x] = map[4][x + 1] = map[4][x + 2] = 1;
	if (num == 3)
		map[0][x] = map[0][x + 1] = map[0][x + 2] = map[1][x + 2] = map[2][x] = map[2][x + 1] = map[2][x + 2] = map[3][x + 2] = map[4][x] = map[4][x + 1] = map[4][x + 2] = 1;
	if (num == 4)
		map[0][x] = map[0][x + 2] = map[1][x] = map[1][x + 2] = map[2][x] = map[2][x + 1] = map[2][x + 2] = map[3][x + 2] = map[4][x + 2] = 1;
	if (num == 5)
		map[0][x] = map[0][x + 1] = map[0][x + 2] = map[1][x] = map[2][x] = map[2][x + 1] = map[2][x + 2] = map[3][x + 2] = map[4][x] = map[4][x + 1] = map[4][x + 2] = 1;
	if (num == 6)
		map[0][x] = map[0][x + 1] = map[0][x + 2] = map[1][x] = map[2][x] = map[2][x + 1] = map[2][x + 2] = map[3][x] = map[3][x + 2] = map[4][x] = map[4][x + 1] = map[4][x + 2] = 1;
	if (num == 7)
		map[0][x] = map[0][x + 1] = map[0][x + 2] = map[1][x + 2] = map[2][x + 2] = map[3][x + 2] = map[4][x + 2] = 1;
	if (num == 8)
		map[0][x] = map[0][x + 1] = map[0][x + 2] = map[1][x] = map[1][x + 2] = map[2][x] = map[2][x + 1] = map[2][x + 2] = map[3][x] = map[3][x + 2] = map[4][x] = map[4][x + 1] = map[4][x + 2] = 1;
	if (num == 9)
		map[0][x] = map[0][x + 1] = map[0][x + 2] = map[1][x] = map[1][x + 2] = map[2][x] = map[2][x + 1] = map[2][x + 2] = map[3][x + 2] = map[4][x] = map[4][x + 1] = map[4][x + 2] = 1;
	return 0;
}
int main()
{
	int n;
	memset (map, 0, sizeof(map));
	string str;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		char num;
		cin >> num;
		draw (i, num);
	}
	for (int i = 0;i < 5;i++)
	{
		for (int j = 0;j < n * 3 + n - 1;j++)
			cout << map[i][j];
		cout << endl;
	}
}
