#include <cstdio>
#include <cstring>
int main ()
{
	char a[4][101];
	for (int i = 0;i < 4;i++)
	{
		scanf ("%[^\n]", a[i]);
		getchar ();
	}
	int s[26], max = 0;
	memset (s, 0, sizeof(s));
	for (int i = 0;i < 4;i++)
	{
		for (int in = 0;in < strlen(a[i]);in++)
		{
			s[a[i][in] - 'A']++;
		}
	}
	for (int i = 0;i < 26;i++)
	{
		if (s[i] > max)
			max = s[i];
	}
	for (int i = max;i > 0;i--)
	{
		for (int in = 0;in < 25;in++)
		{
			if (s[in] >= i)
				printf ("* ");
			else
				printf ("  ");
		}
		if (s[25] >= i)
			printf ("*\n");
		else
			printf (" \n");
	}
	printf ("A");
	for (int i = 1;i < 26;i++)
	{
		printf (" %c", 'A' + i);
	}
	return 0;
}
