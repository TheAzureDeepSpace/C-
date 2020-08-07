#include <cstdio>
int main ()
{
	int s;
	for (int i = 100;i < 1000;i++)
	{
		if (i * 3 > 999)
			return 0;
		int s1 = i / 100, 
			s2 = i / 10 % 10, 
			s3 = i % 10;
		for (int in = i + 1;in <= 666;in++)
		{
			int j1 = in / 100,
				j2 = in / 10 % 10,
				j3 = in % 10;
			for (int i3 = in + 1;i3 <= 999;i3++)
			{
				int f1 = i3 / 100,
					f2 = i3 /10 % 10,
					f3 = i3 % 10;
				int ss[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, yes = 9;
				for (int iz = 0;iz < 9;iz++)
				{
					if (ss[iz] == s1 || ss[iz] == s2 || ss[iz] == s3 || ss[iz] == j1 || ss[iz] == j2 || ss[iz] == j3 || ss[iz] == f1 || ss[iz] == f2 || ss[iz] == f3)
						yes --;
				}
				if (i * 2 == in && i * 3 == i3 && yes <= 0)
					printf("%d %d %d\n", i, in, i3);
			}
		}
	}
}
