#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[1001][3];
int dp[1001][3];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, result = 20000000;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
			dp[i][j] = 20000000;
		}
	}
	for (int i = 0; i < 3; i++) {
		dp[1][i] = arr[1][i];
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (j != k) {
					dp[i][j] = min(dp[i][j], dp[i-1][k] + arr[i][j]);
				}
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		result = min(result, dp[n][i]);
	}
	cout << result << '\n';
	return 0;
}