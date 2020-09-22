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
int dp[35][35];
int main() {
	for (int i = 1; i <= 30; i++) dp[1][i] = i;
	for (int i = 2; i <= 30; i++) {
		dp[i][i] = 1;
		for (int j = i + 1; j <= 30; j++) {
			for (int k = 1; k < j; k++) {
				dp[i][j] += dp[i - 1][k];
			}
		}
	}
	cin >> t;
	while (t--) {
		cin >> n >> m;
		cout << dp[n][m] << endl;
	}
}