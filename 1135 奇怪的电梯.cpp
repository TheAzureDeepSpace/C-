#include <cstdio>
int n, a, b, k[205], to[205] = {}, yes = 0x7ffffff;
int x (int cing, int cs)
{
	if (cs > yes)
		return 0;
	if (cing == b)
		if (yes > cs)
			yes = cs;
	to[cing] = 1;
	if(cing + k[cing] <= n && !to[cing + k[cing]])
	{	
		x(cing + k[cing], cs + 1);
	}
	if(cing - k[cing] > -1 && !to[cing - k[cing]])
	{
		x(cing - k[cing], cs + 1);
	}
	to[cing] = 0;
}
int main ()
{
	scanf ("%d%d%d", &n, &a, &b);
	for (int i = 1;i <= n;i++)
	{
		scanf ("%d", &k[i]);
		to[i] = 0;
	}
	to[a] = 1;
	x (a, 0);
	if (yes != 0x7ffffff) 
		printf ("%d", yes);
	else
		printf ("-1"); 
}
