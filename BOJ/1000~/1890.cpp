#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int n, A[100][100];
long long dp[100][100];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	dp[0][0] = 1;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] == 0 || (i == n - 1 && j == n - 1)) continue;

			int nextI = A[i][j] + i;
			int nextJ = A[i][j] + j;

			if (nextI < n) {
				dp[nextI][j] += dp[i][j];
			}
			if (nextJ < n) {
				dp[i][nextJ] += dp[i][j];
			}
		}
	}

	cout << dp[n - 1][n - 1] << '\n';

	return 0;
}

