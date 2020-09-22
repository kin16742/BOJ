#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int n, m, a[50], b[50], res = 1000000000, res1 = 1000000000, res2 = 1000000000;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i];
	}
	if (n >= 6) {
		int t = n;
		for (int i = 0; i < m; i++) {
			int x = 0;
			x += t / 6 * a[i];
			res1 = min(x, res1);
		}
		t %= 6;
		for (int i = 0; i < m; i++) {
			int x = 0;
			x += t * b[i];
			res2 = min(x, res2);
		}
		res = res1 + res2;
		for (int i = 0; i < m; i++) {
			int x = 0;
			x += (n / 6 + 1) * a[i];
			res = min(x, res);
		}
		for (int i = 0; i < m; i++) {
			int x = 0;
			x += n * b[i];
			res = min(x, res);
		}
		cout << res << '\n';
	}
	else {
		for (int i = 0; i < m; i++) {
			int x = 0;
			x += n * b[i];
			res = min(x, res);
		}
		for (int i = 0; i < m; i++) {
			res = min(a[i], res);
		}
		cout << res << '\n';
	}
	return 0;
}