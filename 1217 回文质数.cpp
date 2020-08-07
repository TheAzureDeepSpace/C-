#include <cstdio>
#include <cmath>
int a, b;
bool Prime(int n)
{ //middle
	int stop = sqrt(n) + 1;
	if (n == 2)
	{
		return 1;
	}
	if (n % 2 == 0)
	{
		return 0;
	}
	for (int i = 3; i <= stop; i += 2)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
bool check (int s)
{
	int x = s, y = 0, c = 0;
	while (x)
	{
		y = y * 10 + x % 10;
		x /= 10;
		c++;
	}
	if (y == s && c % 2 != 0 && Prime(s))
		return 1;
	else
		return 0;
}
int main ()
{
	scanf ("%d%d", &a, &b);
	if (b > 10000000)
		b = 10000000;
	for (int i = a;i <= b;i++)
	{
		if (check(i) || i == 11 && i % 2 != 0)
		{
			printf ("%d\n", i);
		}
	}
}
