#include <bits/stdc++.h>
using namespace std;
int MAP[1002][1002], n, m, canmap[1002][1002];
struct node
{
	int x, y;
};
int BFS(int x, int y)
{
	int pathx[4] = {0, 0, 1, -1};int sum = 0;
	int pathy[4] = {1, -1, 0, 0};
	queue<node> q;
	q.push(node{x, y});
	canmap[y][x] = 1;
	memset(canmap, 0, sizeof(canmap));
	while (!q.empty())
	{
		node s;
		s.x = q.front().x;
		s.y = q.front().y;
		for (int i = 0;i < 4;i++)
		{
			int nowx = s.x + pathx[i], nowy = s.y + pathy[i];
			if (nowx >= 1 && nowx <= n && nowy >= 1 && nowy <= n && MAP[nowy][nowx] != MAP[s.y][s.x] && canmap[nowy][nowx] == 0)
			{
				q.push(node{nowx, nowy});
				canmap[nowy][nowx] = 1;
				sum++;
			}
		}
		q.pop();
	}
	return sum;
}
int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		string str;
		cin >> str;
		for (int j = 1;j <= n;j++)
		{
			MAP[i][j] = str[j - 1] - '0';
		}
	}
	for (int i = 1;i <= m;i++)
	{
		int a, b;
		cin >> a >> b;
		cout << BFS(b, a) << endl;
	}
}
