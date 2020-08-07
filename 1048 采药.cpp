#include <iostream>
using namespace std;
struct thing
{
	int time;
	int money;
};
thing things[10000];
int money[10000][10000];
int main()
{
	int T, M;
	cin >> T >> M;
	for (int i = 0;i < M;i++)
	{
		cin >> things[i].time >> things[i].money;
	}
	for (int i = 0;i < M;i++)
	{
		for (int j = 0;j <= T;j++)
		{
			money[i][j] = 0;
			if (i == 0 && j - things[i].time >= 0)
			{
				money[0][j] = things[i].money;
			}
			else
			{
				if (i > 0)
				{
					money[i][j] = money[i - 1][j];
				}
				if (j - things[i].time >= 0)
				{
					money[i][j] = max(money[i][j], things[i].money + money[i - 1][j - things[i].time]);
				}
			}
		}
	}
	cout << money[M - 1][T];
}
