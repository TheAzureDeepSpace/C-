#include <iostream>
using namespace std;
int main()
{
	int n, s = 1;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		for (int j = i;j < n;j++)
		{
			if (s < 10)
				cout << 0;
			cout << s++;
		}
		cout << endl;
	}
}
