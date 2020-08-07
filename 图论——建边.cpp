#include <iostream>
using namespace std;
const int MAXN = 1000;
struct Edge
{
	int next;		//下一条边
	int to;			//去
	int dis;		//权值
}edge[MAXN];

int head[MAXN], num = 0;

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
	int n;
	cout << "输入要的边数";
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		int from, to, dis;
		cin >> from >> to >> dis;
		//建边
		AddEdge(from, to, dis);
		//无向图要建立双向
		AddEdge(to, from, dis);
	}
	cout << "请输入要查询的边";
	cin >> n;
	for (int i = head[n];i;i = edge[i].next)
	{
		cout << n << ":" << edge[i].to << " " << edge[i].dis << endl;
	}
	return 0;
}