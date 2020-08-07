#include <bits/stdc++.h>
using namespace std;
int N, M, P;
int father[5000];
//找父亲节点 
int find(int x)
{
	while (x != father[x])
	{
		father[x] = father[father[x]];
		x = father[x];
	}
	return x;
}
//合并
void uni(int x, int y)
{
	father[find(x)] = find(y);
}
bool same(int x, int y)
{
	if (find(x) == find(y))
		return true;
	else
		return false;
}
int main()
{
	cin >> N >> M >> P;
	for (int i = 1;i <= N;i++)
	{
		father[i] = i;
	}
	for (int i = 1;i <= M;i++)
	{
		int x, y;
		cin >> x >> y;
		uni(x, y);
	}
	for (int i = 1;i <= P;i++)
	{
		int x, y;
		cin >> x >> y;
		cout << (same(x, y) == true ? "Yes" : "No") << endl;
	}
}
