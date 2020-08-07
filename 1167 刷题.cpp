#include <iostream>
#include <algorithm>
using namespace std;
int Year (int m)
{
	if (m % 100 == 0)
	{
		if (m % 400 != 0)	return 0;
		else if (m % 400 == 0) return 1;
	}
	if (m % 4 == 0)
		return 1;
	return 0;
}
int main ()
{
	char ch;
	long int N, problem[10000], AC = 0, MIN = 0;
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		cin >> problem[i];
	}
	sort(problem, problem + N);
	int year, mon, day, hour, min;
	int year2, mon2, day2, hour2, min2;
	cin >> year >> ch >> mon >> ch >> day >> ch >> hour >> ch >> min;
	cin >> year2 >> ch >> mon2 >> ch >> day2 >> ch >> hour2 >> ch >> min2;
	while (year != year2 || mon != mon2 || day != day2 || hour != hour2 || min != min2)
	{
		min++, MIN++;
		if (AC < N && MIN >= problem[AC])
		{
			AC++, MIN = 0;
		}
		if (min >= 60)
		{
			min = 0, hour++;
		}
		if (hour >= 24)
		{
			hour = 0, day++;
		}
		if (day >= 31 && (mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12))
		{
			day = 0, mon++;
		}
		if (day >= 30 && (mon == 4 || mon == 6 || mon == 9 || mon == 11))
		{
			day = 0, mon++;
		}
		if (Year(year) && mon == 2 && day >= 28)
		{
			day = 0, mon++;
		}
		if (Year(year) && mon == 2 && day >= 29)
		{
			day = 0, mon++;
		}
	}
	cout << AC;
}