#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, t;
int dp[305][305];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= max(n,m); i++) {
		for (int j = 1; j <= max(n,m); j++) {
			dp[i][j] = 10000000;
		}
	}
	dp[1][1] = 0;
	for (int i = 2; i <= max(m,n); i++) {
		dp[i][1] = dp[i - 1][1] + 1;
		dp[1][i] = dp[1][i - 1] + 1;
	}
	for (int i = 2; i <= max(m,n); i++) {
		for (int j = 2; j <= max(m,n); j++) {
			for (int k = 1; k < max(i,j); k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
			}
		}
	}
	cout << dp[n][m] << endl;
}