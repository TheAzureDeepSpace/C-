#include <cstdio>
int main ()
{
	int n;
	scanf("%d", &n);
	int s = 0;
	while (n != 0)
	{
		s = s * 10 + n % 10;
		n /= 10;
	}
	printf("%d", s);
}
