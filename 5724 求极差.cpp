#include <iostream>
using namespace std;
int main()
{
	int max = 0, min = 1000, n;
	cin >> n;
	while (n--)
	{
		int a;
		cin >> a;
		max = max > a ? max : a;
		min = min < a ? min : a;
	}
	cout << max - min;
}
