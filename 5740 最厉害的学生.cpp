#include <cstdio>
struct st
{
	char name[256];
	int cn, math, en, sum;
}student[10000];
int max = 0, maxi = 0;
int main ()
{
	int n;
	scanf ("%d", &n);
	for (int i = 0;i < n;i++)
	{
		scanf ("%s%d%d%d", student[i].name, &student[i].cn, &student[i].math, &student[i].en);
		student[i].sum = student[i].cn + student[i].math + student[i].en;
		if (max < student[i].sum)
			max = student[i].sum, maxi = i;
	}
	printf ("%s %d %d %d", student[maxi].name, student[maxi].cn, student[maxi].math, student[maxi].en);
}
