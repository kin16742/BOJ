#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <stack>
using namespace std;
int n, m;
int a[1050][1050], dp[1050][1050];
int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	dp[0][0] = a[0][0];
	for (int i = 1; i < n; i++) dp[i][0] = a[i][0] + dp[i-1][0];
	for (int i = 1; i < m; i++) dp[0][i] = a[0][i] + dp[0][i-1];
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			dp[i][j] = max(dp[i][j], max(dp[i - 1][j] + a[i][j], dp[i][j - 1] + a[i][j]));
		}
	}
	cout << dp[n - 1][m - 1] << '\n';
}