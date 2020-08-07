#include <bits/stdc++.h>
using namespace std;
int n, m, win = -1;
int father[50000];
int f(int x, int y)
{
	return y * (n) + x;
}
int find(int x)
{
	while (x != father[x])
	{
		father[x] = father[father[x]];
		x = father[x];
	}
	return x;
}
void unionn(int x, int y)
{
	father[find(x)] = find(y);
}
int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			father[f(j, i)] = f(j, i);
		}
	}
	int x, y;
	for (int i = 1;i <= m;i++)
	{
		cin >> y >> x;
		char s;
		while (cin >> s)
		{
			if (s == 'D' || s == 'R')
				break;
		}
		if (s == 'D')
		{
			if (find(f(x, y)) == find(f(x, y + 1)))
			{
				win = win == -1 ? i : win;
			}
			unionn(f(x, y), f(x, y + 1));
		}
		else
		{
			if (find(f(x + 1, y)) == find(f(x, y)))
			{
				win = win == -1 ? i : win;
			}
			unionn(f(x, y), f(x + 1, y));
		}
	}
	win:;
	if (win == -1)
		cout << "draw";
	else
		cout << win;
}

