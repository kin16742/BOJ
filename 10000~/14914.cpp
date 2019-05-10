#include <iostream>
using namespace std;
int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c;
	cin >> a >> b;
	c = gcd(a, b);
	for (int i = 1; i <= c; i++) {
		if (c%i == 0)
			cout << i << " " << a / i << " " << b / i << '\n';
	}
	return 0;
}