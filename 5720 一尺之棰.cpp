#include <iostream>
using namespace std;
int main()
{
	int n, i = 0;
	cin >> n;
	while (n != 1)
		n /= 2, i++;
	cout << i + 1;
}
