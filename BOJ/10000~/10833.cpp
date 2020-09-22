#include <iostream>
#include <algorithm>
using namespace std;

int t, a, b, res = 0;

int main() {
	cin >> t;

	while (t--) {
		cin >> a >> b;
		res += b % a;
	}
	cout << res << '\n';
	return 0;
}