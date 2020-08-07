#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;
struct Edge
{
	int from;
	int to;
	int dis;
}edge[MAXN];
int father[MAXN], head[MAXN], num = 0, n, m, ans = 0, k = 0;
void Add(int from, int to, int dis)
{
	num++;
	edge[num].from = from;
	edge[num].to = to;
	edge[num].dis = dis;
}
int find(int x)
{
	if (father[x] == x)
		return x;
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
bool cmp(Edge a, Edge b)
{
	return a.dis < b.dis;
}
int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		int from, to, dis;
		for (int j = 1;j <= n;j++)
		{
			int s;
			cin >> s;
			if (j > i)
				Add(i, j, s);
		}
	}
	for (int i = 1;i <= n;i++)
	{
		father[i] = i;
	}
	sort(edge + 1, edge + 1 + n * n, cmp);
	for (int i = 1;i <= n * n;i++)
	{
		if (find(edge[i].from) != find(edge[i].to) && edge[i].from != edge[i].to)
		{
			unionn(edge[i].from, edge[i].to);
//			cout << edge[i].from << "->" << edge[i].to << endl;	//Êä³öÁ¬½Ó 
			ans += edge[i].dis;
			k++;
		}
		if (k == n - 1)
			break;
	}
	cout << ans;
	return 0;
}
