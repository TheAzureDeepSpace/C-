#include <cstdio>
long int w (int a, int b, int c)
{
	if (a <= 0 || b <= 0)
		return 1;
	else if (a > 20 || b > 20 || c > 20)
		return w(20, 20, 20);
	else if (a < b && b < c)
		return w(a,b,c - 1)+w(a,b - 1,c - 1) - w(a,b - 1,c);
	else 
		return w(a - 1,b,c) + w(a - 1,b - 1,c) + w(a - 1,b,c - 1) - w(a - 1,b - 1,c - 1);
}
int main ()
{
	long int a, b, c;
	do
	{
		scanf("%ld%ld%ld", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1)
			break;
		printf("w(%ld, %ld, %ld) = %ld\n", a, b, c, w(a, b, c));
	}while (1);
}
