#include <iostream>
using namespace std;
int main()
{
	int budget[13], money = 0, mother = 0, save, i;
	for (i = 1; i <= 12; i++)
		cin >> budget[i];
	for (i = 1; i <= 12; i++)
	{
		money += 300;
		money -= budget[i];
		if (money<0)
		{
			cout << '-' << i;
			return 0;
		}
		save = money / 100 * 100;
		money -= save; mother += save;
	}
	money += mother + mother / 5;
	cout << money;
	return 0;
}
