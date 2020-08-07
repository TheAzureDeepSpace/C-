#include <bits/stdc++.h>
#define MAXN 10000
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
	cin >> n >> m;
	for (int i = 1;i <= m;i++)
	{
		int from, to, dis;
		cin >> from >> to >> dis;
		Add(from, to, dis);
	}
	sort(edge + 1, edge + 1 + m, cmp);
	for (int i = 1;i <= n;i++)
	{
		father[i] = i;
	}
	for (int i = 1;i <= m;i++)
	{
		if (find(edge[i].from) != find(edge[i].to))
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
/*
5 8
1 2 2
1 5 12
1 3 10
2 5 8
5 3 6
2 4 9
5 4 3
3 4 7
*/
