#include <cstdio>
#include <cstring>
int main ()
{
	char a[12], b[1000002];
	int min = -1, s = 0;
	scanf ("%s\n%[^\n]", a + 1, b + 1);
	a[0] = ' ', b[0] = ' ';
	for (int i = 0;i < strlen (a);i++) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 32;
	for (int i = 0;i < strlen (b);i++) if (b[i] >= 'A' && b[i] <= 'Z') b[i] += 32;
	for (int i = 0;i < strlen (b);i++)
	{
		bool yes = true;
		while (b[i] != ' ' && i < strlen (b))
		{
//			printf ("%c", b[i]);
			i++;
		}
		for (int in = 0;in < strlen (a);in++)
		{
			if (a[in] != b[i + in])
			{
//				printf ("%c%c\n", a[in], b[i + in]);
				yes = false;
				break;
			}
		}
		if (yes && b[i] == ' ')
		{
			if (min == -1)
				min = i;
//			printf ("1");
			s++;
		}
	}
	if (min != -1)
		printf ("%d ", s);
	printf ("%d", min);
	return 0;
}
