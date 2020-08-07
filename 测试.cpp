#include <bits/stdc++.h>
#include <cstring>
#include <queue>
using namespace std;
const int MAX = 1e9;		//最大上限
priority_queue<pair<int, int> > q;
struct Edge
{
	int next;				//下一条边的索引
	int to;					//所到的点
	int dis;				//边权值
}edge[10000];
int num = 0, head[10000], dis[10000], vis[10000];
int AddEdge(int from, int to, int dis)
{
	num++;
	edge[num].next = head[from];
	edge[num].to = to;
	edge[num].dis = dis;
	head[from] = num;
}
int main()
{
	int n, m, s;
	cin >> n >> m >> s;
	for (int i = 0;i < m;i++)
	{
		int from, to, dis;
		cin >> from >> to >> dis;
		AddEdge(from, to, dis);
	}
	for (int i = 1;i <= n;i++)//初始化
	{
		dis[i] = MAX;
	}
	dis[s] = 0;
	q.push(make_pair(0, s));
	while (q.size())
	{
		int tmp = q.top().second;		//取第二个元素
		q.pop();
		if (vis[tmp])
			continue;
		vis[tmp] = 1;
        for(int j = head[tmp];j;j = edge[j].next)	//j:边的序号
		{ 
            int k = edge[j].to, d = edge[j].dis;
            if(dis[k] > dis[tmp] + d)
			{
                dis[k] = dis[tmp] + d;
                q.push(make_pair(-dis[k], k));
            } 
        }
	}
	for (int i = 1;i <= n;i++)
	{
		cout << dis[i] << " ";
	}
}