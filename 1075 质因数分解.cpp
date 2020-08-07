#include <cstdio>
#include <cmath>
using namespace std;
long long n;
int Prime (long long s)
{
	long long a = s / 2;
	if (s > 500)
		a = sqrt (s);
	for (int i = 2;i <= a;i++)
	{
		if (!(s % i))
			return 0;
	}
	return 1;
}
int main ()
{
	scanf ("%lld", &n);
	for (long long i = 2;i <= n;i++)
	{
		if (Prime (i) && Prime (n / i) && n % i == 0)//
		{
			printf ("%lld", n / i);
			printf ("%lld", n);
			return 0;
		}
	}
	return 0;
}
