#include <iostream>
using namespace std;
bool is_prime(int n)
{
	if (n == 2)
		return true;
	if (n % 2 == 0)
		return false;
	for (int i = 2;i < n / 2 + 1;i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
int main()
{
	int l, sum = 0, c = 0;
	cin >> l;
	for (int i = 2;sum < l && i < l && i < 10000;i++)
	{
		if (is_prime(i) && sum + i <= l)
		{
			sum += i, c++;;
			cout << i << endl;
		}
	}
	cout << c;
}
