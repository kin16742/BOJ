
#include <iostream>
#include <algorithm>
using namespace std;

int t, r, e, c;

int main() {
	cin >> t;

	while (t--) {
		cin >> r >> e >> c;

		if (r > e - c) cout << "do not advertise\n";
		if (r < e - c) cout << "advertise\n";
		if (r == e - c)cout << "does not matter\n";
	}

	return 0;
}