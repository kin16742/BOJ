#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll n, m, c, a[1000000], res, maxT;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		maxT = max(maxT, a[i]);
	}
	ll left = 1, right = maxT;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			if(a[i] > mid) sum += a[i] - mid;
		}
		if (sum >= m) {
			left = mid + 1;
			res = max(mid, res);
		}
		else right = mid - 1;
	}
	cout << res << '\n';
	return 0;
}