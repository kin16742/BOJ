#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

long long x, y, res;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (scanf("%lld %lld", &x, &y) != EOF) {
		res = 2000000000;
		long long z = y * 100 / x;
		long long left = 1, right = 1000000000;
		while (left <= right) {
			long long mid = (left + right) / 2;
			long long per = (y + mid) * 100 / (x + mid);
			if (z < per) {
				right = mid - 1;
				res = min(res, mid);
			}
			else left = mid + 1;
		}
		if (res == 2000000000) cout << -1 << '\n';
		else cout << res << '\n';
	}
	return 0;
}