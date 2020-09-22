#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll n, k, res;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;

	ll left = 1, right = k;
	while (left <= right) {
		ll mid = (left + right) / 2, cnt = 0;
		for (int i = 1; i <= n; i++) 
			cnt += min(mid / i, n);
		if (cnt < k) left = mid + 1;
		else {
			res = mid;
			right = mid - 1;
		}
	}
	cout << res << '\n';
	return 0;
}