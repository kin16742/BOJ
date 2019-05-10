#include <iostream>
#include <cmath>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int x1, y1, r1, x2, y2, r2;
		double l;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		l = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
		if (x1 == x2 && y1 == y2) {
			if (r1 == r2) cout << -1 << '\n';
			else if (r1 != r2) cout << 0 << '\n';
		}
		else {
			if (r1 + r2 == l || abs(r1 - r2) == l) cout << 1 << '\n';
			else if (r1 + r2 > l && abs(r1 - r2) < l) cout << 2 << '\n';
			else cout << 0 << '\n';
		}
	}

	return 0;
}