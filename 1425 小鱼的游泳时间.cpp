#include <cstdio>
int main ()
{
	int a, b, c ,d, e = 0, f;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	b += a * 60;		//转化为分 
	d += c * 60;
	f = d - b;
	e += f /60;
	f = f % 60;
	printf("%d %d", e, f);
	return 0;
}
