#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll n, c, res, a[200000];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> c;
	for (int i = 0; i < n; i++) cin >> a[i];

	sort(a, a + n);

	ll left = 1, right = a[n - 1] - a[0] + 1, cnt = 0, gap = 0;
	while (left <= right) {
		ll mid = (left + right) / 2;
		cnt = 1;
		gap = a[0];
		for (int i = 1; i < n; i++) {
			if (a[i] - gap >= mid) {
				gap = a[i];
				cnt++;
			}
		}
		if (cnt >= c) {
			left = mid + 1;
			res = max(res, mid);
		}
		else right = mid - 1;
	}
	cout << res << '\n';
	return 0;
}