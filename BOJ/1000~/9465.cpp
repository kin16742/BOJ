#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

int t, n, a[2][100005], dp[2][100005];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		memset(a, 0, sizeof(a));
		memset(dp, 0, sizeof(dp));
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
			}
		}
		dp[0][0] = dp[1][0] = 0;
		dp[0][1] = a[0][1];
		dp[1][1] = a[1][1];
		for (int i = 2; i <= n; i++) {
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + a[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + a[1][i];
		}
		cout << max(dp[0][n], dp[1][n]) << '\n';
	}
	return 0;
}

