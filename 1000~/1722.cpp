#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

long long n, r, a[21], f[21];

void R1(int now, int visit, long long k) {
	if (now == n) return;
	long long idx = k / f[n - now - 1];
	int op = 0, cc = 0;
	for (int i = 0; i < n; i++) {
		if (!(visit&(1 << i))) {
			if (cc == idx) {
				op = i;
				break;
			}
			cc++;
		}
	}
	cout << op + 1 << ' ';
	R1(now + 1, visit | (1 << op), k % f[n - now - 1]);
}

long long R2(int now, int visit) {
	if (now == n) return 0;
	int op = 0, cc = 0;
	for (int i = 0; i < n; i++) {
		if (!(visit&(1 << i))) {
			if (i + 1 == a[now])
				break;
			cc++;
		}
	}
	long long ret = cc * f[n - now - 1] + R2(now + 1, visit | (1 << (a[now] - 1)));
	return ret;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> r;

	f[0] = 1;
	for (int i = 1; i <= n; i++) f[i] = f[i - 1] * i;

	if (r == 1) {
		long long k;
		cin >> k;
		R1(0, 0, k - 1);
		cout << '\n';
	}
	else if (r == 2) {
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << R2(0, 0) + 1 << '\n';
	}
	return 0;
}