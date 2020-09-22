#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll n, m, a[100000], ma, sum, res = 2000000000;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ma = max(a[i], ma);
		sum += a[i];
	}
	ll left = ma, right = sum;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll rem = 0, cnt = 0;

		for (int i = 0; i < n; i++) {
			if (rem < a[i]) {
				cnt++;
				rem = mid - a[i];
			}
			else rem -= a[i];
		}

		if (cnt <= m) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << left << '\n';
	return 0;
}