#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int t, n, dp[12];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 10; i++) {
		dp[i] += dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}