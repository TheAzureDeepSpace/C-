#include <cstdio>
int main ()
{
	char a[14] = "", b;
	int s = 0, x = 1;
	scanf ("%s", a);
	b = a[12];
	for (int i = 0;i < 13;i++)
	{
		if (a[i] != '-' && x != 10)
		{
			s += (a[i] - '0') * x;
			x++;
		}
	}
	if (s % 11 == 10)
		a[12] = 'X';
	else
		a[12] = s % 11 + '0';
	if (a[12] == b)
		printf ("Right");
	else
		printf ("%s", a);
	return 0;
}
