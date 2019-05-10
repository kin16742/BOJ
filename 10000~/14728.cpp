#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int n, t, k, s, dp[10005];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		cin >> k >> s;
		for (int j = t; j >= k; j--) {
			dp[j] = max(dp[j], dp[j - k] + s);
		}
	}
	cout << dp[t] << '\n';
	return 0;
}