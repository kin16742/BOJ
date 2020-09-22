#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll k, n, a[10005], d, res;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
		d = max(d, a[i]);
	}
	ll left = 1, right = d;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll sum = 0;
		for (int i = 0; i < k; i++) {
			sum += a[i] / mid;
		}
		if (sum >= n) {
			left = mid + 1;
			res = max(res, mid);
		}
		else right = mid - 1;
	}
	cout << res << '\n';
	return 0;
}