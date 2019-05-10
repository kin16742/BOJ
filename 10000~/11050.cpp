#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	int c = 1;
	cin >> a >> b;
	for (int i = a - b + 1; i <= a; i++) {
		c *= i;
	}
	for (int i = 1; i <= b; i++) {
		c /= i;
	}
	cout << c << '\n';
	return 0;
}