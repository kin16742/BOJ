#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll n, a[10005], m, d, res;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		d = max(d, a[i]);
	}
	cin >> m;

	ll left = 0, right = d;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] > mid) sum += mid;
			else sum += a[i];
		}
		if (sum > m) right = mid - 1;
		else {
			left = mid + 1;
			res = max(res, mid);
		}
	}
	cout << res << '\n';
	return 0;
}