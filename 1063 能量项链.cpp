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
	//以项链的第几颗起点为阶段 
	for (int i = 2;i < 2 * n;i++)
	{
		//以项链的第几颗结束为状态 
		for (int j = i - 1;i - j < n && j >= 1;j--)	//逆序储存 
		{
			for (int k = j;k < i;k++)
				ans[j][i] = max(ans[j][i], ans[j][k] + ans[k + 1][i] + (s[j] * s[k + 1] * s[i + 1]));
			//状态转移方程:max(当前能量, 左区间合并能量 + 右区间合并能量 + (左区间珠子 * 右区间珠子 * 总区间后面的珠子);
			MAX = max(ans[j][i], MAX);
		}
	}
	cout << MAX;
}

