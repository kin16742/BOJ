#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int n, res;
int dp[505][505], arr[505][505];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j];
		}
	}
	dp[1][1] = arr[1][1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			dp[i][j] = max(dp[i][j], arr[i][j] + dp[i - 1][j]);
			dp[i][j+1] = max(dp[i][j+1], arr[i][j+1] + dp[i - 1][j]);
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) res = max(res, dp[n][i]);
	cout << res << endl;
}