#include <iostream>
using namespace std;
int main()
{
	int n;
	int map[200][200];
	cin >> n;
	map[0][0] = 1;
	if (!n)
		return 0;
	for (int i = 0;i <= n;i++)
	{
		for (int j = 0;j < i;j++)
		{
			map[i][j] = map[i - 1][j - 1] + map[i - 1][j];
			if (j == 0 || j == i - 1)
				map[i][j] = 1;
			cout << map[i][j] << " ";
		}
		if (i)
			cout << endl;
	}
	return 0;
}
