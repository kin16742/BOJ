#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int a[1000001] = { 0 };

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, cnt;
	cin >> n;
	a[1] = 0;
	a[2] = 1;
	a[3] = 1;
	for (int i = 4; i <= n; i++) {
		a[i] = i;
		
		if (i % 2 == 0) {
			a[i] = min(a[i], a[i / 2] + 1);
		}
		if (i % 3 == 0) {
			a[i] = min(a[i], a[i / 3] + 1);
		}
		if (i % 6 == 0) {
			a[i] = min(a[i], a[i / 6] + 2);
		}
		a[i] = min(a[i], a[i - 1] + 1);

	}

	cout << a[n] << '\n';

	return 0;
}