#include <stdio.h>
int main ()
{
	int a;
	double x = 0;
	scanf("%d", &a);
	if ( a <= 150)
	{
		x += a * 0.4463;
	}
	else if (a > 150 && a <= 400)
	{
		x += 150 * 0.4463 + (a - 150) * 0.4663;
	}
	else if (a > 400)
	{
		x += 150 * 0.4463 + 250 * 0.4663 + (a - 400) * 0.5663;
	}
	printf("%.1f", x);
	return 0;
}
