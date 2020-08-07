#include <cstdio>
#include <cstring>
int main ()
{
	bool tree[10001];
	memset(tree, true, sizeof(tree));
	int l, m;
	scanf("%d%d", &l, &m);
	for (int i = 0;i < m;i++)
	{
		int s1, s2;
		scanf("%d%d", &s1, &s2);
		for (int in = s1;in <= s2;in++)
		{
			tree[in] = false;
		}
	}
	int s = 0;
	for (int i = 0;i <= l;i++)
	{
		if (tree[i])
			s++;
	}
	printf("%d", s);
	return 0;
} 
