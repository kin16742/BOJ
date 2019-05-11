#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll n, m, a[1001], res;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < m; i++) {
		ll r = a[0] + a[1];
		a[0] = r;
		a[1] = r;
		sort(a, a + n);
	}
	for (int i = 0; i < n; i++) {
		res += a[i];
	}
	cout << res << '\n';
	return 0;
}