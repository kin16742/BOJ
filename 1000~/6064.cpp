#include <iostream>
using namespace std;

int t, a, b, c, d;
int gcd(int x, int y) {
	int temp;
	while (y) {
		temp = x;
		x = y;
		y = temp%y;
	}
	return x;
}
int main() {
	cin >> t;
	while (t--) {
		bool chk = 1;
		cin >> a >> b >> c >> d;
		while (c != d && c <= a * b / gcd(a, b)) {
			if (c < d) c += a;
			else d += b;
		}
		if (c != d) cout << -1 << '\n';
		else cout << c << '\n';
	}
	return 0;
}