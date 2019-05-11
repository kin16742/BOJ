#include <iostream>
using namespace std;

int t, a, b, c;

int main() {
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		if (c%a == 0) cout << a * 100 + c / a << '\n';
		else cout << c % a * 100 + c / a + 1 << '\n';
	}
	return 0;
}