#include <cstdio>
#include <cmath>
bool Prime (int s)
{
	if (s == 1)
		return 0;
	for (int i = 2;i < s;i++)
	{
		if (!(s % i))
		{
			return 0;
		}
	}
	return 1;
}
int main ()
{
	int a;
	scanf("%d", &a);
	for (int i = 0;i < a;i++)
	{
		for (int in = 0;in < a;in++)
		{
			int ir = a - i - in;
			if (Prime (ir) && Prime (i) && Prime (in))
			{
				printf ("%d %d %d", i, in, ir);
				return 0;
			}
		}
	}
	return 0;
}
