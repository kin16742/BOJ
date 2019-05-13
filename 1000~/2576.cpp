#include <iostream>
#include <algorithm>
using namespace std;

int sum = 0, m = 101, a;

int main() {
	for (int i = 0; i < 7; i++) {
		cin >> a;
		if (a % 2 == 1) {
			m = min(a, m);
			sum += a;
		}
	}
	if (sum == 0) {
		cout << -1 << '\n';
	}
	else {
		cout << sum << '\n' << m << '\n';
	}
	return 0;
}