#include <cstdio>
int main ()
{
	double m, can = 2.0 ,pm = 0;
	int i;
	scanf("%lf", &m);
	for (i = 0;pm < m;i++)
	{
		pm += can;
		can = can * 0.98;
	}
	printf("%d", i);
}
