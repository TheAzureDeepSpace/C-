#include <bits/stdc++.h>
using namespace std;
int Map[10][10], hang[10][10], lie[10][10], gong[10][10], u, ans = -1;
struct l
{
	int line, sum;
}line[10];
struct node
{
	int hang, lie, gong;
}nodes[1000];
//�ж�
bool operator < (l, l);
//���� 
int Gong(int, int);
//����
int Score(int, int); 
//���� 
void dfs(int, int);
//�����жϵڼ�����/��/���ĵڼ������Ƿ���� u -> û��������� ans -> �� 
int main()
{
	int score = 0;
	for (int i = 1;i <= 9;i++)
		line[i].line = i;
	for (int i = 1;i <= 9;i++)
	{
		for (int j = 1;j <= 9;j++)
		{
			cin >> Map[i][j];
			if (Map[i][j] != 0)
			{
				score += Map[i][j] * Score(j, i);
				hang[i][Map[i][j]] = lie[j][Map[i][j]] = gong[Gong(j, i)][Map[i][j]] = 1;
			}
			else
			{
				line[i].sum++;
			}
		}
	}
	sort(line + 1, line + 1 + 9);
	for (int i = 1;i <= 9;i++)
	{
		for (int j = 1;j <= 9;j++)
		{
			if (Map[i][j] == 0)
			{
				//���һ���ڵ�
				nodes[u].hang = line[i].line,
				nodes[u].lie = j,
				nodes[u].gong = Gong(j, line[i].line),
				u++;
			}
		}
	}
	dfs(0, score);
	cout << ans;
	return 0;
}
bool operator < (l a, l b)
{
	return a.sum < b.sum;
}
//q -> ��ǰ����Ľڵ� score -> ��ǰ���� 
void dfs(int q, int score)
{
	if (q == u)
	{
		ans = max(score, ans);
		return;
	}
	//��1�������п��Ե��� 
	for (int i = 1;i <= 9;i++)
	{
	}
}
int Gong(int x, int y)
{
	if (y <= 3)
		if (x <= 3) return 1;
		else if (x <= 6) return 2;
		else if (x <= 9) return 3;
	if (y <= 6)
		if (x <= 3) return 4;
		else if (x <= 6) return 5;
		else if (x <= 9) return 6;
	if (y <= 9)
		if (x <= 3) return 7;
		else if (x <= 6) return 8;
		else if (x <= 9) return 9;
}
int Score(int x, int y)
{
	if (x == 1 || y == 1 || x == 9 || y == 9)
		return 6;
	if (x == 2 || y == 2 || x == 8 || y == 8)
		return 7;
	if (x == 3 || y == 3 || x == 7 || y == 7)
		return 8;
	if (x == 4 || y == 4 || x == 6 || y == 6)
		return 9;
	return 10;
}
