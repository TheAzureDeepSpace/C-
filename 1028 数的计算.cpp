#include <cstdio>
int s = 1;
void ss (int z)
{
	for (int i = 1;i <= z / 2;i++)
	{
		s++;
		ss (i);
	}
}
int main ()
{
	int a;
	scanf ("%d", &a);
	ss (a);
	printf ("%d", s);
	return 0;
}
