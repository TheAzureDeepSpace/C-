#include <iostream>
using namespace std;
const int MAXN = 1000;
struct Edge
{
	int next;		//��һ����
	int to;			//ȥ
	int dis;		//Ȩֵ
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
	cout << "����Ҫ�ı���";
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		int from, to, dis;
		cin >> from >> to >> dis;
		//����
		AddEdge(from, to, dis);
		//����ͼҪ����˫��
		AddEdge(to, from, dis);
	}
	cout << "������Ҫ��ѯ�ı�";
	cin >> n;
	for (int i = head[n];i;i = edge[i].next)
	{
		cout << n << ":" << edge[i].to << " " << edge[i].dis << endl;
	}
	return 0;
}