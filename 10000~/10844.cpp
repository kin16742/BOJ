#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int dp[101][10], n, res;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 1; i <= 9; i++) dp[1][i] = 1;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j != 0) {
				dp[i][j] += dp[i - 1][j - 1];
				dp[i][j] %= 1000000000;
			}
			if (j != 9) {
				dp[i][j] += dp[i - 1][j + 1];
				dp[i][j] %= 1000000000;
			}
		}
	}
	for (int i = 0; i <= 9; i++) {
		res += dp[n][i];
		res %= 1000000000;
	}
	cout << res << '\n';
	return 0;
}