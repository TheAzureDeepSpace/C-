#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n, m;
int f[1001][1001];
void floyd()
{
	for(int k = 1; k <= n; ++k)
	{
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= n; ++j)
			{
				if(i != j && i != k && j != k)
				{
					f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
				}
			}
		}
	}
}
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	memset(f, INF, sizeof(f));
	scanf ("%d%d\n", &m, &n);
	for (int i = 1;i <= m;i++)
	{
		int S[1000], top = 1;
		string str;
		getline(cin, str);
		for (int j = 0;j < str.length();++j)
		{
			int s = 0;
			while (str[j] <= '9' && str[j] >= '0')
			{
				s = s * 10 + str[j] - '0';
				j++;
			}
			S[top++] = s;
		}
		for (int j = 1;j < top;j++)
		{
			f[i][i] = 0;
			for (int j2 = j + 1;j2 < top;j2++)
			{
				f[S[j]][S[j2]] = 1;
			}
		}
	}
	floyd();
	if (f[1][n] == INF)
		cout << "NO";
	else
		cout << f[1][n] - 1;
}

