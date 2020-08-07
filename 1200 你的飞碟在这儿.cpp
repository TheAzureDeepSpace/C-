#include <cstdio>
int main ()
{
	char a[7], b[7];
	int sa = 1, sb = 1;
	scanf ("%s%s", a, b);
	for (int i = 0;a[i] != '\0';i++) sa *= a[i] - 'A' + 1;
	for (int i = 0;b[i] != '\0';i++) sb *= b[i] - 'A' + 1;
	if (sa % 47 == sb % 47)
		printf ("GO");
	else
		printf ("STAY");
	return 0;
}
