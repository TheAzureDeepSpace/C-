#include <bits/stdc++.h>
using namespace std;
const int INF = 101;
struct Edge
{
	int to, next;
}edge[500000 * 2 * 2];
int num = 0, n, m, money1[100002], money2[100002], money[100002], head[100002], head2[100002], GO[100002];
void Add(int from, int to)
{
	num++;
	edge[num].to = to;
	edge[num].next = head[from];
	head[from] = num;
}
void Add2(int from, int to)
{
	num++;
	edge[num].to = to;
	edge[num].next = head2[from];
	head2[from] = num;
}
void SPFA1()
{
	queue<int> q;
	for (int i = 1;i <= n;i++)
		money1[i] = INF;
	memset(GO, 0, sizeof(GO));
	q.push(1);
	GO[1] = 1;
	money1[1] = money[1];
	while (!q.empty())
	{
		int s = q.front();
		q.pop();
		for (int i = head[s];i;i = edge[i].next)
		{
			int to = edge[i].to, m = money[to];
			if (GO[to] == 0)
			{
				money1[to] = min(money1[s], m);
				GO[to] = 1;
				q.push(to);
			}
			else if (GO[to] == 1 && money1[s] < money1[to])
			{
				q.push(to);
				money1[to] = min(money1[s], min(money1[s], m));
			}
		}
	}
}
void SPFA2()
{
	queue<int> q;
	memset(money2, 0, sizeof(money2));
	memset(GO, 0, sizeof(GO));
	q.push(n);
	GO[n] = 1;
	money2[n] = money[n];
	while (!q.empty())
	{
		int s = q.front();
		q.pop();
		for (int i = head2[s];i;i = edge[i].next)
		{
			int to = edge[i].to, m = money[to];
			if (GO[to] == 0)
			{
				GO[to] = 1;
				q.push(to);
				money2[to] = max(money2[s], m);
			}
			else if (GO[to] == 1 && money2[s] > money2[to])
			{
				q.push(to);
				money2[to] = max(money2[s], max(money2[s], m));
			} 
		}
	}
}
int main()
{
//	ios::sync_with_stdio(false);
//	freopen("DeBug.in", "r", stdin);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> money[i];
	for (int i = 1;i <= m;i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		Add(x, y);
		Add2(y, x);
		if (z == 2)
		{
			Add(y, x);
			Add2(x, y);
		}
	}
	SPFA1();
	SPFA2();
	int ans = 0;
	for (int i = 1;i <= n;i++)
	{
		ans = max(money2[i] - money1[i], ans);
	}
	cout << ans;
}
