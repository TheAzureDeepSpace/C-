#include <bits/stdc++.h>
using namespace std;
int n, s[10000];
int ans[1000][1000], MAX = -0e7f;
int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> s[i];
		s[n + i] = s[i];
	}
	//�������ĵڼ������Ϊ�׶� 
	for (int i = 2;i < 2 * n;i++)
	{
		//�������ĵڼ��Ž���Ϊ״̬ 
		for (int j = i - 1;i - j < n && j >= 1;j--)	//���򴢴� 
		{
			for (int k = j;k < i;k++)
				ans[j][i] = max(ans[j][i], ans[j][k] + ans[k + 1][i] + (s[j] * s[k + 1] * s[i + 1]));
			//״̬ת�Ʒ���:max(��ǰ����, ������ϲ����� + ������ϲ����� + (���������� * ���������� * ��������������);
			MAX = max(ans[j][i], MAX);
		}
	}
	cout << MAX;
}

